#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int A[100010],mod=10007;
int cmp(const void *xx,const void *yy)
{
	int x=*(int *)xx,y=*(int *)yy;
	return x-y;
}
int main()
{
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&A[i]);
    qsort(A+1,n,sizeof(int),cmp);
    for(i=1;i<=n;i++)ans=(ans+(long long)A[i]*A[n-i+1])%mod;
	printf("%d\n",ans);
	return 0;
}