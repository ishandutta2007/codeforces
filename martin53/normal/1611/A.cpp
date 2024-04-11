#include<bits/stdc++.h>
using namespace std;

int solve()
{
    string inp;
    cin>>inp;

    int n=inp.size();

    if((inp[n-1]-'0')%2==0)return 0;

    if((inp[0]-'0')%2==0)return 1;

    for(int i=0;i+1<n;i++)
        if((inp[i]-'0')%2==0)return 2;

    return -1;
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