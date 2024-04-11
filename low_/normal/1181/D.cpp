#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 500005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m, q;
int cnt[mn];

vector <pii> V;
vector <pii> V2={}; // luu thu tu cua hieu 2 cnt sau khi sort
vector <int> V3; // mang cong don cua V2

int BS(int u){
    int l=0, r=V3.size()-1;
    while (r>l)
    {
        int mid=(l+r)/2;

        if (V3[mid]<u) l=mid+1;
        else r=mid;
    }
    return l;
}

class fenwick{
private:
    int FW[mn];
public:
    fenwick(){
        for (int i=0; i<mn; i++) FW[i]=0;
    }
    void upd(int u){
        while (u<=m){
            FW[u]++;
            u+=(u&(-u));
        }
    }
    int get(int u){
        int ret=0;
        while (u>0){
            ret+=FW[u];
            u-=(u&(-u));
        }
        return ret;
    }
    int bs(int u){
        int l=1, r=m;
        while (r>l){
            int mid=(l+r)/2;
            if (get(mid)<u) l=mid+1;
            else r=mid;
        }
        return l;
    }
} fw1;

vector <pii> queries;
vector <int> inra;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    int u;
    for (int i=1; i<=n; i++) 
    {
        cin>>u;
        cnt[u]++;
    }
    for (int i=1; i<=m; i++) V.push_back({cnt[i], i});

    sort(V.begin(), V.end());
    for (int i=1; i<m; i++) if (V[i].XX>V[i-1].XX)
    {
        V2.push_back({(V[i].XX-V[i-1].XX)*i, i});
    }
    V2.push_back({inf, m});
    V3={n};
    for (pii i: V2) V3.push_back(V3.back()+i.XX);
    // V3.push_back(inf);

    //Before this is ok

    queries.assign(q,{0, 0}), inra.assign(q, 0);

    for (int i=0; i<q; i++){
        cin>>u;
        queries[i]={u, i};
    }
    sort(queries.begin(), queries.end());
    int ptr=0;
    for (int i=0; i<q; i++){
        u=queries[i].XX;
        int c=BS(u);
        int c1=c-1;
        // cerr<<u<<" "<<c1<<endl;
        while (ptr<V2[c1].YY){
            fw1.upd(V[ptr].YY);
            ptr++;
        }
        int k=u-V3[c-1], r=V2[c1].YY;
        k=(k+r-1)%r+1;
        inra[queries[i].YY]=fw1.bs(k);
    }
    for (int i:inra) cout<<i<<endl;

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/