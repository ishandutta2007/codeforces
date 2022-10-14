#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=105,MOD=1000000007;
int n,m;
struct matrix{
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
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=m;k++)
					res[i][j]=(res[i][j]+v[i][k]*rhs[k][j]%MOD)%MOD;
		return res;
	}
	matrix qpow(matrix ans,int y){
		matrix t=*this;
		for(;y;y>>=1,t=t*t)
			if(y&1)ans=ans*t;
		return ans;
	}
}f,b;
signed main(){
	cin>>n>>m;
	if(n<m)
	    cout<<"1\n",exit(0);
	for(int i=1;i<=m;i++)
		b[1][i]=1+(i==m);
	f[1][m]=f[m][m]=1;
	for(int i=2;i<=m;i++)
		f[i][i-1]=1;
	f=f.qpow(b,n-m);
	cout<<f[1][m]<<"\n";
}