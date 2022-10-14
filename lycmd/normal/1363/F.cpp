#include<bits/stdc++.h>
using namespace std;
int const N=2010,T=28,INF=0x3f3f3f3f;
int t,n,f[N][N],sa[N][T],sb[N][T];
string a,b;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>a>>b,a=" "+a,b=" "+b;
		for(int i=1;i<=n;i++){
			memcpy(sa[i],sa[i-1],sizeof sa[i]);
			memcpy(sb[i],sb[i-1],sizeof sb[i]);
			sa[i][a[i]-97]++,sb[i][b[i]-97]++;
		}
		int flg=1;
		for(int i=0;i<T;i++)
			flg&=sa[n][i]==sb[n][i];
		if(!flg){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				f[i][j]=f[i-1][j]+1;
				if(a[i]==b[j])
					f[i][j]=min(f[i][j],f[i-1][j-1]);
				else if(sa[i][b[j]-97]<sb[j][b[j]-97])
					f[i][j]=min(f[i][j],i<j?f[i][j-1]:INF);
			}
		cout<<f[n][n]<<"\n";
	}
}