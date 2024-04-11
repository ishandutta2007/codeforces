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

#define MAXM 100005

int N, M;
int P[MAXM], H[MAXM];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=M;i++) scanf("%d%d", P+i, H+i);
    int ans = H[1]+P[1]-1; bool imp = 0;
    for (int i=1;i<M;i++){
        int dx = P[i+1] - P[i];
        int dy = H[i+1] - H[i];
        if (dx < abs(dy)){ imp = 1; break; }
        int s = 1, e = 1e8, t = 0;
        while (s <= e){
            int m = (s+e)>>1;
            if (P[i]+m > P[i+1]){ e = m-1; continue; }
            int ndx = P[i+1] - P[i] - m;
            int ndy = H[i+1] - (H[i]+m);
            if (ndx < abs(ndy)) e = m-1;
            else s = m+1, t = m;
        }
        put_max(ans, H[i]+t);
    }
    if (imp){ puts("IMPOSSIBLE"); return 0; }
    put_max(ans, H[M] + (N - P[M]));
    cout << ans << endl;
}