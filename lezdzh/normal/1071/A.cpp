#include<cstdio>

using namespace std;

int a,b;
int c[100001];
bool pd(int mid){
	for(int i=1;i<=100000;i++)
		c[i]=1;
	int aa=a,bb=b;
	for(int i=mid;i>0;i--)
	if(aa>=i)aa-=i,c[i]=0;
	for(int i=mid;i>0;i--)
		if(c[i])
			if(bb>=i)bb-=i;
			else goto ed;
	return 1;
	ed:;return 0;
}
int main(){
	scanf("%d%d",&a,&b);
	int l=0,r=100000;
	while(l^r){
		int mid=l+r+1>>1;
		if(pd(mid))l=mid;
		else r=mid-1;
	}
	pd(l);
	int ans1=0,ans2=0;
	for(int i=1;i<=l;i++)
		if(!c[i])ans1++;
		else ans2++;
	printf("%d\n",ans1);
	for(int i=1,ok=0;i<=l;i++)
		if(!c[i])printf(ok?" %d":(ok=1,"%d"),i);
	printf("\n");
	printf("%d\n",ans2);
	for(int i=1,ok=0;i<=l;i++)
		if(c[i])printf(ok?" %d":(ok=1,"%d"),i);
	printf("\n");
}