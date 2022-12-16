#include<bits/stdc++.h>
using namespace std;

string solve()
{
    vector<int> seen[2]={};

    int n;
    cin>>n;

    string inp;

    cin>>inp;

    for(int i=0;i<inp.size();i++)
        if(inp[i]=='T')seen[0].push_back(i);
        else seen[1].push_back(i);

    if(seen[0].size()!=seen[1].size()*2)return "NO";

    int m=seen[1].size();

    for(int i=0;i<m;i++)
        if(seen[0][i]<seen[1][i]&&seen[1][i]<seen[0][i+m]);
        else return "NO";

    return "YES";
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;
        cout<<solve()<<endl;
    }


    return 0;
}