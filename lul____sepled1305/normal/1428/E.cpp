#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;

ll cut(int l, int k)
{
    k++;
    ll cur = l;
    if(k == 1)
        return cur*cur;
    else
    {
        ll num = cur%k;
        return num * (cur/k + 1)*(cur/k + 1) + (k-num) * (cur/k) * (cur/k);
    }
}

int main()
{
    int n,i,k;
    ll ans = 0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];

    priority_queue<pair<ll,pii>> pq;

    for(i=0;i<n;i++)
    {
        ans+=cut(a[i],0);
        pq.push({cut(a[i],0) - cut(a[i],1),{i,0}});
    }

    while(n!=k)
    {
        n++;
        pair<long long, pii> cur = pq.top();
        pq.pop();
        ans-=cur.first;

        pii it = cur.second;
        it.second++;
        pq.push({cut(a[it.first],it.second) - cut(a[it.first],it.second+1),{it.first,it.second}});
    }

    cout<<ans;
}