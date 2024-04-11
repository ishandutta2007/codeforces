#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k,d,rans;cin>>n>>k;
    vector<long long int>v;
    long long int answer=2000000000000;
    for(long long int i=0;i<n;i++)
    {
        cin>>d;v.push_back(d);    
    }
    sort(v.begin(),v.end());
    for(long long int i=0;i<n-k;i++)
    {     
        d=(v[i+k]-v[i]+1)/2;
        if(d<answer)
        {
            answer=d;
            rans=(v[i+k]+v[i]+1)/2;
        }
    }
    cout<<rans<<endl;
}
int main()
{
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}