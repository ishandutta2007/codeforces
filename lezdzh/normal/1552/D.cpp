#include<cstdio>
#include<algorithm>
using namespace std;

int a[11],b[100001],c[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1){printf(a[1]==0?"YES\n":"NO\n");continue;}
		int k=n/2;
		b[0]=0;
		for(int i=0;i<1<<k;i++)
			for(int j=0;j<1<<k;j++)
				if((i&j)==j){
					int z=0;
					for(int o=0;o<k;o++)
						if(i>>o&1)
							z+=(j>>o&1?a[o+1]:-a[o+1]);
					if(z>=0)b[++b[0]]=z;
				}
		c[0]=0;
		for(int i=0;i<1<<n-k;i++)
			for(int j=0;j<1<<n-k;j++)
				if((i&j)==j){
					int z=0;
					for(int o=0;o<n-k;o++)
						if(i>>o&1)
							z+=(j>>o&1?a[o+k+1]:-a[o+k+1]);
					if(z>=0)c[++c[0]]=z;
				}
		sort(b+1,b+b[0]+1);
		sort(c+1,c+c[0]+1);
	//	for(int i=1;i<=b[0];i++)
	//		printf("!!%d",b[i]);
	//	printf("!!\n");
	//	for(int i=1;i<=c[0];i++)
	//		printf("!!%d",c[i]);
		int ok=0;
		if(b[2]==0||c[2]==0)ok=1;
		for(int i=2;i<=c[0];i++){
			if((*lower_bound(b+1,b+b[0]+1,c[i]))==c[i])
				ok=1;
//			printf("!!!???%d %d\n",*lower_bound(b+1,b+b[0]+1,c[i]),c[i]);
		}
		printf(ok?"YES\n":"NO\n");
	}
}