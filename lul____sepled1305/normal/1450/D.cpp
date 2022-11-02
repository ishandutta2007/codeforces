/** Ithea Myse Valgulious **/
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;
 
struct segment
{
    vector<pii> mini;
    vector<pii> maxi;
    int n;
 
    segment(int n)
    {
        this->n = n-1;
        n*=4;
        for(int i=0;i<n;i++)
        {
            mini.push_back({0,1e9});
            maxi.push_back({0,-1e9});
        }
    }
 
    void rep(int idx, int val)
    {
        mini[n+idx].second = val;
        mini[n+idx].first = idx;
        maxi[n+idx].second = val;
        maxi[n+idx].first = idx;
        idx = n+idx;
        idx/=2;
        while(idx > 0)
        {
            if(mini[2*idx].second < mini[2*idx+1].second)
                mini[idx] = mini[2*idx];
            else
                mini[idx] = mini[2*idx+1];
            if(maxi[2*idx].second > maxi[2*idx+1].second)
                maxi[idx] = maxi[2*idx];
            else
                maxi[idx] = maxi[2*idx+1];
            idx/=2;
        }
    }
 
    pii ask_min(int idx, int tl, int tr, int l, int r)
    {
        if(l>r)
            return {0,1e9};
 
        if(tl==l && tr==r)
            return mini[idx];
 
        int mid = tl+tr >> 1;
        pii can1 = ask_min(2*idx,tl,mid,l,min(mid,r));
        pii can2 = ask_min(2*idx+1,mid+1,tr,max(l,mid+1),r);
 
        if(can1.second < can2.second )
            return can1;
        return can2;
    }
 
    pii ask_max(int idx, int tl, int tr, int l, int r)
    {
        if(l>r)
            return {0,-1e9};
 
        if(tl==l && tr==r)
            return maxi[idx];
 
        int mid = tl+tr >> 1;
        pii can1 = ask_max(2*idx,tl,mid,l,min(mid,r));
        pii can2 = ask_max(2*idx+1,mid+1,tr,max(l,mid+1),r);
 
        if(can1.second > can2.second )
            return can1;
        return can2;
    }
};
 
void solve()
{
    int n,i,j;
    int cur = 2;
    cin>>n;
    while(cur < n)
        cur*=2;
    segment qu = segment(cur);
    int found[n];
    vector<int> v;
    deque<int> de;
    for(i=0;i<n;i++)
        found[i] = 0;
 
    for(i=0;i<n;i++)
    {
        cin>>j;
        j--;
        v.push_back(j);
        qu.rep(i+1,j);
        de.push_back(j);
    }
 
    vector<int> ans;
    int pointer1=1,pointer2 = n;
    bool bomb = false;
 
    while(de.size() != 1)
    {
        if(bomb || qu.ask_min(1,1,cur,pointer1,pointer2).second != n-de.size())
        {
            ans.push_back(0);
        }
        else
            ans.push_back(1);
 
        //cout<<de.size()<<' '<<ans.back()<<' '<<qu.ask_min(1,1,cur,pointer1,pointer2).second<<endl;
 
        int mini = min(de.front(),de.back());
        if(mini == de.front())
        {
            de.pop_front();
            if(mini != n-1-de.size())
                bomb = true;
            pointer1++;
        }
        else
        {
            de.pop_back();
            if(mini != n-1-de.size())
                bomb = true;
            pointer2--;
        }
    }
    sort(v.begin(),v.end());
    int good = 1;
    for(i=0;i<n-1;i++)
    {
        if(v[i] == v[i+1])
            good = 0;
    }
    ans.push_back(good);
    while(!ans.empty())
    {
        cout<<ans.back();
        ans.pop_back();
    }
    cout<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>T;
    while(T--)
        solve();
    return 0;
}