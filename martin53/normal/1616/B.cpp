#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin>>n;

    string inp;
    cin>>inp;

    if(inp[0]<=inp[1])
    {
        string ret="";
        ret.push_back(inp[0]);
        ret.push_back(inp[0]);

        return ret;
    }

    int k=1;

    for(k=1;k<n;k++)
    {
        if(inp[k]>inp[k-1])break;
    }

    string ret="";

    for(int i=0;i<k;i++)ret.push_back(inp[i]);
    for(int i=k-1;i>=0;i--)ret.push_back(inp[i]);

    return ret;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}