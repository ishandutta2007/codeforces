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



// (t,l,r)  r-l>=2*t
template<class T>
struct EnumerateRuns{
	vector<int>zalgo(const T &s){
		vector<int>z(s.size());
		z[0]=s.size();
		int i=1,j=0;
		while(i<s.size()){
			while(i+j<s.size()&&s[j]==s[i+j])j++;
			z[i]=j;
			if(j==0){i++;continue;}
			int k=1;
			while(i+k<s.size()&&k+z[k]<j)z[i+k]=z[k],k++;
			i+=k;j-=k;
		}
		return z;
	}
	
	T S;
	EnumerateRuns(const T &s):S(s){}

	T substr(int l,int r){return {S.begin()+l,S.begin()+r};}
	T rev(T s){reverse(s.begin(),s.end());return s;}
	T concat(T a,T b){a.insert(a.end(),b.begin(),b.end());return a;}

	map<pair<int,int>,int>mp;
	void solve(int l,int r,int f){
		if(r-l==1)return;
		int m=(l+r+f)/2;
		solve(l,m,f);solve(m,r,f);
		
		auto zl=zalgo(rev(substr(l,m)));
		auto zr=zalgo(concat(substr(m,r),substr(l,r)));
		for(int p=1;p<=m-l;p++){
			int lenl=(p<m-l?zl[p]:0);
			int lenr=zr[r-l-p];
			int ll=m-p-lenl;
			int rr=min(m+lenr,r);
			if(rr-ll<2*p)continue;
			if(ll&&S[ll-1+p]==S[ll-1])continue;
			if(rr<S.size()&&S[rr]==S[rr-p])continue;
			if(f)tie(ll,rr)=pint(S.size()-rr,S.size()-ll);
			pair<int,int>I(ll,rr);
			if(!mp.count(I)||mp[I]>p)mp[I]=p;
		}
	}

	vector<tuple<int,int,int>>calc(){
		for(int i=0;i<2;i++){
			solve(0,S.size(),i);
			reverse(S.begin(),S.end());
		}

		vector<tuple<int,int,int>>runs;
		for(auto &p:mp){
			int t=p.second;
			int l,r;tie(l,r)=p.first;
			runs.emplace_back(t,l,r);
		}
		return runs;
	}
};

const int INF=1001001001001001001ll;

int N;
string S;

int dp[8888];


int lim[8888];
vector<pint>es[8888];

int dp2[8888];

int len[8888];
signed main(){
	for(int i=1;i<=8000;i++){
		stringstream ss;
		ss<<i;
		len[i]=ss.str().size();
	}
	cin>>S;
	N=S.size();
	EnumerateRuns<string> er(S);

	fill_n(dp,N+1,INF);
	dp[0]=0;

	memset(lim,-1,sizeof(lim));

	auto lis=er.calc();
	for(auto tup:lis){
		int t,l,r;
		tie(t,l,r)=tup;
		es[l].eb(t,r);
	}
	
	for(int i=0;i<N;i++){
		for(auto e:es[i]){
			int t,r;
			tie(t,r)=e;
			lim[t]=r;
		}

		for(int j=1;j<=N-i;j++){
			dp2[j]=j;
		}

		for(int j=1;j<=N-i;j++){
			if(dp2[j]==j||lim[dp2[j]]>=i+j)chmin(dp[i+j],dp[i]+len[j/dp2[j]]+dp2[j]);
			if(lim[dp2[j]]<i+j+dp2[j])continue;
			chmin(dp2[j+dp2[j]],dp2[j]);

		}
	}

	cout<<dp[N]<<endl;
    return 0;
}