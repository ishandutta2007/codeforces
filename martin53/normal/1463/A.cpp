#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int a,b,c;

    scanf("%i%i%i",&a,&b,&c);

    if((a+b+c)%9)return 0;

    int turns=(a+b+c)/9;

    return a>=turns&&b>=turns&&c>=turns;
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