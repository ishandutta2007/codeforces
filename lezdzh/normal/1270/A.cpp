#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,k1,k2;
		scanf("%d%d%d",&n,&k1,&k2);
		int w1=-1,w2=-1,o;
		for(int i=1;i<=k1;i++){
			scanf("%d",&o);
			w1=max(o,w1);
		}
		for(int i=1;i<=k2;i++){
			scanf("%d",&o);
			w2=max(w2,o);
		}
		printf(w1>w2?"YES\n":"NO\n");
	}
}