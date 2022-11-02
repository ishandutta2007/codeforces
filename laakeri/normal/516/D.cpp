#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<pair<int, ll> > g[100001];

ll apl[100001];
ll di[100001];

void dfs1(int x, int p){
    for (auto nx:g[x]){
        if (nx.F!=p){
            dfs1(nx.F, x);
            apl[x]=max(apl[x], apl[nx.F]+nx.S);
        }
    }
}

vector<pair<ll, int> > ns;

void dfs2(int x, int p, ll pl){
    ll b1=pl;
    int b1i=0;
    ll b2=0;
    for (auto nx:g[x]){
        if (nx.F!=p){
            if (apl[nx.F]+nx.S>b1){
                b2=b1;
                b1=apl[nx.F]+nx.S;
                b1i=nx.F;
            }
            else if(apl[nx.F]+nx.S>b2){
                b2=apl[nx.F]+nx.S;
            }
        }
    }
    di[x]=b1;
    for (auto nx:g[x]){
        if (nx.F!=p){
            if (nx.F==b1i){
                dfs2(nx.F, x, b2+nx.S);
            }
            else{
                dfs2(nx.F, x, b1+nx.S);
            }
        }
    }
    //cout<<x<<" "<<di[x]<<endl;
    ns.push_back({di[x], x});
}

const int N=1<<18;
int st[2*N];
void add(int i, int x){
    for (i+=N;i;i/=2){
        st[i]+=x;
    }
}

int sum(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int sta[100001];
int stb[100001];

int git=1;

void dfs3(int x, int p){
    sta[x]=git++;
    for (auto nx:g[x]){
        if (nx.F!=p){
            dfs3(nx.F, x);
        }
    }
    stb[x]=git++;
    //cout<<x<<" "<<sta[x]<<" "<<stb[x]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    sort(ns.rbegin(), ns.rend());
    dfs3(ns[n-1].S, 0);
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        ll l;
        cin>>l;
        for (int ii=0;ii<2*N;ii++){
            st[ii]=0;
        }
        for (int ii=1;ii<=n;ii++){
            add(sta[ii], 1);
        }
        int bk=0;
        int v=0;
        for (int ii=0;ii<n;ii++){
            while (bk<ii&&ns[bk].F-ns[ii].F>l){
                add(sta[ns[bk].S], -1);
                bk++;
            }
            //cout<<bk<<" "<<ii<<" "<<ns[bk].S<<" "<<ns[ii].S<<" "<<ns[ii].F<<" "<<ns[bk].F<<endl;
            v=max(v, sum(sta[ns[ii].S], stb[ns[ii].S]));
        }
        cout<<v<<'\n';
    }
}