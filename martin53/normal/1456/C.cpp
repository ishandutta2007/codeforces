#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,k,inp[nmax];

long long outp=0,bonus=0;

priority_queue<long long> pq;

int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    for(int i=1;i<=k+1;i++)pq.push(0);

    for(int i=n;i>=1;i--)
    {
        long long tp=pq.top();
        pq.pop();
        outp+=tp;

        //cout<<i<<" -> "<<tp<<endl;

        tp+=inp[i];

        //cout<<"tp= "<<tp<<endl;

        pq.push(tp);
    }

    printf("%lld\n",outp);
    return 0;
}