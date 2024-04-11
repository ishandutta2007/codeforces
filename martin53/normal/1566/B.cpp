#include<bits/stdc++.h>
using namespace std;

int solve()
{
    string inp;
    cin>>inp;

    int i=0,j=inp.size()-1;

    while(i<=j&&inp[i]=='1')i++;

    while(i<=j&&inp[j]=='1')j--;

    if(i>j)return 0;

    for(int p=i;p<=j;p++)
        if(inp[p]=='1')return 2;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}