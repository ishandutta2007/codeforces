#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,p;
int bits(int test)
{
    int ret=0;
    while(test)
    {
        if(test%2)ret++;
        test=test/2;
    }
    return ret;
}
int main()
{
    scanf("%i%i",&n,&p);

    for(int nums=1;nums*(p+1)<=n;nums++)
    {
        int now=n-nums*p;

        if(bits(now)<=nums)
        {
            printf("%i\n",nums);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}