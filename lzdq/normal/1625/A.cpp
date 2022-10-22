#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,l;
int cnt[30][2];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&l);
		memset(cnt,0,sizeof(cnt));
		while(n--){
			int x; scanf("%d",&x);
			for(int i=0; i<l; i++)
				cnt[i][x>>i&1]++;
		}
		int ans=0;
		for(int i=0; i<l; i++)
			if(cnt[i][1]>cnt[i][0]) ans|=1<<i;
		printf("%d\n",ans);
	}
	return 0;
}