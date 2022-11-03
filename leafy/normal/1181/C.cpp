#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int n,m;
char s[N][N];
int a[N][N];ll f[N][N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
			if(i==1||s[i][j]!=s[i-1][j])
				a[i][j]=1;
			else a[i][j]=a[i-1][j]+1;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) {
		int la=0;
		for(int j=1;j<=m;j++){
			int t=a[i][j];
			if(a[i-t][j]!=t||a[i-2*t][j]<t) {la=0;continue;}
			f[i][j]=1;
			if(la==t&&s[i][j-1]==s[i][j]&&s[i-t][j-1]==s[i-t][j]&&s[i-2*t][j-1]==s[i-2*t][j])
				f[i][j]+=f[i][j-1];
			la=t;ans+=f[i][j];
		}
	}
	printf("%I64d",ans);
	return 0;
}