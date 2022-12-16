#include<bits/stdc++.h>
using namespace std;

int eval(int num)
{
    int ret=0;

    for(int p=2;p*p<=num;p++)
        while(num%p==0)
        {
            ret++;
            num=num/p;
        }

    if(num>1)ret++;
    return ret;
}

bool solve()
{
    int a,b,k;
    scanf("%i%i%i",&a,&b,&k);

    int low=2;
    if((a%b==0||b%a==0)&&a!=b)low=1;

    int high=eval(a)+eval(b);

    return low<=k&&k<=high;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}