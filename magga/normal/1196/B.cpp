#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k,t;cin>>n>>k;
    vector<long long int>v;
    for(long long int i=0;i<n;i++)
    {
        cin>>t;
        if(t%2==1)
        {
            v.push_back(i);
        }
    }
    if(v.size()>=k && (v.size()-k)%2==0)
    {
        cout<<"YES"<<endl;
        for(long long int i=0;i<k-1;i++)
        {
            cout<<v[i]+1<<" ";
        }
        cout<<n<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}