#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
int n,p[MAXN];
int Query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			p[i]=0;
		for(int i=1; i<=n; i++){
			if(p[i]) continue;
			int u=Query(i);
			int st=u;
			do{
				u=p[u]=Query(i);
			}while(u!=st);
		}
		putchar('!');
		for(int i=1; i<=n; i++)
			printf(" %d",p[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}