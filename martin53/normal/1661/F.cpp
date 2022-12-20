#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;
int n,inp[nmax];
long long m;

long long eval(long long d,long long x)
{
    long long g=d/x;

    return d%x*(g+1)*(g+1)+(x-d%x)*g*g;
}

void test()
{
    for(int d=1;d<=1e4;d++)
    {
        for(int x=1;x<d;x++)
        {
            assert(eval(d,x)>=eval(d,x+1));
        }

        //cout<<d<<" -> ";for(int x=1;x<=d;x++)cout<<eval(d,x)<<" ";cout<<endl;

        for(int x=2;x<d;x++)
        {
            assert(eval(d,x-1)-eval(d,x)>=eval(d,x)-eval(d,x+1));
        }
    }
}

long long to_save;

int outp;

//collect all with diff(d,x-1)-diff(d,x)>=av
pair<long long/*saved*/,int/*placed*/> ask(long long delta,bool upd)
{
    pair<long long/*saved*/,int/*placed*/> ret={0,0};

    for(int i=1;i<=n;i++)
    {
        long long d=inp[i]-inp[i-1];

        int ok_x=1,not_ok_x=d+1;

        while(not_ok_x-ok_x>1)
        {
            int av=(ok_x+not_ok_x)/2;

            if(eval(d,av-1)-eval(d,av)>=delta)ok_x=av;
            else not_ok_x=av;
        }

        ret.second+=ok_x-1;
        ret.first+=eval(d,1)-eval(d,ok_x);

        //cout<<" i= "<<i<<" ok_x= "<<ok_x<<" "<<eval(d,1)<<" and "<<eval(d,ok_x)<<" "<<eval(d,ok_x+1)<<endl;
    }

    if(ret.first>=to_save&&upd)
    {
        long long t=(ret.first-to_save)/delta;
        outp=min(1LL*outp,ret.second-t);
    }

    //cout<<delta<<" -> "<<ret.first<<" "<<ret.second<<" "<<upd<<" "<<to_save<<endl;

    return ret;
}

int main()
{
    //test();
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);
    scanf("%lld",&m);

    long long score_now=0;
    for(int j=1;j<=n;j++)score_now+=1LL*(inp[j]-inp[j-1])*(inp[j]-inp[j-1]);

    if(score_now<=m)
    {
        printf("0\n");
        return 0;
    }

    to_save=score_now-m;

    outp=inp[n];

    long long ok=0,not_ok=1LL*inp[n]*inp[n]+1;

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;

        pair<long long/*saved*/,int/*placed*/> cur=ask(av,0);

        if(cur.first<to_save)not_ok=av;
        else ok=av;
    }

    ask(ok,1);

    printf("%i\n",outp);

    return 0;
}