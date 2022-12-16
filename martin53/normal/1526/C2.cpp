#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

priority_queue<int> pq;

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=0,outp=0;

    for(int i=1;i<=n;i++)
        if(inp[i]>=0)
        {
            sum+=inp[i];
            outp++;
        }
        else if(inp[i]+sum>=0)
        {
            sum+=inp[i];
            outp++;

            pq.push(-inp[i]);
        }
        else if(pq.size()&&pq.top()+sum+inp[i]>=0)//too much
        {
            sum+=inp[i];

            pq.push(-inp[i]);

            sum+=pq.top();

            pq.pop();
        }

    printf("%lld\n",outp);

    return 0;
}