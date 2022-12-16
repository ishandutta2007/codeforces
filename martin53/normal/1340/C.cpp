#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+42,kmax=1e3+42;
int sz,n,inp[nmax];

int g,r;

int when[nmax][kmax];

priority_queue< pair<int/*time*/, int/*island*/> > pq;

bool is_group(int t1,int t2)
{
    if(t1>t2)swap(t1,t2);
    int which=t1/g;

    return t2<=(which+1)*g;
}

long long actual(long long t)
{
    long long full=(t-1)/g;
    return t+full*r;
}

bool lss(int a,int b)
{
    return a==-1||a>b;
}
int main()
{
    scanf("%i%i",&sz,&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    scanf("%i%i",&g,&r);

    for(int i=1;i<n;i++)
        if(inp[i+1]-inp[i]>g)
        {
            printf("-1\n");
            return 0;
        }

    memset(when,-1,sizeof(when));

    pq.push({0,1});

    when[1][0]=0;

    int in=0;
    while(pq.size())
    {
        pair<int/*time*/, int/*island*/> tp=pq.top();
        pq.pop();

        tp.first=-tp.first;

        if(tp.second==n)
        {
            //cout<<in<<endl;
            printf("%lld\n",actual(tp.first));
            return 0;
        }

        if(when[tp.second][tp.first%g]!=tp.first)continue;
        when[tp.second][tp.first%g]=tp.first;
        in++;

        int i=tp.second;

        //go left
        if(i>=2&&is_group(tp.first,tp.first+inp[i]-inp[i-1])&&lss(when[i-1][(tp.first+inp[i]-inp[i-1])%g],tp.first+inp[i]-inp[i-1]))
        {
            when[i-1][(tp.first+inp[i]-inp[i-1])%g]=tp.first+inp[i]-inp[i-1];
            pq.push({-(tp.first+inp[i]-inp[i-1]),i-1});
        }
        //go right
        if(i<n&&is_group(tp.first,tp.first+inp[i+1]-inp[i])&&lss(when[i+1][(tp.first+inp[i+1]-inp[i])%g],tp.first+inp[i+1]-inp[i]))
        {
            when[i+1][(tp.first+inp[i+1]-inp[i])%g]=tp.first+inp[i+1]-inp[i];
            pq.push({-(tp.first+inp[i+1]-inp[i]),i+1});
        }
    }

    //cout<<in<<endl;

    printf("-1\n");
    return 0;
}