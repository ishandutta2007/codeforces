#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n;
int output[nmax];

int main()
{
    scanf("%i",&n);

    if(n%2==1)
    {
        for(int i=1;i<=n;i++)
            if(i%2==1)
            {
                output[i]=2*i-1;
                output[i+n]=2*i;
            }
            else
            {
                output[i]=2*i;
                output[i+n]=2*i-1;
            }
        printf("YES\n");
        for(int i=1;i<=2*n;i++)printf("%i ",output[i]);
        printf("\n");
        return 0;
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}