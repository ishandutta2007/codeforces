#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;
typedef pair<vector<int>, vector<int>> pvv;

int N, ans;
vector <int> A, B;
set <pvv> V;

void dfs(vector <int> a, vector <int> b)
{
    if (a.empty()){
        printf("%d 2\n", ans);
        return;
    }
    if (b.empty()){
        printf("%d 1\n", ans);
        return;
    }
    if (V.count(mp(a, b))){
        puts("-1");
        return;
    }
    V.insert(mp(a, b));
    ans++;
    int x = a.front(); a.erase(a.begin());
    int y = b.front(); b.erase(b.begin());
    if (x > y){
        a.pb(y); a.pb(x);
    }else{
        b.pb(x); b.pb(y);
    }
    dfs(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int sz;
    cin >> N >> sz;
    for (int i=sz;i--;){
        int v; cin >> v;
        A.pb(v);
    }
    cin >> sz;
    for (int i=sz;i--;){
        int v; cin >> v;
        B.pb(v);
    }
    dfs(A, B);
}