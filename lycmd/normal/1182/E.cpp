#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=105,MOD=1000000007,MOD1=MOD-1;
int n,f1,f2,f3,c,a[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
struct matrix{
	static int const N=3;
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
					res[i][j]=(res[i][j]+
						v[i][k]*rhs[k][j]%MOD1)%MOD1;
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
}f;
signed main(){
	cin>>n>>f1>>f2>>f3>>c,f1=f1*c%MOD,f2=f2*c%MOD*c%MOD,
	f3=f3*c%MOD*c%MOD*c%MOD;
	matrix ans;
	ans[0][0]=ans[0][1]=ans[1][0]=ans[1][2]=ans[2][0]=1;
	ans=ans.qpow(n-3);
	cout<<qpow(f1,ans[2][0])*qpow(f2,ans[1][0])%MOD
		*qpow(f3,ans[0][0])%MOD*qpow(qpow(c,n),MOD-2)%MOD<<"\n";
}