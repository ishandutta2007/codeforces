#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<typename I,bool isMin>
struct ConvexHullTrick{
#define a first
#define b second

	using Line=pair<I,I>;
	deque<Line>lines;

	//l.a>=m.a>=r.a
	inline bool notNecessary(const Line &l,const Line &m,const Line &r){
		return (long double)(m.a-l.a)*(r.b-m.b)>=(long double)(m.b-l.b)*(r.a-m.a);
	}
	void addLine(I a,I b){
		if(!isMin)a*=-1,b*=-1;
		Line l(a,b);
		if(lines.empty())lines.push_back(l);
		else if(lines.front().a<=a){
			if(lines.front().a==a){
				if(lines.front().b<=b)return;
				lines.pop_front();
			}
			while(lines.size()>=2&&notNecessary(l,lines[0],lines[1]))lines.pop_front();
			lines.push_front(l);
		}
		else{
			if(lines.back().a==a){
				if(lines.back().b<=b)return;
				lines.pop_back();
			}
			while(lines.size()>=2&&notNecessary(lines[lines.size()-2],lines[lines.size()-1],l))lines.pop_back();
			lines.push_back(l);
		}
	}

	inline I eval(const Line &l,I x){
		return l.a*x+l.b;
	}

	I query(I x){
		int lb=-1,ub=lines.size()-1;
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			if(eval(lines[mid],x)<=eval(lines[mid+1],x))ub=mid;
			else lb=mid;
		}
		if(isMin)return eval(lines[ub],x);
		return -eval(lines[ub],x);
	}

	I queryMonotoneInc(I x){
		while(lines.size()>=2&&eval(lines[0],x)>=eval(lines[1],x))lines.pop_front();
		if(isMin)return eval(lines[0],x);
		return -eval(lines[0],x);
	}
	I queryMonotoneDec(I x){
		while(lines.size()>=2&&eval(lines[lines.size()-1],x)>=eval(lines[lines.size()-2],x))lines.pop_back();
		if(isMin)return eval(lines.back(),x);
		return -eval(lines.back(),x);
	}
#undef a
#undef b
};

int N;
int X[1111111],Y[1111111],A[1111111];
int dp[1111111];

signed main(){
	scanf("%lld",&N);
	vector<tuple<int,int,int>>vec;
	rep(i,N){
		int x,y,a;
		scanf("%lld%lld%lld",&x,&y,&a);
		vec.pb(make_tuple(x,y,a));
	}

	sort(all(vec));
	rep(i,N){
		tie(X[i],Y[i],A[i])=vec[i];
	}

	ConvexHullTrick<int64_t,false>cht;
	cht.addLine(0,0);
	for(int i=0;i<N;i++){
		int v=cht.queryMonotoneDec(Y[i]);
		dp[i+1]=v+X[i]*Y[i]-A[i];
		cht.addLine(-X[i],dp[i+1]);
	}

	cout<<*max_element(dp,dp+N+1)<<endl;
	return 0;
}