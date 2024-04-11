#include<bits/stdc++.h>
using namespace std;

int ask(int a,int b)
{
    if(b==1)return 1e9;

    int outp=0;

    while(a)
    {
        outp++;
        a=a/b;
    }

    return outp;
}
int solve()
{
    int a,b;

    scanf("%i%i",&a,&b);

    int outp=1e9;

    for(int i=0;i<=50;i++)
        outp=min(outp,ask(a,b+i)+i);

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}