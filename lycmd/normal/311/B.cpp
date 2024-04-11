#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,M=105;
int n,m,p,a[N],b[N],s[N],f[M][N],q[M][N],l[N],r[N];
double slope(int x,int l,int r){
	return 1.0*(s[l]+f[x][l]-s[r]-f[x][r])/(l-r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>p;
	if(p>=m)cout<<"0\n",exit(0);
	for(int i=2;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=m;i++){
		int h,t;cin>>h>>t;
		b[i]=t-a[h];
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+b[i];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=min(j,p);i++){
			int t=i-1;
			while(l[t]<r[t]&&slope(t,q[t][l[t]],q[t][l[t]+1])<=b[j])l[t]++;
			int k=q[t][l[t]];
			f[i][j]=f[i-1][k]+b[j]*(j-k)-s[j]+s[k];
			while(l[i]<r[i]&&slope(i,q[i][r[i]-1],q[i][r[i]])>slope(i,q[i][r[i]],j))r[i]--;
			q[i][++r[i]]=j;
		}
	cout<<f[p][m]<<"\n";
}