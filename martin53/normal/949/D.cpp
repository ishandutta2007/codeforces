#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,d,b;
int inp[nmax];

long long LHS[nmax],RHS[nmax];

int exact(int up_to)
{
    long long extra=0;

    int ret=0;

    int border=0;

    for(int i=1;i<=up_to;i++)
    {
        long long l=i+1,r=i+1LL*i*d;

        if(l>n)l=n+1;
        if(l<=border)l=border+1;

        if(r>n)r=n;

        border=r;

        for(int j=l;j<=r;j++)
        {
            LHS[i]=LHS[i]+LHS[j];
            LHS[j]=0;
        }

        if(LHS[i]>=b)
        {
            LHS[i+1]+=LHS[i]-b;
        }
        else
        {
            ret++;
            LHS[i+1]+=LHS[i];
        }
    }

    return ret;
}

int outp=n;

int eval(long long sum)
{
    for(int i=1;i<=n;i++)
    {
        LHS[i]=min(sum,1LL*inp[i]);
        RHS[i]=inp[i]-LHS[i];

        sum=sum-LHS[i];
    }
    /*
    cout<<"sum= "<<sum<<endl;
    for(int i=1;i<=n;i++)cout<<LHS[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<RHS[i]<<" ";cout<<endl;
    */
    int one=exact((n+1)/2);

    for(int i=1;i<=n;i++)
        LHS[i]=RHS[n+1-i];

    int two=exact(n-(n+1)/2);

    //cout<<"one= "<<one<<" two= "<<two<<endl;

    outp=min(outp,max(one,two));

    return one-two>=0;
}
int main()
{
    scanf("%i%i%i",&n,&d,&b);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    outp=n;

    long long ok=0,not_ok=1LL*b*n;

    eval(ok);
    eval(not_ok);

    while(not_ok-ok>1)
    {
        long long av=(ok+not_ok)/2;
        if(eval(av))ok=av;
        else not_ok=av;
    }

    printf("%i\n",outp);
    return 0;
}