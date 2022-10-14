#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,B=18;
int n,ans,a[N],lg[N],f[N],s[B][N];
void init(){
	for(int i=2;i<N;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		s[0][i]=i;
	for(int i=1;i<B;i++)
		for(int j=1;j+(1<<(i-1))<n;j++)
			s[i][j]=i?a[s[i-1][j]]>a[s[i-1][j+(1<<(i-1))]]?
				s[i-1][j]:s[i-1][j+(1<<(i-1))]:j;
}
int query(int l,int r){
	int k=lg[r-l+1];
	return a[s[k][l]]>a[s[k][r-(1<<k)+1]]?s[k][l]:s[k][r-(1<<k)+1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>a[i];
	init();
	for(int i=n-1;i>=1;i--)
		if(a[i]<n){
			int k=query(i+1,a[i]);
			f[i]=n-a[i]+k-i+f[k];
		}else f[i]=n-i;
	for(int i=1;i<=n;i++)
		ans+=f[i];
	cout<<ans<<"\n";
}