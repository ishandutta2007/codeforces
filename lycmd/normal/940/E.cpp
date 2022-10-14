#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,B=18;
int n,k,a[N],s[N],f[N],lg[N],mn[B][N];
void init(){
	for(int i=1;i<=n;i++)
		mn[0][i]=a[i],lg[i]=i>1?lg[i>>1]+1:0;
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<(i-1));j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
}
int ask(int l,int r){
	int k=lg[r-l+1];
	return min(mn[k][l],mn[k][r-(1<<k)+1]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	init();
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		if(i>=k)f[i]=min(f[i],f[i-k]+s[i]-s[i-k]-ask(i-k+1,i));
	}
	cout<<f[n]<<"\n";
}