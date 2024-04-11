#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=105,MOD=1000000007;
int n,k,cnt,a[N];
struct matrix{
	int v[N][N];
	matrix(){memset(v,0,sizeof v);}
	matrix operator*(const matrix&rhs)const{
		matrix res;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
					res.v[i][j]=(res.v[i][j]+
						v[i][k]*rhs.v[k][j]%MOD)%MOD;
		return res;
	}
}f;
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int calca(int x){
	return (cnt-x)*(cnt-x);
}
int calcb(int x){
	return x*(n-2*cnt+x);
}
int calcc(int x){
	return n*(n-1)/2-calca(x)-calcb(x);
}
matrix qpow(matrix x,int y){
	matrix ans;
	for(int i=0;i<N;i++)
		ans.v[i][i]=1;
	for(;y;y>>=1,x=x*x)
		if(y&1)ans=ans*x;
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt+=!a[i];
	for(int i=0;i<=cnt;i++){
		if(i)
		    f.v[i][i-1]=calca(i-1);
		f.v[i][i]=calcc(i);
		if(i<cnt)f.v[i][i+1]=calcb(i+1);
	}
	matrix ans=qpow(f,k);
	int s=0,c=0;
	for(int i=1;i<=cnt;i++)
		c+=!a[i];
	for(int i=0;i<=cnt;i++)
		s=(s+ans.v[i][c])%MOD;
	cout<<ans.v[cnt][c]*qpow(s,MOD-2)%MOD<<"\n";
}