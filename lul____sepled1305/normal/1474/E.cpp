#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
 
void solve()
{
    int n,i,j;
    cin>>n;
    long long sum = 0;
    vector<pii> mov;
    vector<int> per;
    if(n%2 == 0)
    {
        //Split right at half. So, 1->n-1,...,1->n/2+1
        //Then n->2,n->3,...,n->n/2
        //Then 1->n
        for(i=0;i<n/2-1;i++)
            mov.push_back({n/2+i,0}),sum+=1LL * (n/2+i)*(n/2+i);
        for(i=0;i<n/2-1;i++)
            mov.push_back({n/2-1-i,n-1}),sum+=1LL * (n/2+i)*(n/2+i);
        mov.push_back({0,n-1});
        per.push_back(n/2);
        for(i=0;i<n/2-1;i++)
            per.push_back(i);
        for(i=0;i<n/2-1;i++)
            per.push_back(n/2+i+1);
        per.push_back(n/2-1);
    }
    else
    {
        //Split right at half. So, 1->n-1,...,1->n/2+1
        //Then n->2,n->3,...,n->n/2
        //Then 1->n
        for(i=0;i<n/2;i++)
            mov.push_back({n/2+i,0}),sum+=1LL * (n/2+i)*(n/2+i);
        for(i=0;i<n/2-1;i++)
            mov.push_back({n/2-i-1,n-1}),sum+=1LL * (n/2+i+1)*(n/2+i+1);
        mov.push_back({0,n-1});
        per.push_back(n/2);
        for(i=0;i<n/2-1;i++)
            per.push_back(i);
        for(i=0;i<n/2;i++)
            per.push_back(n/2+i+1);
        per.push_back(n/2-1);
    }
    sum+=1LL*(n-1)*(n-1);
    cout<<sum<<endl;
    for(auto it: per)
        cout<<it+1<<' ';
    cout<<endl;
    cout<<n-1<<endl;
    for(auto it: mov)
        cout<<it.first+1<<' '<<it.second+1<<endl;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}