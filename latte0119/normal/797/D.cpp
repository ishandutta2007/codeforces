#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

int N;
int A[111111];
int ch[111111][2];

set<int>s;
void dfs(int v,int l,int r){
	if(l<=A[v]&&A[v]<=r)s.insert(A[v]);
	if(ch[v][0]!=-1)dfs(ch[v][0],l,min(r,A[v]-1));
	if(ch[v][1]!=-1)dfs(ch[v][1],max(l,A[v]+1),r);
}
signed main(){
	scanf("%lld",&N);
	vint isroot(N,1);
	rep(i,N){
		scanf("%lld%lld%lld",&A[i],&ch[i][0],&ch[i][1]);
		rep(j,2)if(ch[i][j]!=-1){
			ch[i][j]--;
			isroot[ch[i][j]]=0;
		}	
	}

	rep(i,N)if(isroot[i]){
		dfs(i,0,1000000000);
		int ans=0;
		rep(j,N)if(s.find(A[j])==s.end())ans++;
		cout<<ans<<endl;

	}
	return 0;
}