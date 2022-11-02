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

int N, K; lld S;
int A[26]; lld F[19]={1};
vector <pli> P, Q;

void dfs(int x, int end, vector <pli> &arr, lld sum, int cnt)
{
    if (sum > S || cnt > K) return;
    if (x > end){ arr.pb(mp(sum, cnt)); return; }
    dfs(x+1, end, arr, sum, cnt);
    dfs(x+1, end, arr, sum+A[x], cnt);
    if (A[x] < 19) dfs(x+1, end, arr, sum+F[A[x]], cnt+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1;i<19;i++) F[i] = F[i-1]*i;
    cin >> N >> K >> S;
    for (int i=1;i<=N;i++) cin >> A[i];
    int m = (1+N)>>1;
    dfs(1, m, P, 0, 0);
    dfs(m+1, N, Q, 0, 0);
    sort(all(P)); sort(all(Q));
    lld ans = 0; int cnt = 0;
    for (int i=0,j=sz(Q),k=sz(Q);i<sz(P);i++){
        while (k > 0 && Q[k-1] > mp(S-P[i].fr, K-P[i].sc)) k--;
        while (j > 0 && Q[j-1] >= mp(S-P[i].fr, 0)) j--;
        ans += k-j;
    }
    cout << ans << endl;
}