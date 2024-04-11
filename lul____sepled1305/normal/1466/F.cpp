/**
    Ithea Myse Valgulious
**/

#include<bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using pll = pair<ll,ll>;
int T;
const int mod = 1e9+7;
set<int> del;

struct dsu
{
    private:
        int n;
        vector<int> par;
        vector<int> siz;
        vector<int> one;
        int total_disjoint_group;
    public:
        dsu(int n)
        {
            this -> n = n;
            for(int i = 0;i<n;i++)
            {
                par.push_back(i);
                siz.push_back(1);
                one.push_back(1e9);
            }
            total_disjoint_group = n;
        }

        int find_par(int a)
        {
            if(par[a]!=a)
                a = find_par(par[a]);
            return par[a];
        }

        bool add_one(int a,int val)
        {
            a = find_par(a);
            if(one[a] != 1e9)
                return false;
            one[a] = val;
            return true;
        }

        bool merge(int a, int b)
        {
            a = find_par(a);
            b = find_par(b);

            if(a==b)
                return false;

            if(siz[a] > siz[b])
                swap(a,b);

            if(one[a] != 1e9 && one[b] != 1e9)
                return false;

            siz[b]+=siz[a];
            par[a] = b;
            if(one[b] < one[a])
            {
                if(one[a] != 1e9)
                    del.insert(one[a]);
            }
            else
            {
                if(one[b] != 1e9)
                    del.insert(one[b]);
                one[b] = one[a];
            }
            return true;
        }

        int getGroup()
        {
            return total_disjoint_group;
        }
};

int mulbytwo(int n)
{
    long long gg = (1LL*n*2)%(mod);
    return (int) gg;
}

void solve()
{
    int n,m,i,j;
    int make = 1;
    cin>>m>>n;
    dsu g = dsu(n+1);
    vector<int> G[m];
    bool get_one[n];
    for(i=0;i<n;i++)
        get_one[i] = false;
    for(i=0;i<m;i++)
    {
        int t;
        cin>>t;
        for(j=0;j<t;j++)
        {
            int r;
            cin>>r;
            G[i].push_back(r);
        }
    }
    vector<int> ans;
    for(i=0;i<m;i++)
    {
        if(G[i].size() == 1)
        {
            int can = G[i][0];
            if(g.add_one(can,i+1))
                ans.push_back(i+1);
            continue;
        }

        int can1 = G[i][0], can2 = G[i][1];
        if(g.find_par(can1) == g.find_par(can2))
            continue;
        else
        {
            if(g.merge(can1,can2))
                ans.push_back(i+1);
        }
    }
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size()-del.size();i++)
    {
        make = mulbytwo(make);
    }
    cout<<make<<' '<<ans.size()-del.size()<<"\n";
    for(auto it: ans)
        if(del.count(it) == 0)
            cout<<it<<' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}