#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d,sum1,sum2;cin>>n;
    vector<long long int>v;
    set<long long int>s;
    for(long long int i=0;i<2*n;i++)
    {
        cin>>d;
        v.push_back(d);
        s.insert(d);
    }
    if(s.size()==1)
    {
        cout<<-1<<endl;
    }
    else
    {
        sort(v.begin(),v.end());
        for(long long int i=0;i<2*n-1;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<v.back()<<endl;
    }
}
int main()
{
    solve();
}