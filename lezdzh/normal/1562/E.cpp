#include<cstdio>
#include<algorithm>
using namespace std;

char s[5002];
int a[5002][5002];
int f[5001];
bool cmp(int p,int q){
	if(p==q)return 0;
	for(int i=0;;i++)
		if(s[p+i]!=s[q+i])
			return s[p+i]<s[q+i];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,ans=0;
		scanf("%d%s",&n,s+1);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				a[i][j]=0;
		for(int i=n;i;i--)
			for(int j=n;j;j--)
				a[i][j]=s[i]==s[j]?a[i+1][j+1]+1:0;
		for(int i=n;i;i--){
			f[i]=0;
			for(int j=i+1;j<=n;j++)
				if(s[i+a[i][j]]<s[j+a[i][j]])
					f[i]=max(f[i],f[j]-a[i][j]);
			f[i]+=n-i+1;
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
}