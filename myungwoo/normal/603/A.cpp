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

int N;
int A[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%1d", A+i);
    int ans = 1;
    for (int i=2;i<=N;i++) if (A[i-1] != A[i]) ans++;
    vector <int> arr; int cnt = 0;
    for (int i=1;i<=N;i++){
        if (i == 1 || A[i-1] != A[i]) cnt = 0;
        cnt++;
        if (i == N || A[i] != A[i+1]) arr.pb(cnt);
    }
//  for (int v: arr) printf("%d ", v); puts("");
    int add = 0;
    for (int v: arr) if (v > 1) add = 1;
    for (int v: arr) if (v > 2) add = 2;
    int mx = arr[0];
    for (int i=1;i<sz(arr);i++){
        if (mx > 1 && arr[i] > 1) add = 2;
        mx = max(mx, arr[i]);
    }
//  printf("%d %d\n", ans, add);
    printf("%d\n", ans+add);
}