#include<cstdio>

using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int z;
			scanf("%d",&z);
			ans+=z!=2;
		}
		printf("%d\n",ans);
	}
}