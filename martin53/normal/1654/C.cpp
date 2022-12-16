#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

map<long long,int> seen;

int n;

vector<long long> on;

void push(long long val)
{
    if(seen[val])
    {
        seen[val]--;
        n--;
    }
    else on.push_back(val);
}

bool solve()
{
    seen={};

    scanf("%i",&n);

    long long sum=0;

    for(int i=1;i<=n;i++)
    {
        int val;

        scanf("%i",&val);
        seen[val]++;

        sum=sum+val;
    }

    on={};

    push(sum);

    int pointer=0;

    while(pointer+n>on.size())
    {
        long long cur=on[pointer];
        pointer++;

        push(cur/2);
        push((cur+1)/2);
    }

    return pointer==on.size();
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