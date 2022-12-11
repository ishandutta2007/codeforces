#include<cstdio>
#include<algorithm>
using namespace std;

char s[1001][1002];
int a[1001][1001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int mn=m+1,mx=0;
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#'){
				mn=min(mn,j);
				mx=max(mx,j);
			}
		if(mx==0)continue;
		for(int j=mn;j<=mx;j++)
			if(s[i][j]!='#')goto ed;
		for(int j=1;j<mn;j++)a[i][j]=1;
		for(int j=mx+1;j<=m;j++)a[i][j]=1;
	}
	for(int j=1;j<=m;j++){
		int mn=n+1,mx=0;
		for(int i=1;i<=n;i++)
			if(s[i][j]=='#'){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		if(mx==0)continue;
		for(int i=mn;i<=mx;i++)
			if(s[i][j]!='#')goto ed;
		for(int i=1;i<mn;i++)a[i][j]=1;
		for(int i=mx+1;i<=n;i++)a[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		bool ok=0;
		for(int j=1;j<=m;j++)
			if(!a[i][j])ok=1;
		if(!ok)goto ed;
	}
	for(int j=1;j<=m;j++){
		bool ok=0;
		for(int i=1;i<=n;i++)
			if(!a[i][j])ok=1;
		if(!ok)goto ed;
	}
	for(int i=1;i<=n;i++){
		int mn=m+1,mx=0;
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#'){
				mn=min(mn,j);
				mx=max(mx,j);
			}
		if(mx==0)continue;
		int ok=0;
		for(int j=mn;j<=mx;j++)
			if(i!=1&&s[i-1][j]=='#')ok=1;
		if(!ok)ans++;
	}
	printf("%d\n",ans);
	return 0;
ed:;
	printf("-1\n");
}