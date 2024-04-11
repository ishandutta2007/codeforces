#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=105;
int n,a[MAXN],f[MAXN][MAXN],cnt[MAXN],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		for(int i=1; i<=n; i++){
			memset(cnt,0,sizeof(cnt));
			int x=0;
			for(int j=i; j<=n; j++){
				if(a[j]<=n) cnt[a[j]]=1;
				while(cnt[x]) x++;
				f[i][j]=x+1;
			}
		}
		for(int i=n; i; i--)
			for(int j=i; j<=n; j++){
				for(int k=i; k<j; k++)
					f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
				ans+=f[i][j];
			}
		printf("%d\n",ans);
	}
	return 0;
}