#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n,m;
char s[MAXN];
int rw[MAXN];
bool vis[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(int i=0; i<m; i++)
			vis[i]=0;
		int cnt=0,lst=-MAXN;
		for(int i=1; i<=n*m; i++){
			if(s[i]=='1'){
				if(!vis[i%m])
					vis[i%m]=1,cnt++;
				lst=i;
			}
			rw[i]=rw[max(i-m,0)];
			if(i-lst<m) rw[i]++;
			printf("%d ",rw[i]+cnt);
		}
		puts("");
	}
	return 0;
}