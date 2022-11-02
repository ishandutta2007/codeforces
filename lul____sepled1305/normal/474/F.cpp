#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii = pair<int,int>;
const int N = 131072;
const int INF = 1e9+7;

int GCD(int a,int b)
{
    if(a==0 || b==0)
        return max(a,b);
    if(a>b)
        swap(a,b);
    if(b%a==0)
        return a;
    else
        return GCD(b%a,a);
}

struct segmentTree
{
private:
    int n;
    vector<pii> v;
    vector<pii> range;
public:
    segmentTree(int n)
    {
        this -> n = n;
        int i;
        for(i=0;i<2*n;i++)
        {
            v.push_back({0,0});
            range.push_back({0,0});
        }
        range[1]={1,n};
        queue<int> qu;
        qu.push(2);
        qu.push(3);
        while(!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            int siz = range[node/2].se - range[node/2].fi >>1;
            int mid = range[node/2].fi + range[node/2].se >>1;
            if(node%2==0)
                range[node] = {range[node/2].fi,mid};
            if(node%2==1)
                range[node] = {mid+1,range[node/2].se};
            if(siz>=1)
                qu.push(2*node),qu.push(2*node+1);
        }
    }
    void add(int idx, int val)
    {
        int r = n-1+idx;
        v[r].fi = 1;
        v[r].se = val;
        r/=2;

        while(r>0)
        {
            v[r].se = GCD(v[2*r].se,v[2*r+1].se);
            v[r].fi = 0;
            if(v[r].se==v[2*r].se)
                v[r].fi+=v[2*r].fi;
            if(v[r].se==v[2*r+1].se)
                v[r].fi+=v[2*r+1].fi;
            r/=2;
        }
    }
    pii query(int l, int r, int idx)
    {
        if(l>=range[idx].fi && r<=range[idx].se)
        {
            if(l==range[idx].fi && r==range[idx].se)
                return v[idx];
            else
            {
                pii q={0,0},w={0,0};
                int mid = range[idx].fi + range[idx].se >>1;
                if(l<=mid)
                    q = query(l,min(mid,r),2*idx);
                if(r>=mid+1)
                    w = query(max(l,mid+1),r,2*idx+1);
                pii ans;
                ans.se = GCD(q.se,w.se);
                ans.fi = 0;
                if(ans.se==q.se)
                    ans.fi+=q.fi;
                if(ans.se==w.se)
                    ans.fi+=w.fi;
                return ans;
            }
        }
    }
    void print()
    {
        int i;
        for(i=1;i<2*n;i++)
        {
            cout<<i<<" "<<range[i].fi<<" "<<range[i].se<<" "<<v[i].fi<<" "<<v[i].se<<"\n";
        }
    }
};

void solve()
{
    int n,i,j,m,a,b;
    cin>>n;
    segmentTree thisTree(N);
    for(i=0;i<n;i++)
    {
        cin>>j;
        thisTree.add(i+1,j);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        cout<<b-a+1-thisTree.query(a,b,1).fi<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}