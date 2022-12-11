#include<cstdio>

using namespace std;

int a[200001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			a[i]=0;
		for(int i=0;i<n;i++){
			int o;
			scanf("%d",&o);
			o=((1ll*i+o)%n+n)%n;
			a[o]++;
		}
		for(int i=0;i<n;i++)
			if(a[i]!=1)goto ed;
		printf("YES\n");
		continue;
ed:;
		printf("NO\n");
	}
}