#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
vector<int> inp;

bool by_hand()
{
    for(int i=inp.size()-1;i>=0;i--)
    {
        if(inp[i]%(i+2))
        {
            inp.erase(inp.begin()+i,inp.begin()+i+1);
            return 1;
        }
    }

    return 0;
}

bool solve()
{
    scanf("%i",&n);

    inp={};

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        inp.push_back(cur);
    }

    while(inp.size())
    {
        if(by_hand()==0)return 0;

        while(inp.size()&&inp.back()%(inp.size()+1))inp.pop_back();
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