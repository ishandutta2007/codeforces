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

#define MAXN 1000006

int N, D[MAXN], F[MAXN];

bool check(int n)
{
    for (;n;n/=10) if (n%10 > 1) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector <int> nums;
    for (int i=1;i<=N;i++) if (check(i)) nums.pb(i);
    for (int i=1;i<=N;i++) D[i] = 2e9;
    for (int i=0;i<N;i++) if (D[i] < 2e9){
        for (int n: nums){
            if (i+n > N) break;
            if (D[i+n] > D[i]+1)
                D[i+n] = D[i]+1, F[i+n] = i;
        }
    }
    vector <int> ans;
    for (int i=N;i;i=F[i]) ans.pb(i-F[i]);
    printf("%d\n", sz(ans));
    for (int t: ans) printf("%d ", t); puts("");
}