#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>a[200001];
main() {
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        set<int>s;
        stack<int>q;
        s.clear();
        int n;
        cin>>n;
        for(int x=1,y;x<=n;x++)
        cin>>y,a[x]={y,-x};
        sort(a+1,a+1+n);
        for(int x=1;x<=n;x++)
        {
            if(x!=1&&a[x].first-a[x-1].first)
            while(!q.empty())s.insert(q.top()),q.pop();
            q.push(a[x].second);
            for(int y=1;!s.empty()&&*s.begin()<a[x].second;y++)
            s.erase(a[y].second);
            ans=max(ans,(int)(s.size()+q.size()));
        }
        cout<<n-ans<<endl;
        while(!q.empty())q.pop();
    }
}