#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n;
pair<int,long long> inp[nmax];

bool odd(long long cur,int up_to)
{
    //cout<<cur<<" "<<up_to<<" -> ";

    up_to++;

    int bits=0;

    while(cur&&up_to)
    {
        up_to--;

        bits+=cur%2;
        cur=cur/2;
    }

    //cout<<bits<<endl;

    return bits%2;
}
long long eval(long long mask,int up_to)
{
    long long ret=0;

    for(int i=1;i<=n;i++)
        if(inp[i].second<=(1LL<<up_to)-1+(1LL<<up_to))
    {
        long long cur=mask&inp[i].second;

        if(odd(cur,up_to))ret-=inp[i].first;
        else ret+=inp[i].first;
    }

    //cout<<mask<<" -> "<<ret<<endl;

    return ret;
}

bool sign(long long x)
{
    if(x<0)return 0;
    return 1;
}

bool valid(long long a,long long b)
{
    if(a==0)return 1;

    if(b==0)return 0;

    return sign(a)!=sign(b);
}



int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%lld",&inp[i].first,&inp[i].second);

    long long s=0;
    for(int i=1;i<=n;i++)
        s+=inp[i].first;

    if(s<0)
    {
        for(int i=1;i<=n;i++)
            inp[i].first=-inp[i].first;
    }

    long long outp=0;

    for(int i=0;i<62;i++)
    {
        long long sum[2]={0,0};

        for(int j=1;j<=n;j++)
        {
            long long st=1LL<<i;

            if(st<=inp[j].second&&inp[j].second<2*st)
            {
                sum[odd(inp[j].second&outp,70)]+=inp[j].first;
            }
        }

        if(sum[0]>sum[1])outp+=1LL<<i;

        //cout<<i<<" -> "<<sum[0]<<" "<<sum[1]<<endl;
    }

    //cout<<eval(outp,70)<<" "<<eval(0,70)<<endl;

    printf("%lld\n",outp);
    return 0;
}