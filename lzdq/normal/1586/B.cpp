#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m;
bool vis[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			vis[i]=0;
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vis[b]=1;
		}
		int x=0;
		for(int i=1; i<=n; i++)
			if(!vis[i]){
				x=i;
				break;
			}
		for(int i=1; i<=n; i++)
			if(i!=x) printf("%d %d\n",x,i);
	}
	return 0;
}