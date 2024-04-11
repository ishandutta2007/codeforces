#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,p,nps,d;cin>>n;
    long long int ns=0;
    long long int arr [n];
    vector<long long int>ans;
    cin>>p;
    nps=p;
    ns=p;
    for(long long int i=0;i<n-1;i++)
    {
        cin>>d;
        ns+=d;
        if(d*2<=p)
        {
            nps+=d;
            ans.push_back(i);
        }
    }
    ns=(ns+2)/2;
   // cout<<nps<<" "<<ns<<endl;
    if(nps>=ns && ans.size()!=0)
    {
        cout<<ans.size()+1<<endl;
        cout<<1<<" ";
        for(long long int i=0;i<ans.size()-1;i++)
        {
            cout<<ans[i]+2<<" ";
        }
        cout<<ans.back()+2<<endl;
    }
    else if(nps>=ns)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    for(long long int i=0;i<1;i++)
    {
       	solve();
    }   
}