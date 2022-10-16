#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>e[n+1];
    vector<int>rd(n+1);
    while(m--)
    {
        int x,y;
        cin>>y>>x;
        e[x].push_back(y);
        rd[y]++;
    }
    set<int>s;
    for(int x=1;x<=n;x++)
    if(!rd[x])s.insert(-x);
    int now=n;
    vector<int>ans(n+1);
    while(!s.empty())
    {
        int x=*s.begin();
        s.erase(x);
        for(auto q:e[-x])
        {
            rd[q]--;
            if(rd[q]==0)s.insert(-q);
        }
        ans[-x]=now;
        now--;
    }
    for(int x=1;x<=n;x++)
    cout<<ans[x]<<' ';
}