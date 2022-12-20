#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int n;
    cin>>n;

    map<int,int> seen={};

    long long ret=0;

    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;

        ret+=seen[val-i];
        seen[val-i]++;
    }

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