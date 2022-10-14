#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,x,a[N],cnt[N];
struct matrix{
	static int const N=105,MOD=1000000007;
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
matrix ans,f;
signed main(){
	ios::sync_with_stdio(0);
	ans[0][0]=ans[0][100]=f[100][0]=f[100][100]=1;
	for(int i=0;i<99;i++)
		f[i][i+1]=1;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[a[i]-1][0]++;
	cout<<(ans*f.qpow(x))[0][0]<<"\n";
}