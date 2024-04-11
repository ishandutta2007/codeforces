#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k,i,j;
    ll sum = 0;
    vector<ll> v;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<ll>());
    priority_queue<ll> pq;
    for(i=0;i<k+1;i++)
        pq.push(0LL);
    for(i=0;i<n;i++)
    {
        ll cur = pq.top();
        pq.pop();
        sum+=cur;
        pq.push(cur+v[i]);
    }
    cout<<sum;
}