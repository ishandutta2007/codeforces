#include<cstdio>
#include<algorithm>
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;

int main(void)
{
    int i,n;
    scanf("%d",&n);
    if(n%2==0) printf("-1");
    else
    {
        ff(i,0,n-1) printf("%d ",i);
        printf("\n");
        f(i,n-1) printf("%d ",i);printf("0\n");
        f(i,n-1) printf("%d ",(2*i-1)%n);printf("%d",n-1);
    }
}