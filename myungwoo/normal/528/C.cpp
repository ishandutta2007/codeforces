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

#define MAXN 100005
#define MAXM 300005

int N, M;
int deg[MAXN], pos[MAXN];
bool V[MAXM];
vector <int> con[MAXN], cone[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=1;i<=M;i++){
        int a, b;
        cin >> a >> b;
        deg[a]++; deg[b]++;
        con[a].pb(b); cone[a].pb(i);
        con[b].pb(a); cone[b].pb(i);
    }
    vector <int> arr;
    for (int i=1;i<=N;i++) if (deg[i] & 1) arr.pb(i);
    for (int i=0;i<sz(arr);i+=2){
        con[arr[i]].pb(arr[i+1]); cone[arr[i]].pb(++M);
        con[arr[i+1]].pb(arr[i]); cone[arr[i+1]].pb(M);
    }
    if (M&1)
        con[1].pb(1), cone[1].pb(++M);
    vector <int> path;
    stack <int> stk;
    stk.push(1);
    while (!stk.empty()){
        int top = stk.top();
        bool sw = 0;
        for (int i=pos[top];i<sz(con[top]);i++){
            int e = cone[top][i], t = con[top][i];
            if (V[e]) continue;
            V[e] = 1;
            stk.push(t);
            pos[top] = i+1;
            sw = 1;
            break;
        }
        if (!sw){
            pos[top] = sz(con[top]);
            path.pb(top);
            stk.pop();
        }
    }
    printf("%d\n", M);
    for (int i=1;i<sz(path);i++){
        if (i&1) printf("%d %d\n", path[i-1], path[i]);
        else printf("%d %d\n", path[i], path[i-1]);
    }
}