#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    cin>>n;

    string inp;

    cin>>inp;

    int cnt=1;

    vector<int> given={};

    for(int i=1;i<inp.size();i++)
        if(inp[i]==inp[i-1])cnt++;
        else
        {
            given.push_back(cnt);
            cnt=1;
        }

    given.push_back(cnt);

    int outp=0;

    for(int i=0;i+1<given.size();i++)
        if(given[i]%2)given[i]--,given[i+1]++,outp++;

    return outp;
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