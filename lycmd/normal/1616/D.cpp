#include<bits/stdc++.h>
using namespace std;
int const N=50010;
int t,n,k,a[N],s[N],f[N][4],g[N];
int check(int l,int r){
	for(int i=l;i<r;i++)
		for(int j=i+1;j<=r;j++)
			if(s[j]-s[i-1]<k*(j-i+1))
				return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i]=s[i-1]+a[i],
			f[i][0]=f[i][1]=f[i][2]=f[i][3]=g[i]=0;
		cin>>k;
		for(int i=1;i<=n;i++){
			int flg=1;
			for(int j=0;j<=min(i,3);j++){
				if(check(i-j+1,i))
					f[i][j]=max(f[i][j],g[i-j-1]+j);
				else{
					flg=0;break;
				}
				g[i]=max(g[i],f[i][j]);
			}
			if(flg)g[i]=max(g[i],f[i][3]=max(f[i][3],f[i-1][3]+1));
		}
		cout<<g[n]<<"\n";
	}
	return 0;
}