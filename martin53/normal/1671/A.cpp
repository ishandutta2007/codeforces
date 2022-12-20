#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;
    cin>>inp;

    for(int i=0;i<inp.size();i++)
    {
        int j=i;

        while(inp[j]==inp[i]&&j<inp.size())j++;

        j--;

        if(i==j)return 0;

        i=j;
    }

    return 1;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}