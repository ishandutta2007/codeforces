#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=998244353;
int N;
struct matrix{
	ll m[205][205];
	void clr(){
		memset(m,0,sizeof(m));
	}
	matrix(){
		memset(m,0,sizeof(m));
	}
	matrix friend operator * (const matrix &a,const matrix &b){
		matrix c;
		for (int i=1;i<=N;i++)
			for (int k=1;k<=N;k++)
				for (int j=1;j<=N;j++) (c.m[i][j]+=a.m[i][k]*b.m[k][j])%=mod;
		return c;
	}
};
matrix ksm(matrix A,ll x){
	matrix ret;
	for (int i=1;i<=N;i++) ret.m[i][i]=1;
	for (;x;x>>=1,A=A*A) if (x&1) ret=ret*A;
	return ret;
}

matrix A,B;
ll n,m,K;
vector<ll> g[250];
ll deg[250];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> K;
	N=2*n;
	for (int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for (int u=1;u<=n;u++){
		for (auto v:g[u]) A.m[u][v]=1;
		A.m[u][n+u]=mod-(deg[u]-1);
		A.m[n+u][u]=1;
	}
	/*
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			cerr << A.m[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	A=ksm(A,K-1);
	long long ans=0;
	for (int u=1;u<=n;u++){
		B.clr();
		for (auto v:g[u]){
			B.m[n+v][1]++;
			for (auto w:g[v]) B.m[w][1]++;
		}
		B.m[u][1]=0;
		B=A*B;
		ans=(ans+B.m[n+u][1])%mod;
	}
	cout << ans << "\n";
	return 0;
}