#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;

    string inp;
    cin>>inp;

    int outp=0;
    for(int i=0;i<n;i++)
        if(inp[i]!='0')
        {
            outp+=inp[i]-'0';
            if(i!=n-1)outp++;
        }
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