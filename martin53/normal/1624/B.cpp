#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int a,b,c;

    scanf("%i%i%i",&a,&b,&c);

    int x=2*b-c;
    if(x>0&&x%a==0)return 1;

    x=a+c;
    if(x%2==0&&(x/2)%b==0)return 1;

    x=2*b-a;
    if(x>0&&x%c==0)return 1;

    return 0;
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