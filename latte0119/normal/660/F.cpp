#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
	return __builtin_parity(x);
}

template<typename I,bool isMin>
struct ConvexHullTrick{
#define a first
#define b second
 
	using Line=pair<I,I>;
	deque<Line>lines;
 
	//l.a>=m.a>=r.a
	inline bool needless(const Line &l,const Line &m,const Line &r){
		return (__int128)(m.a-l.a)*(r.b-m.b)>=(__int128)(m.b-l.b)*(r.a-m.a);
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
			while(lines.size()>=2&&needless(l,lines[0],lines[1]))lines.pop_front();
			lines.push_front(l);
		}
		else{
			if(lines.back().a==a){
				if(lines.back().b<=b)return;
				lines.pop_back();
			}
			while(lines.size()>=2&&needless(lines[lines.size()-2],lines[lines.size()-1],l))lines.pop_back();
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
int A[222222];

int S[222222],B[222222];

signed main(){
	cin>>N;
	rep(i,N)cin>>A[i];

	rep(i,N){
		S[i+1]=S[i]+(i+1)*A[i];
		B[i+1]=B[i]+A[i];
	}

	ConvexHullTrick<int,false>cht;
	
	int ans=0;
	for(int i=0;i<N;i++){
		cht.addLine(-i,i*B[i]-S[i]);

		chmax(ans,cht.query(B[i+1])+S[i+1]);
	}

	cout<<ans<<endl;
	return 0;
}