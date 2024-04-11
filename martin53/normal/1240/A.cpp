#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

int x,a,y,b;

long long ask(int tickets)
{
    int both=tickets/(1LL*a*b/__gcd(a,b));

    int only_a=tickets/a-both;

    int only_b=tickets/b-both;

    //cout<<"both= "<<both<<" only_a= "<<only_a<<" only_b= "<<only_b<<endl;

    long long ret=0;

    for(int i=1;i<=n;i++)
    {
        if(both)
        {
            ret=ret+1LL*inp[i]*(x+y)/100;
            both--;
            continue;
        }

        if(x>y)
        {
            if(only_a)
            {
                ret=ret+1LL*inp[i]*x/100;
                only_a--;
                continue;
            }
            else if(only_b)
            {
                ret=ret+1LL*inp[i]*y/100;
                only_b--;
                continue;
            }
        }
        else
        {
            if(only_b)
            {
                ret=ret+1LL*inp[i]*y/100;
                only_b--;
                continue;
            }
            else if(only_a)
            {
                ret=ret+1LL*inp[i]*x/100;
                only_a--;
                continue;
            }
        }
    }

    //cout<<tickets<<" -> "<<ret<<endl;
    return ret;
}
bool cmp(int u,int v)
{
    return u>v;
}
long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1,cmp);

    scanf("%i%i",&x,&a);

    scanf("%i%i",&y,&b);

    long long want;
    scanf("%lld",&want);

    if(ask(n)<want)return -1;

    int ok=n,not_ok=0;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(ask(av)>=want)ok=av;
        else not_ok=av;
    }
    //cout<<"ok= "<<ok<<endl;
    return ok;
}
int main()
{
    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
        printf("%lld\n",solve());

    return 0;
}