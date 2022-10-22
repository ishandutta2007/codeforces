#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m;
ll c[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			c[i]=0;
			for(int j=1; j<=m; j++){
				int a; scanf("%d",&a);
				c[i]+=1ll*a*j;
			}
		}
		int k;
		if(c[1]==c[2]){
			for(int i=3; i<=n; i++)
				if(c[i]!=c[1]){
					k=i;
					break;
				}
		}else{
			if(c[1]==c[3]) k=2;
			else k=1;
		}
		printf("%d %lld\n",k,k==1?c[1]-c[2]:c[k]-c[1]);
	}
	return 0;
}