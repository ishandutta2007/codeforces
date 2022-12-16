#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,p,k,inp[nmax];

map<int,int> seen={};
int main()
{
    scanf("%i%i%i",&n,&p,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long answer=0;
    for(int i=1;i<=n;i++)
    {
        long long now=(1LL*inp[i]*inp[i])%p;
        now=now*now%p;
        now=now-1LL*k*inp[i];
        now=now%p;
        now=(now+p)%p;

        answer=answer+seen[now];

        seen[now]++;
    }
    printf("%lld\n",answer);
    return 0;
}