#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n,k;
    cin>>n>>k;

    string inp;
    cin>>inp;

    if(2*k>=n)return 0;

    int i=0;

    while(i<n-1-i&&inp[i]==inp[n-1-i])i++;

    return i>=k;
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