#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    string inp;

    cin>>n>>inp;

    set<string> in={};

    for(int i=0;i<n;i++)
    {
        string cur="";

        for(int j=i;j<n&&j-i<=2;j++)
        {
            cur.push_back(inp[j]);

            in.insert(cur);
        }
    }

    for(char a='a';a<='z';a++)
    {
        string me="";
        me.push_back(a);

        if(in.count(me)==0)return me;
    }

    for(char a='a';a<='z';a++)
    for(char b='a';b<='z';b++)
    {
        string me="";
        me.push_back(a);
        me.push_back(b);

        if(in.count(me)==0)return me;
    }

    for(char a='a';a<='z';a++)
    for(char b='a';b<='z';b++)
    for(char c='a';c<='z';c++)
    {
        string me="";
        me.push_back(a);
        me.push_back(b);
        me.push_back(c);

        if(in.count(me)==0)return me;
    }
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