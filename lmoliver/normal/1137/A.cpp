#include<bits/stdc++.h>
using namespace std;

#define F(p) for(int p=0;p<n;p++)

const int N=1010;
int a[N][N],b[N][N],c[N][N],d[N][N];
map<int,int> mp;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			c[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[j][i]=a[i][j];
			d[j][i]=b[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		sort(c[i]+1,c[i]+m+1);
		int k=unique(c[i]+1,c[i]+m+1)-(c[i]+1);
		mp.clear();
		for(int j=1;j<=k;j++){
			mp[c[i][j]]=j;
		}
		for(int j=1;j<=m;j++){
			a[i][j]=mp[a[i][j]];
			c[i][j]=k;
		}
	}
	for(int i=1;i<=m;i++){
		sort(d[i]+1,d[i]+n+1);
		int k=unique(d[i]+1,d[i]+n+1)-(d[i]+1);
		mp.clear();
		for(int j=1;j<=k;j++){
			mp[d[i][j]]=j;
		}
		for(int j=1;j<=n;j++){
			b[i][j]=mp[b[i][j]];
			d[i][j]=k;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int l=max(a[i][j]-1,b[j][i]-1);
			int r=max(d[j][i]-b[j][i],c[i][j]-a[i][j]);
			printf("%d ",l+1+r);
		}
		printf("\n");
	}
    return 0;
}