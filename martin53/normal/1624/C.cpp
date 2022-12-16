#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq,idle;

bool solve()
{
    pq=idle;

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        pq.push(cur);
    }

    for(int i=n;i>=1;i--)
    {
        while(pq.top()>i)
        {
            pq.push(pq.top()/2);
            pq.pop();
        }

        if(pq.top()!=i)return 0;

        pq.pop();
    }

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}