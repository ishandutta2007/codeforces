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

#define MAXN 200005

int N, M;
int B[MAXN];

struct Z{
    int x, w;
} A[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i].x >> A[i].w;
    sort(A+1, A+N+1, [](const Z &a, const Z &b){
        return a.x < b.x;
    });
    B[0] = -2e9;
    for (int i=1;i<=N;i++){
        int p = upper_bound(B+1, B+M+1, A[i].x-A[i].w) - B - 1;
        if (p == M) B[++M] = A[i].x+A[i].w;
        else{
            if (B[p+1] > A[i].x+A[i].w)
                B[p+1] = A[i].x+A[i].w;
        }
    }
    printf("%d\n", M);
}