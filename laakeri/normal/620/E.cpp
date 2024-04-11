#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1<<20;
ll st[2*N];
int lz[2*N];
ll lv[2*N];

void setv(int, int, int, int, int, ll);

void golazy(int i, int stl, int str){
    if (lz[i]){
        int m=(stl+str)/2;
        setv(i*2, stl, m, stl, m, lv[i]);
        setv(i*2+1, m+1, str, m+1, str, lv[i]);
        lz[i]=0;
        lv[i]=0;
    }
}

void setv(int i, int stl, int str, int l, int r, ll v){
    if (stl>r||str<l) return;
    if (l<=stl&&str<=r){
        st[i]=v;
        lv[i]=v;
        lz[i]=1;
    }
    else{
        golazy(i, stl, str);
        int m=(stl+str)/2;
        setv(i*2, stl, m, l, r, v);
        setv(i*2+1, m+1, str, l, r, v);
        st[i]=st[i*2]|st[i*2+1];
    }
}

ll getv(int i, int stl, int str, int l, int r){
    if (stl>r||str<l) return 0;
    if (l<=stl&&str<=r){
        return st[i];
    }
    else{
        golazy(i, stl, str);
        ll re=0;
        int m=(stl+str)/2;
        re|=getv(i*2, stl, m, l, r);
        re|=getv(i*2+1, m+1, str, l, r);
        st[i]=st[i*2]|st[i*2+1];
        return re;
    }
}

int sta[N];
int stb[N];
ll ac[N];
vector<int> g[N];

int i2=0;

void dfs(int x, int p){
    sta[x]=i2++;
    for (int nx:g[x]){
        if (nx!=p){
            dfs(nx, x);
        }
    }
    stb[x]=i2++;
    setv(1, 0, N-1, sta[x], sta[x], (1ll<<ac[x]));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>ac[i];
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    for (int i=0;i<m;i++){
        int t;
        cin>>t;
        if (t==1){
            int v;
            ll c;
            cin>>v>>c;
            setv(1, 0, N-1, sta[v], stb[v], (1ll<<c));
        }
        if (t==2){
            int v;
            cin>>v;
            ll vv=getv(1, 0, N-1, sta[v], stb[v]);
            int vvv=0;
            for (ll ii=0;ii<62;ii++){
                if (((1ll<<ii)&vv)>0){
                    vvv++;
                }
            }
            cout<<vvv<<'\n';
        }
    }
}