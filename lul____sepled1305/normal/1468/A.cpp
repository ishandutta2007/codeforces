#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

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
    int n,i;
    cin>>n;
    int cur =2;
    while(cur < n)
        cur*=2;
    segment dptree = segment(cur);
    segment valtree = segment(cur);
    int a[n],dp[n],par[n],maxi = 0;
    pii b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = {a[i],i};
        dp[i] = 1;
        valtree.rep(i,a[i]);
        dptree.rep(i,0);
    }
    sort(b,b+n,greater<pii>());
    for(i=0;i<n;i++)
    {
        int pos = b[i].second;
        int val = b[i].first;
        pii ma = dptree.ask_max(1,1,cur,pos+1,n-1);
        if(ma.second == -1e9)
            ma.second = 0;
        dp[pos] = ma.second +1;
        //cout<<"DP: "<<ma.first<<' '<<ma.second<<endl;
        if(valtree.ask_max(1,1,cur,pos+1,ma.first-1).second > val)
            dp[pos]++;
        dptree.rep(pos,dp[pos]);
        maxi = max(maxi,dp[pos]);
        //cout<<pos<<' '<<dp[pos]<<endl;
        if(pos!=0)
            maxi = max(maxi,dp[pos]+1);
    }
    cout<<maxi<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}