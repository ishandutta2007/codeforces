#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii,int>;
int N = 1<<17;
 
struct node
{
    vector<pii> mask;
 
    void add(pii newMask)
    {
        while(!mask.empty() && mask.back().fi >= newMask.fi)
            mask.pop_back();
        if(mask.empty())
            mask.push_back(newMask);
        else
        {
            if(mask.back().se >= newMask.fi)
                mask.back().se = newMask.se;
            else
                mask.push_back(newMask);
        }
    }
 
    int applyMask(int t)
    {
        int mini = 0;
        if(mask.size() == 0)
            return t;
        if(mask[0].fi > t)
            return t;
        while(mini < mask.size() && mask[mini].fi <= t)
        {
            mini++;
        }
        mini--;
        return max(mask[mini].second,t);
    }
};
 
struct tree
{
private:
    int n;
    vector<node> v;
public:
    tree(int n)
    {
        this -> n = n;
        for(int i=0;i<2*n;i++)
        {
            node s;
            v.push_back(s);
        }
    }
 
    void add_mask(pii mask)
    {
        add_mask(1,mask,1,mask.first,1,n);
    }
 
    void add_mask(int node,pii mm, int l, int r, int tl, int tr)
    {
        if(l==tl && r==tr)
            v[node].add(mm);
        else
        {
            int mid = tl+tr>>1;
            if(mid >= l)
                add_mask(2*node,mm,l,min(r,mid),tl,mid);
            if(mid < r)
                add_mask(2*node+1,mm,max(mid+1,l),r,mid+1,tr);
        }
    }
 
    int get_ans(int val)
    {
        int gg = val;
        int cur = n-1+val;
        while(cur > 0)
        {
            val = v[cur].applyMask(val);
            cur/=2;
        }
        return val;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    tree tr = tree(N);
    int n,m,q,i;
    cin>>n>>m;
    pii ma[m];
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        ma[i] = {b,a};
    }
    sort(ma,ma+m);
    cin>>q;
    vector<piii> que;
    for(i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        que.push_back({{b,a},i});
    }
    sort(que.begin(),que.end());
    vector<pii> ans;
    int pointer1=0,pointer2=0;
    for(i=1;i<=n;i++)
    {
        while(pointer1 < m && ma[pointer1].first <= i)
            tr.add_mask({ma[pointer1].second,ma[pointer1].first}),pointer1++;
        while(pointer2 < q && que[pointer2].first.first <= i)
        {
            int ll = tr.get_ans(que[pointer2].first.second);
            ans.push_back({que[pointer2].second,ll});
            pointer2++;
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it: ans)
    {
        cout<<it.second<<endl;
    }
    return 0;
}