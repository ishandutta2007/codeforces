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

int N, M;
int A[MAXN], B[MAXN];

bool proc(lld t)
{
    int need = 1;
    for (int i=1;i<=N;i++) B[i] = A[i];
    lld now = 0; int last = 0;
    for (int i=1;i<=N;i++) if (B[i]){
        if (t+1 <= i) return 0;
        if (i-last + now > t){
            now = i;
            need++;
        }else now += i-last;
        last = i;
        for (;;){
            if (t - now < B[i]){
                B[i] -= t-now;
                now = i;
                need++;
                
            }else{
                now += B[i];
                B[i] = 0;
            }
            if (need > M) return 0;
            if (!B[i]) break;
        }
    }
    return need <= M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin >> A[i];
    lld s = 0, e = 1e16, ans;
    while (s <= e){
        lld m = (s+e)>>1;
        if (proc(m)) e = m-1, ans = m;
        else s = m+1;
    }
    cout << ans << endl;
}