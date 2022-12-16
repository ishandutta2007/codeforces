#include<bits/stdc++.h>
using namespace std;

bool on[30];

bool solve()
{
    string inp;

    cin>>inp;

    memset(on,0,sizeof(on));

    for(auto w:inp)
    {
        if(on[w-'a'])return 0;

        on[w-'a']=1;
    }

    for(int i=0;i<inp.size();i++)
        if(on[i]==0)return 0;

    int l=0,r=inp.size()-1;

    for(int i=inp.size()-1;i>=0;i--)
    {
        //cout<<i<<" "<<l<<" "<<r<<" "<<inp[l]<<" "<<inp[r]<<" "<<char(i+'a')<<endl;

        if(inp[l]==char(i+'a'))l++;
        else if(inp[r]==char(i+'a'))r--;
        else return 0;
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