#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		int w=-1e9,ans=0;
		for(int i=1;i<=n;i++){
			int o;
			scanf("%d",&o);
			w=max(o,w);
			ans=max(ans,w-o);
		}
		if(ans==0)printf("0\n");
		else
			for(int i=31;i>=0;i--)
				if(ans>>i&1){
					printf("%d\n",i+1);
					break;
				}
	}
}