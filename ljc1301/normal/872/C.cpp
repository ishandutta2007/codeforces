#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n&1)
        {
            if(n==9) printf("1\n");
            else
            {
                n=(n-9)/2;
                if(n<=1) printf("-1\n");
                else printf("%d\n",n/2+1);
            }
        }
        else
        {
            n/=2;
            if(n<=1) printf("-1\n");
            else printf("%d\n",n/2);
        }
    }
    return 0;
}