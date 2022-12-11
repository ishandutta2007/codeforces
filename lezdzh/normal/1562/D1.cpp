#include<cstdio>

using namespace std;

char s[300002];
int a[300001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,q;
		scanf("%d%d%s",&n,&q,s+1);
		for(int i=1;i<=n;i++)
			a[i]=a[i-1]+((s[i]=='+')^(i%2==1)?1:-1);
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			if(a[r]-a[l-1]==0)printf("0\n");
			else{
//			for(int i=1;i<=n;i++)
//				if(a[i-1]==a[n]-a[i]){printf("1\n");goto ed;}
			if((r-l+1)%2==0)printf("2\n");
			else printf("1\n");
			ed:;
			}
		}
	}
}