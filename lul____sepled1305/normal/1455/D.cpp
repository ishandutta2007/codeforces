#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x,i,counti = 0,last = -2;
    cin>>n>>x;
    vector<int> v;
    int par[n];
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
        par[i] = -1;
    }
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<"0\n";
        return;
    }
    for(i=0;i<n;i++)
    {
        if(v[i] > x)
        {
            swap(x,v[i]);
            counti++;
            par[i] = last;
            last = i;
            if(is_sorted(v.begin(),v.end()))
            {
                cout<<counti<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}