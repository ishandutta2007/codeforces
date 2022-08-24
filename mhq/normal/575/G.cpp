#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=3e5;
vector<pair<int,int> > ed[maxn];
int ans[maxn],ct[maxn];
int o[maxn],hh[maxn],dg[maxn],b[maxn],mar[maxn],cl[maxn];
int sz;
int n,x,m,y,z;
pair<pair<int,int>,pair<int,int> > d[maxn];
void dfs(int x, int y) {
    sz++;
    b[sz]=y;
    o[sz]=x;
    cl[sz]=0;
    mar[x]=1;
    for (int i=0;i<ed[x].size();i++) {
        int to=ed[x][i].first;
        if (ed[x][i].second!=0) continue;
        if (mar[to]==1) continue;
        dfs(to,sz);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        cin >> x >> y >> z;
        x++;
        y++;
        ed[x].push_back(make_pair(y,z));
        ed[y].push_back(make_pair(x,z));
    }
    dfs(n,0);
    int l=1;
    int v=0;
    int kcl=0;
    while (l<=sz) {
        int x=o[l];
        if (x==1) break;
        for (int i=0;i<ed[x].size();i++) {
            int to=ed[x][i].first;
            int y=ed[x][i].second;
            if (mar[to]==1) continue;
            v++;
            d[v]=make_pair(make_pair(cl[l],y),make_pair(to,l));
        }
        if (l==sz) {
            sort(d+1,d+v+1);
            d[0].first.first=-1;
            for (int i=1;i<=v;i++) {
                if (d[i].first!=d[i-1].first) kcl++;
                if (mar[d[i].second.first]==0) {
                    mar[d[i].second.first]=1;
                    sz++;
                    o[sz]=d[i].second.first;
                    b[sz]=d[i].second.second;
                    dg[sz]=d[i].first.second;
                    cl[sz]=kcl;
                }
            }
            v=0;
        }
        l++;
    }
    int p=l;
    int s=0;
    while (p!=0) {
        s++;
        ans[s]=dg[p];
        ct[s]=o[p];
        p=b[p];
    }
    reverse(ans+1,ans+s+1);
    int frst=s;
    for (int i=1;i<=s;i++)
    if (ans[i]!=0) {
        frst=i;
        break;
    }
    for (int i=frst;i<=s;i++) cout << ans[i];
    cout << "\n";
    for (int i=1;i<=n;i++) mar[i]=0;
    int sz=1;
    l=1;
    o[1]=1;
    hh[1]=0;
    b[1]=0;
    while (l<=sz) {
        int x=o[l];
        if (x==n) break;
        int h=hh[l];
        for (int i=0;i<ed[x].size();i++) {
            int v=s-h;
            v=max(v,0);
            if (ed[x][i].second!=ans[v]) continue;
            int to=ed[x][i].first;
            if (mar[to]==1) continue;
            sz++;
            o[sz]=to;
            b[sz]=l;
            mar[to]=1;
            hh[sz]=h+1;
        }
        l++;
    }
    s=0;
    p=l;
    while (p!=0) {
        s++;
        ct[s]=o[p];
        p=b[p];
    }
    cout << s << "\n";
    for (int i=s;i>=1;i--) cout << ct[i]-1 << " ";
    cout << "\n";
    return 0;
}