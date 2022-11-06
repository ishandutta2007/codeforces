#include <stdio.h>

int a[110];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
    int n;
    int m=0;
    int sum=0;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {scanf("%d",&a[i]);}

    for(int i=1;i<=n;i++)
        { if(a[i]==0)
            {a[i]=a[i]+1;
             m=m+1;
            }
        }

    for(int i=1;i<=n;i++)
    {sum=sum+a[i];}

    if(sum==0)
    {m=m+1;}

    printf("%d\n",m);
	}
}