#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,MX=2e7+42;
int c,d,x;

long long ret=0;

int cnt[MX];

void eval(int g)
{
    long long u=x+1LL*d*g;
    long long v=1LL*c*g;

    if(u%v)return;

    int num=u/v;

    ret+=(1<<cnt[num]);
}
void solve()
{
    scanf("%i%i%i",&c,&d,&x);

    ret=0;

    for(int g=1;g*g<=x;g++)
        if(x%g==0)
        {
            eval(g);
            if(g!=x/g)eval(x/g);
        }

    printf("%lld\n",ret);
}

int main()
{
    for(int i=1;i<MX;i++)
        cnt[i]=0;

    for(int p=2;p<MX;p++)
        if(cnt[p]==0)
        for(int j=p;j<MX;j=j+p)
            cnt[j]++;

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}