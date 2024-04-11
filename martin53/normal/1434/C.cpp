#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int a,b,c,d;

long long eval(long long t)
{
    if(t<0)return 0;

    long long ret=(t/d+1)*a;

    long long hits=t/d;

    long long full=(t-c)/d;

    if(full<0)full=0;

    ret=ret-1LL*full*c*b;

    //cout<<"ret= "<<ret<<endl;

    if(full>=hits)return ret;

    long long not_full=hits-full;

    long long start=t-(hits)*d;

    long long gain=d;

    long long sz=hits-full+1;

    long long sub=sz*start+1LL*gain*(sz-1)*sz/2;

    sub=sub*b;

    ret=ret-sub;

    //cout<<t<<" -> "<<ret<<" "<<sz<<" "<<start<<" "<<gain<<" "<<sz<<" "<<sub<<endl;

    return ret;
}

void solve()
{
    scanf("%i%i%i%i",&a,&b,&c,&d);

    long long lose=a-1LL*b*c;

    if(lose>0)
    {
        printf("-1\n");
        return;
    }

    //lose<=0

    if(c<d)
    {
        printf("%i\n",a);
        return;
    }

    long long outp=0;

    int ok=-1,not_ok=1e6+42;

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        long long mem_1=eval(1LL*d*av);
        long long mem_2=eval(1LL*d*(av+1));

        outp=max(outp,mem_1);
        outp=max(outp,mem_2);

        if(mem_1<mem_2)ok=av;
        else not_ok=av;
    }
    printf("%lld\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}