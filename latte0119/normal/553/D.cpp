#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
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

/*
r in Q:
r=a/b & (a,b)=(1) & b>=0
*/
struct Fraction{
    int64_t gcd(int64_t a,int64_t b){
        return b?gcd(b,a%b):a;
    }
	int64_t a,b;
	Fraction():a(0),b(1){}
	Fraction(int64_t a):a(a),b(1){}
	Fraction(int64_t a,int64_t b):a(a),b(b){
		if(b<0)a*=-1,b*=-1;
        int64_t g=gcd((a>0?a:-a),b);
        a/=g;
        b/=g;
    }
	bool operator==(const Fraction& f)const{return a==f.a&&b==f.b;}
	bool operator!=(const Fraction& f)const{return a!=f.a||b!=f.b;}
	Fraction& operator+=(const Fraction& f){
		int64_t c=a*f.b+b*f.a;
		int64_t d=b*f.b;
		int64_t g=gcd((c>0?c:-c),d);
		a=c/g;
		b=d/g;
		return *this;
	}
	Fraction& operator-=(const Fraction& f){
		int64_t c=a*f.b-b*f.a;
		int64_t d=b*f.b;
		int64_t g=gcd((c>0?c:-c),d);
		a=c/g;
		b=d/g;
		return *this;
	}
	Fraction& operator*=(const Fraction& f){
		int64_t c=a*f.a;
		int64_t d=b*f.b;
		int64_t g=gcd((c>0?c:-c),d);
		a=c/g;
		b=d/g;
		return *this;
	}
	Fraction& operator/=(const Fraction& f){
		int64_t c=a*f.b;
		int64_t d=b*f.a;
		if(d<0)c*=-1,d*=-1;
		int64_t g=gcd((c>0?c:-c),d);
		a=c/g;
		b=d/g;
		return *this;
	}
	Fraction operator+(const Fraction& f)const{return Fraction(*this)+=f;}
	Fraction operator-(const Fraction& f)const{return Fraction(*this)-=f;}
	Fraction operator*(const Fraction& f)const{return Fraction(*this)*=f;}
	Fraction operator/(const Fraction& f)const{return Fraction(*this)/=f;}
	bool operator<(const Fraction& f)const{return (Fraction(*this)-f).a<0;}
	bool operator>(const Fraction& f)const{return (Fraction(*this)-f).a>0;}
	bool operator<=(const Fraction& f)const{return (Fraction(*this)-f).a<=0;}
	bool operator>=(const Fraction& f)const{return (Fraction(*this)-f).a>=0;}
	Fraction operator+()const{return Fraction(*this);}
	Fraction operator-()const{return Fraction()-Fraction(*this);}
};

int N,M,K;
bool ban[111111];
vint G[111111];
int cnt[111111];

using st=pair<Fraction,int>;
signed main(){
	scanf("%lld%lld%lld",&N,&M,&K);
	rep(i,K){
		int a;scanf("%lld",&a);
		a--;
		ban[a]=true;
	}
	rep(i,M){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	priority_queue<st,vector<st>,greater<st>>que;
	rep(i,N){
		if(ban[i])continue;
		for(auto u:G[i]){
			if(!ban[u])cnt[i]++;
		}
		que.emplace(Fraction(cnt[i],G[i].size()),i);
	}

	vint ord;
	vector<Fraction>score;
	while(que.size()){
		Fraction val;
		int v;
		tie(val,v)=que.top();
		que.pop();
		if(ban[v])continue;
		ban[v]=true;
		ord.pb(v);
		score.pb(val);
		for(auto u:G[v]){
			if(ban[u])continue;
			cnt[u]--;
			que.emplace(Fraction(cnt[u],G[u].size()),u);
		}
	}


	vint ans;
	int ma=max_element(all(score))-score.begin();
	for(int i=ma;i<N-K;i++)ans.pb(ord[i]);
	printf("%lld\n",(int)ans.size());
	for(int i=0;i<ans.size();i++){
		if(i)printf(" ");
		printf("%lld",ans[i]+1);
	}
	puts("");
	return 0;
}