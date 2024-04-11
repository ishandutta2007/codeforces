#include<bits/stdc++.h>
using namespace std;
int n,i,j;
using pii = pair<int,int>;

int main()
{
    cin>>n;
    int a[n];
    pii sr[n];
    vector<pii> ans;
    for(i=0;i<n;i++)
        cin>>a[i],sr[i]={a[i],i};
    sort(sr,sr+n);
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>sr[i].second;j--)
        {
            if(a[j]<a[sr[i].second])
                ans.push_back({sr[i].second,j});
        }
    }
    cout<<ans.size()<<"\n";
    for(i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
}