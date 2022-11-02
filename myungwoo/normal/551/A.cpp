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

int N, A[2002], B[2002];
map <int, int> rnk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i], B[i] = A[i];
    sort(B+1, B+N+1, greater<int>());
    for (int i=N;i;i--) rnk[B[i]] = i;
    for (int i=1;i<=N;i++) printf("%d ", rnk[A[i]]); puts("");
}