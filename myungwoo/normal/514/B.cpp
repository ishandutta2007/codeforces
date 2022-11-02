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

#define MAXN 2004

int N, X[MAXN], Y[MAXN];
bool V[MAXN];

bool ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
    return (bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=0;i<=N;i++) cin >> X[i] >> Y[i];
    int ans = 0;
    for (int i=1;i<=N;i++) if (!V[i]){
        ans++;
        for (int j=1;j<=N;j++){
            if (!ccw(X[0], Y[0], X[i], Y[i], X[j], Y[j])) V[j] = 1;
        }
    }
    cout << ans << endl;
}