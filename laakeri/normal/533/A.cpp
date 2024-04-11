#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int inf=1e9+10;

multiset<int> mi;
int h[505050];
vector<int> g[505050];
int am[505050];
int t[505050];
int mif[505050];

int miv=inf;
vector<int> lol;

int hi(int x, multiset<int>&s){
    if (x>=inf){
        x=inf-1;
    }
    auto it=s.upper_bound(x);
    it--;
    return *it;
}

vector<pair<int, int> > cs;

void dfs1(int x, int p){
    t[x]=min(t[p], h[x]);
    cs.push_back({t[x], x});
    for (int nx:g[x]){
        if (nx!=p){
            dfs1(nx, x);
        }
    }
}

void dfs2(int x, int p){
    mif[x]=inf;
    if (am[x]==0){
        mif[x]=t[x];
    }
    for (int nx:g[x]){
        if (nx!=p){
            dfs2(nx, x);
            mif[x]=min(mif[x], mif[nx]);
        }
    }
    //cout<<x<<" "<<mif[x]<<endl;
}

vector<int> na;

int dfs4(int x, int p, int li, int d, vector<int>&has, int tt){
    has.push_back(tt);
    int r=1;
    for (int nx:g[x]){
        if (nx!=p){
            if (h[nx]>t[nx]){
                r&=dfs4(nx, x, li, d, has, min(tt, h[nx]));
            }
            else{
                if (mif[nx]<li){
                    return 0;
                }
            }
        }
    }
    return r;
}

int test(int x, int p, int li, int d){
    vector<int> has;
    if (dfs4(x, p, li, d, has, min(t[p], h[x]+d))){
        if (has.size()>=na.size()){
            sort(has.begin(), has.end());
            int i2=0;
            for (int ha:has){
                if (ha>=na[i2]){
                    i2++;
                }
                if (i2>=(int)na.size()){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void dfs3(int x, int p, int li){
    if (h[x]==t[x]&&h[x]<=li){
        int mii=0;
        int mai=lol.size()-1;
        while (mii<=mai){
            int mid=(mii+mai)/2;
            if (lol[mii]-h[x]>=miv) break;
            if (lol[mid]-h[x]>=0&&test(x, p, li, lol[mid]-h[x])){
                mai=mid-1;
            }
            else{
                mii=mid+1;
            }
        }
        if (mii>=0&&mii<(int)lol.size()){
            miv=min(miv, lol[mii]-h[x]);
        }
    }
    int mm=li;
    if (am[x]==0){
        mm=min(mm, t[x]);
    }
    int mx=0;
    int m2=mm;
    for (int nx:g[x]){
        if (nx!=p){
            if (mif[nx]<mm){
                m2=mm;
                mm=mif[nx];
                mx=nx;
            }
            else if(mif[nx]<m2){
                m2=mif[nx];
            }
        }
    }
    for (int nx:g[x]){
        if (nx!=p){
            if (nx==mx){
                dfs3(nx, x, m2);
            }
            else{
                dfs3(nx, x, mm);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> loll;
    for (int i=1;i<=n;i++){
        cin>>h[i];
        loll.insert(h[i]);
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    loll.insert(0);
    loll.insert(1);
    loll.insert(1e9);
    int k;
    cin>>k;
    for (int i=0;i<k;i++){
        int a;
        cin>>a;
        mi.insert(a);
        loll.insert(a);
    }
    for (int aa:loll){
        lol.push_back(aa);
    }
    for (int i=k;i<n;i++){
        mi.insert(1);
    }
    t[0]=inf;
    dfs1(1, 0);
    sort(cs.begin(), cs.end());
    mi.insert(inf);
    mi.insert(-1);
    for (int i=0;i<n;i++){
        int x=hi(cs[i].F, mi);
        if (x>-1){
            mi.erase(mi.find(x));
            am[cs[i].S]=x;
        }
        //cout<<x<<" "<<cs[i].F<<endl;
    }
    for (int a:mi){
        if (a>-1&&a<inf) na.push_back(a);
    }
    if (na.size()==0){
        cout<<0<<endl;
        return 0;
    }
    dfs2(1, 0);
    dfs3(1, 0, inf);
    if (miv<inf){
        cout<<miv<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}