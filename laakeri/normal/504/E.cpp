#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second

using namespace std;

typedef long long ll;

const ll m1=799999969;
const ll k1=599999929;
struct h{
    ll v;
    int l;
};
ll pot[300011];
ll minv[300011];

ll modpot(ll x, ll p, ll mod){
    if (p==0) return 1;
    if (p%2==1) return (x*modpot(x, p-1, mod))%mod;
    x=modpot(x, p/2, mod);
    return (x*x)%mod;
}

h add(h h1, h h2){
    h nh;
    nh.v=h2.v*pot[h1.l];
    nh.v%=m1;
    nh.v+=h1.v;
    nh.v%=m1;
    nh.l=h1.l+h2.l;
    return nh;
}
h subsa(h h1, h h2){//h2-h1
    if (h1.l>=h2.l) return {0, 0};
    h nh=h2;
    nh.v+=m1-h1.v;
    nh.v%=m1;
    nh.v*=minv[h1.l];
    nh.v%=m1;
    nh.l-=h1.l;
    return nh;
}
h subse(h h1, h h2){//h2-h1
    if (h1.l>=h2.l) return {0, 0};
    h nh=h2;
    nh.v+=m1-(h1.v*pot[h2.l-h1.l])%m1;
    nh.v%=m1;
    nh.l-=h1.l;
    return nh;
}

string nc;
vector<int> g[300001];
int apd[300001];
int dd[300001];
int pp[300001];

const int N2=1<<20;

pair<int, int> mist[2*N2];
int lcai[300001];

void setmin(int i, pair<int, int> v){
    i+=N2;
    mist[i]=v;
    for (i=i/2;i;i/=2){
        mist[i]=mist[i*2];
        if (mist[i].F==0||(mist[i*2+1].F>0&&mist[i*2+1].F<mist[i].F)){
            mist[i]=mist[i*2+1];
        }
    }
}
int lca(int a, int b){
    a=lcai[a]+N2;
    b=lcai[b]+N2;
    if (b<a) swap(a, b);
    pair<int, int> mi={9999999, 9999999};
    while (a<=b){
        if (a%2){
            mi=min(mi, mist[a++]);
        }
        if (!(b%2)){
            mi=min(mi, mist[b--]);
        }
        a/=2;
        b/=2;
    }
    return mi.S;
}

int git=0;
void dfs1(int x, int p, int d){
    pp[x]=p;
    lcai[x]=git;
    setmin(git, {d, x});
    git++;
    apd[x]=d;
    for (int nx:g[x]){
        if (nx!=p){
            dfs1(nx, x, d+1);
            setmin(git, {d, x});
            git++;
            apd[x]=max(apd[x], apd[nx]);
        }
    }
}

h nh[300001];
h rnh[300001];

void dfs2(int x, int p, int d){
    dd[x]=d;
    nh[x]=add(nh[p], {nc[x-1]-'a'+1, 1});
    rnh[x]=add({nc[x-1]-'a'+1, 1}, rnh[p]);
    for (int nx:g[x]){
        if (nx!=p){
            dfs2(nx, x, d+1);
        }
    }
}

int lpc[300001];
int lpci[300001];
vector<int> pns[300001];

int gci=1;

int ac[300001][20];
int loga[300011];
int logam[300011];

void dfs3(int x, int p, int ci){
    ac[x][0]=pp[x];
    for (int i=1;i<20;i++){
        ac[x][i]=ac[ac[x][i-1]][i-1];
    }
    if (ci==0){
        ci=gci++;
    }
    lpci[x]=pns[ci].size();
    pns[ci].push_back(x);
    lpc[x]=ci;
    int md=0;
    int mdi=0;
    for (int nx:g[x]){
        if (nx!=p){
            if (apd[nx]>md){
                md=apd[nx];
                mdi=nx;
            }
        }
    }
    if (mdi) dfs3(mdi, x, ci);
    for (int nx:g[x]){
        if (nx!=p&&nx!=mdi){
            dfs3(nx, x, 0);
        }
    }
}

int ktha(int x, int k){
    if (x==0) return 0;
    if (lpci[x]+k<(int)pns[lpc[x]].size()){
        return pns[lpc[x]][lpci[x]+k];
    }
    else{
        return ktha(ac[x][loga[k]], logam[k]);
    }
}

ll geth(int a, int b, int lc, int le){
    if (dd[a]-dd[lc]+1>=le){
        return subse(rnh[ktha(a, le)], rnh[a]).v;
    }
    else{
        h r=subse(rnh[lc], rnh[a]);
        le-=dd[a]-dd[lc];
        int lol=ktha(b, dd[b]-dd[lc]-le+1);
        r=add(r, subsa(nh[pp[lc]], nh[lol]));
        return r.v;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pot[0]=1;
    minv[0]=1;
    for (int i=1;i<=300010;i++){
        pot[i]=pot[i-1]*k1;
        pot[i]%=m1;
        minv[i]=modpot(pot[i], m1-2, m1);
        for (int ii=0;ii<20;ii++){
            if ((1<<ii)<=i){
                loga[i]=ii;
                logam[i]=i-(1<<ii);
            }
        }
    }
    int n;
    cin>>n;
    cin>>nc;
    for (int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    nh[0]={0, 0};
    rnh[0]={0, 0};
    dfs1(1, 0, 1);
    dfs2(1, 0, 0);
    dfs3(1, 0, 0);
    for (int i=1;i<gci;i++){
        reverse(pns[i].begin(), pns[i].end());
        for (int ii=0;ii<(int)pns[i].size();ii++){
            lpci[pns[i][ii]]=ii;
        }
        int x=pp[pns[i][pns[i].size()-1]];
        int lol=pns[i].size();
        while (x!=0&&lol>0){
            pns[i].push_back(x);
            x=pp[x];
            lol--;
        }
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int l1=lca(a, b);
        int l2=lca(c, d);
        int mi=1;
        int ma=min(dd[a]+dd[b]-2*dd[l1], dd[c]+dd[d]-2*dd[l2])+1;
        while (mi<=ma){
            int m=(mi+ma)/2;
            if (geth(a, b, l1, m)==geth(c, d, l2, m)){
                mi=m+1;
            }
            else{
                ma=m-1;
            }
        }
        cout<<ma<<'\n';
    }
}