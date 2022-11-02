#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n, par[250010], num[250010], sp[250010][30], d[250010], re;
pii eul[250010];
vector<pil> link[250010];
LL dp[250010][2], pedge[250010], sum2[250010];
bool ch[250010];

int lca(int a, int b){
    if(d[a]<d[b])swap(a, b);
    for(int i=20; i>=0; i--){
        if(d[a]-(1<<i)>=d[b])a=sp[a][i];
    }
    if(a==b)return a;
    for(int i=20; i>=0; i--){
        if(sp[a][i]!=sp[b][i])a=sp[a][i], b=sp[b][i];
    }
    return sp[a][0];
}

pli operator+(pli a, pli b){return mp(a.F+b.F, a.S+b.S);}
struct DYNAMIC_MINCOWSKI{
    vector<pli> vc, seg;
    void init(){
        seg.resize(vc.size()*4);
        svec(vc);
        for(int i=0; i<vc.size(); i++)num[vc[i].S]=i;
    }
    void upd(int point, int s, int e, int num){
        if(s==e){
            seg[point]=mp(vc[s].F, 1);
            return;
        }
        if(num<=(s+e)/2)upd(point*2, s, (s+e)/2, num);
        else upd(point*2+1, (s+e)/2+1, e, num);
        seg[point]=seg[point*2]+seg[point*2+1];
    }
    void upd(int num){upd(1, 0, vc.size()-1, num);}
    pli query(int point, int s, int e, int a, int b, int cut){
        if(e<a||s>b||cut<=0)return mp(0ll, 0);
        if(a<=s&&e<=b&&seg[point].S<=cut)return seg[point];
        pli tmp=query(point*2, s, (s+e)/2, a, b, cut);
        pli tmp2=query(point*2+1, (s+e)/2+1, e, a, b, cut-tmp.S);
        return tmp+tmp2;
    }
    pli query(int a, int b, int cut){return query(1, 0, vc.size()-1, a, b, cut);}
    int lb(LL c){
        return lower_bound(all(vc), mp(c, INF))-vc.begin();
    }
}mink[250010];

vector<int> deg[250010];

void pdfs(int num, int p){
    d[num]=d[p]+1;
    par[num]=sp[num][0]=p;
    eul[num].F=++re;
    for(auto i:link[num]){
        if(i.F==p)continue;
        mink[num].vc.eb(-i.S, i.F);
        pedge[i.F]=i.S;
        pdfs(i.F, num);
    }
    eul[num].S=re;
    mink[num].init();
}

vector<int> prs[250010];

void dfs(int now, int k){
    //printf("DFS %d\n", now);
    LL sum=sum2[now];
    vector<LL> vc;
    for(auto i:prs[now]){
        dfs(i, k);
        if(d[i]-d[now]==1&&ch[i]==false){
            sum+=dp[i][1];
            if(dp[i][0]<dp[i][1])vc.eb(dp[i][0]-dp[i][1]);
        }
        else sum+=min(dp[i][0], dp[i][1]);
    }
    svec(vc);
    dp[now][0]=sum;
    dp[now][1]=sum+pedge[now];
    //printf("DFS2 %d\n", now);

    pli tmp=mp(0ll, 0);
    int cut=0;
    for(auto i:vc){
        int ncut=mink[now].lb(i);
        tmp=tmp+mink[now].query(cut, ncut-1, k-1-tmp.S);
        cut=ncut;
        if(tmp.S>=k-1)break;
        tmp.S++;
        tmp.F+=i;
    }
    tmp=tmp+mink[now].query(cut, INF, k-1-tmp.S);
    dp[now][0]+=tmp.F;

    tmp=mp(0ll, 0);
    cut=0;
    for(auto i:vc){
        int ncut=mink[now].lb(i);
        tmp=tmp+mink[now].query(cut, ncut-1, k-tmp.S);
        cut=ncut;
        if(tmp.S>=k)break;
        tmp.S++;
        tmp.F+=i;
    }
    //printf("DFS2 %d\n", now);
    tmp=tmp+mink[now].query(cut, INF, k-tmp.S);
    dp[now][1]+=tmp.F;
}

set<int> s;
bool cmp(int a, int b){return eul[a]<eul[b];}

vector<LL> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W){
    n=N;
    vector<LL> ret(n);
    for(int i=0; i<n-1; i++){
        link[U[i]+1].eb(V[i]+1, W[i]);
        link[V[i]+1].eb(U[i]+1, W[i]);
    }

    for(int i=1; i<=n; i++){
        deg[link[i].size()].eb(i);
        s.insert(i);
    }
    pdfs(1, 0);
    for(int j=1; j<=20; j++){
        for(int i=1; i<=n; i++)sp[i][j]=sp[sp[i][j-1]][j-1];
    }

    for(int i=0; i<n; i++){
        for(auto j:deg[i]){
            s.erase(j);
            ch[j]=true;
            if(!par[j])continue;
            sum2[par[j]]+=pedge[j];
            mink[par[j]].upd(num[j]);
        }

        vector<int> vc, stk;
        for(auto j:s)vc.eb(j);
        for(int j=1; j<s.size(); j++)vc.eb(lca(vc[j-1], vc[j]));
        vc.eb(1);
        sort(all(vc), cmp); press(vc);

        stk.eb(vc[0]);
        for(int j=1; j<vc.size(); j++){
            while(1){
                if(eul[stk.back()].S>=eul[vc[j]].F)break;
                stk.pop_back();
            }
            prs[stk.back()].eb(vc[j]);
            stk.eb(vc[j]);
        }
        dfs(1, i);
        ret[i]=dp[1][1];
        for(auto j:vc)prs[j].clear();
    }

    return ret;
}

int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
    U[i]--; V[i]--;
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}