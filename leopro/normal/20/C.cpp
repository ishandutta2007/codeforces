// not my code: https://codeforces.com/blog/entry/98954
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<long long,long long> pll;
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define PB push_back
#define sz(a) (int)((a).size())
void show_(int x){cerr<<x;}
void show_(double x){cerr<<x;}
void show_(float x){cerr<<x;}
void show_(long long x){cerr<<x;}
void show_(char x){cerr<<x;}
void show_(string x){cerr<<x;}
void show_(bool x){cerr<<(x?'T':'F');}
template<class T,class V> void show_(pair<T,V> p) { cerr<<"{ "; show_(p.F); cerr<<", "; show_(p.S); cerr<<" }"; }
void show_(vector<int> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<char> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<bool> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<float> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<double> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<long long> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
void show_(vector<string> v){ cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
template<class T,class V> void show_(vector<pair<T,V>> v) { cerr << "[ "; for (auto x : v) { show_(x); cerr << ", "; } cerr << " ]"; }
template<class T> void show_(vector<vector<T>> x){cerr<<'\n';for(vector<T> i:x){cerr<<"\t[ ";for(T j : i){show_(j);cerr<<", ";}cerr<<"]\n";}}
void fast()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("dbg.txt", "w", stderr);
    #define debug(x) if(true) cerr<<#x<<" = "; show_(x); cerr<<"\n";
    #else
    #define debug(x)
    #endif
}
long long MOD = 1000000007;
double PI = 3.1415926535;
long long INF = LLONG_MAX;
int __=1;
class my_comp
{
    public:
        int operator()(const pair<ll,int>& a,const pair<ll,int>& b) const
        {
            if(a.F==b.F) return a.S<b.S;
            return a.F>b.F;
        }
};
int main()
{
    fast();
    // cin>>__;
    for(int _=1;_<=__;_++)
    {
        ll n,m;
        cin>>n>>m;
        set<pair<int,int>> st;
        map<pair<int,int>,int> edges;
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            if(a==b) continue;
            if(a>b) swap(a,b);
            if(st.find({a,b})==st.end())
            {
                st.insert({a,b});
                edges[{a,b}] = w;
            }
            else
            {
                edges[{a,b}] = min(edges[{a,b}],w);
            }
        }
        vector<vector<pair<int,int>>> graph(n + 1,vector<pair<int,int>>());
        for (auto x : edges)
        {
            graph[x.F.F].PB({ x.F.S,x.S });
            graph[x.F.S].PB({ x.F.F,x.S });
        }
        vll dist(n + 1,INF);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,my_comp> pq;
        pq.push({ 0,1 });
        dist[1] = 0;
        vll hop(n+1,0);
        vector<bool> visited(n+1,false);
        while (sz(pq))
        {
            pair<ll,int> temp = pq.top();
            pq.pop();
            int node = temp.S;
            ll curd = temp.F;
            debug(node);
            debug(curd);
            if(visited[node]) continue;
            visited[node] = true;
            for (auto adj : graph[node])
            {
                if (curd + adj.S < dist[adj.F])
                {
                    pq.push({ curd + adj.S,adj.F });
                    dist[adj.F] = curd + adj.S;
                    hop[adj.F] = node;
                }
            }
        }
        debug(dist);
        if (dist[n] == INF) dist[n] = -1;
        if(-1==dist[n])
        {
            cout<<-1<<"\n";
        }
        else
        {
            stack<int> st2;
            st2.push(n);
            while(st2.top()!=1) st2.push(hop[st2.top()]);
            while(sz(st2))
            {
                cout<<st2.top()<<" ";
                st2.pop();
            }
            cout<<"\n";
        }

    }
    return 0;
}