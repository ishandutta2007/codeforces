#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m;

int seen_a[nmax],seen_b[nmax];

long long k;

long long common;

void euclid(long long &p,long long A,long long &q,long long B)
{
    long long p1=1,q1=0;
    long long p2=0,q2=1;

    while(B)
    {
        long long alpha=A/B;
        long long beta=A%B;

        long long p3=p1-alpha*p2;
        long long q3=q1-alpha*q2;

        p1=p2;
        p2=p3;

        q1=q2;
        q2=q3;

        A=B;
        B=beta;
    }

    p=p1;
    q=q1;
}
long long solve(int a,int b)
{
    //pn+a=qm+b
    int A=n,B=m;
    int C=b-a;

    int g=__gcd(A,B);

    if(C%g)return -1;

    A=A/g;
    B=B/g;
    C=C/g;

    //cout<<"solving "<<A<<" "<<B<<" "<<C<<endl;

    long long p,q;

    euclid(p,A,q,B);

    p=p*C;
    q=(-q)*C;

    //pA-qB=C
    long long ret=q*m+b;
    ret=ret%common+common;
    if(ret>common)ret=ret-common;

    return ret;
}

vector<long long> seen;

long long test(long long c)
{
    long long ret=c;

    for(auto w:seen)
        if(w<=c)
        {
            ret=ret-1-(c-w)/common;
        }

    //cout<<"test "<<c<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    scanf("%i%i%lld",&n,&m,&k);

    common=1LL*n*m/__gcd(n,m);

    for(int i=1;i<=n;i++)
    {
        int val;
        scanf("%i",&val);
        seen_a[val]=i;
    }

    for(int i=1;i<=m;i++)
    {
        int val;
        scanf("%i",&val);
        seen_b[val]=i;
    }

    for(int i=1;i<nmax;i++)
        if(seen_a[i]&&seen_b[i])
        {
            long long is=solve(seen_a[i],seen_b[i]);
            if(is==-1)continue;

            seen.push_back(is);

            //cout<<i<<" -> "<<is<<endl;
        }

    long long ok=0,not_ok=1e18;
    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;

        if(test(av)<k)ok=av;
        else not_ok=av;
    }

    printf("%lld\n",ok+1);

    return 0;
}