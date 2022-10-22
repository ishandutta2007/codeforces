#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,T,ans;
int a[3][maxn],pos[3][maxn],neg[3][maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		a[1][1]--;
		pos[1][n+1]=pos[2][n+1]=neg[1][n+1]=neg[2][n+1]=-1050000000;
		for(int t=1;t<=2;t++)
			for(int i=n;i>=1;i--){
				pos[t][i]=max(pos[t][i+1],a[t][i]+i);
				neg[t][i]=max(neg[t][i+1],a[t][i]-i);
			}
		int mx=-2000000000,c=0;
		ans=2000000000;
		for(int i=1;i<=n;i+=2){
			c++,mx=max(mx,a[1][i]-c),c++,mx=max(mx,a[2][i]-c);
			ans=min(ans,max(mx,max(neg[2][i+1]-c+i,pos[1][i+1]-(n+n+i+1))));
			if(i<n)
				c++,mx=max(mx,a[2][i+1]-c),c++,mx=max(mx,a[1][i+1]-c);
		}
		mx=-2000000000,c=0;
		for(int i=0;i<=n;i+=2){
			if(i>0)
				c++,mx=max(mx,a[2][i]-c),c++,mx=max(mx,a[1][i]-c);
			ans=min(ans,max(mx,max(neg[1][i+1]-c+i,pos[2][i+1]-(n+n+i+1))));
			if(i<n)
				c++,mx=max(mx,a[1][i+1]-c),c++,mx=max(mx,a[2][i+1]-c);
		}
		printf("%d\n",ans+n+n+1);
	}
	return 0;
}