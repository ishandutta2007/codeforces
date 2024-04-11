#include <iostream>
using namespace std;

int q[20500];

void main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,ans=-1000000000;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
        scanf("%d",&q[i]);

    for (int i=3;i<=n;i++)
        if (n%i==0)
        {
            int k=n/i;
            for (int j=0;j<k;j++)
            {
                int curans=0;
                for (int h=0;h<i;h++)
                    curans+=q[j+h*k];
                if (curans>ans)
                    ans=curans;
            }
        }
    printf("%d",ans);
}