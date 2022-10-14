#include<bits/stdc++.h>
using namespace std;
int const N=1000010,MOD=1000000007;
int n,l,m,ans,a[N],b[N],c[N],cnt[N];
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
}
struct matrix{
	static int const N=105;
	int v[N][N];
	matrix(){
		memset(v,0,sizeof v);
	}
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
					add(res[i][j],1ll*v[i][k]*rhs[k][j]%MOD);
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
matrix f,r,ft;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>l>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],r[a[i]%m][0]++;
	for(int i=1;i<=n;i++)
		cin>>b[i],cnt[b[i]%m]++;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			f[i][j]=cnt[(i-j+m)%m];
	r=f.qpow(l-2)*r;
	for(int i=1;i<=n;i++)
		add(ans,r[(m+m-b[i]-c[i])%m][0]);
	cout<<ans<<"\n";
}