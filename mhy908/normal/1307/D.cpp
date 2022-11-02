#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int n, m, k, ans;
int spe[200010];
vector<int> link[200010];
int dist_st[200010], dist_fin[200010], t;
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool comp(int a, int b){
    return dist_st[a]<dist_st[b];
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=k; i++){
        scanf("%d", &spe[i]);
    }
    for(int i=1; i<=n; i++)dist_st[i]=dist_fin[i]=inf;
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        link[a].pb(b);
        link[b].pb(a);
    }
    pq.push(mp(0, 1));
    while(!pq.empty()){
        int d=pq.top().F, h=pq.top().S;
        pq.pop();
        //printf("dist %d = %d\n", h, dist_st[h]);
        if(dist_st[h]<=d)continue;
        dist_st[h]=d;
        //printf("dist %d = %d\n", h, dist_st[h]);
        for(auto i:link[h]){
            pq.push(mp(d+1, i));
        }
    }
    pq.push(mp(0, n));
    while(!pq.empty()){
        int d=pq.top().F, h=pq.top().S;
        pq.pop();
        if(dist_fin[h]<=d)continue;
        dist_fin[h]=d;
        for(auto i:link[h]){
            pq.push(mp(d+1, i));
        }
    }
    sort(spe+1, spe+k+1, comp);
    int maxx=dist_st[spe[1]];
    for(int i=2; i<=k; i++){
        //printf("try %d\n", maxx+dist_fin[spe[i]]+1);
        ans=max(ans, min(maxx+dist_fin[spe[i]]+1, dist_st[n]));
        maxx=max(maxx, dist_st[spe[i]]);
    }
    printf("%d", ans);
}