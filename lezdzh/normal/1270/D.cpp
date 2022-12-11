#include<cstdio>

using namespace std;

int n,k;
int s[501],a[501];
int xw(){
	printf("?");
	for(int i=1;i<=k;i++)
		printf(" %d",s[i]);
	printf("\n");
	fflush(stdout);
	int o,x;
	scanf("%d%d",&o,&x);
	a[o]=x;
	return o;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		s[i]=i;
	int p=xw();
	s[p]=k+1;
	int p2=xw();
	int ans=0;
	for(int i=1;i<=k;i++)
		if(i!=p){
			s[i]=p;
			int o=xw();
			if(a[p]<a[p2]&&o==p2||a[p]>a[p2]&&o!=p2)
				ans++;
			s[i]=i;
		}
	printf("! %d\n",ans+1);
}