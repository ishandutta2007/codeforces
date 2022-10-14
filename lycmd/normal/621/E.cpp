#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000007;
int n,b,k,x,a[N],cnt[N];
struct matrix{
	static int const N=105;
	int v[N][N];
	matrix(){memset(v,0,sizeof v);}
	int*operator[](int x){
		return v[x];
	}
	const int*operator[](int x)const{
		return v[x];
	}
	matrix operator*(const matrix&rhs)const{
		matrix res;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
					res[i][j]=(res[i][j]+v[i][k]*rhs[k][j]%MOD)%MOD;
		return res;
	}
	matrix qpow(int y){
		matrix ans,t=*this;
		for(int i=0;i<N;i++)
			ans[i][i]=1;
		for(;y;y>>=1,t=t*t)
			if(y&1)ans=ans*t;
		return ans;
	}
};
matrix s,f;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>b>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=0;i<x;i++)
		for(int j=1;j<10;j++)
			f[(i*10+j)%x][i]+=cnt[j];
	s[0][0]=1;
	s=f.qpow(b)*s;
	cout<<s[k][0]<<"\n";
}