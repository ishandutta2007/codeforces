#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

int cnt;

void dfs(int pos,int sum)
{
    if(pos>n)
    {
        if(sum==0)cnt++;
        return;
    }

    dfs(pos+1,sum);
    dfs(pos+1,sum-inp[pos]);
    dfs(pos+1,sum+inp[pos]);
}
bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    cnt=0;

    dfs(1,0);

    return cnt>=2;
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