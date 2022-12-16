#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;
    char c;

    cin>>inp>>c;

    for(int i=0;i<inp.size();i++)
        if(i%2==0&&(inp.size()-i-1)%2==0&&inp[i]==c)return 1;

    return 0;
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