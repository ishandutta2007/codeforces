#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y;
char s[1005];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d%d",&n,&m,&x,&y);
		y=min(y,x*2);
		ans=0;
		for(int i=1; i<=n; i++){
			scanf("%s",s+1);
			int sum=0;
			for(int j=1; j<=m; j++)
				if(s[j]=='.') sum++;
				else ans+=y*(sum>>1)+x*(sum&1),sum=0;
			ans+=y*(sum>>1)+x*(sum&1);
		}
		printf("%d\n",ans);
	}
	return 0;
}