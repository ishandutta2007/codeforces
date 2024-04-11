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

int N;
int A[MAXN], B[MAXN], C[MAXN];
int bit[MAXN];

void upd(int n, int v)
{
    for (n++;n<=N;n+=(n&-n)) bit[n] += v;
}

int read(int n)
{
    int ret = 0;
    for (n++;n;n-=(n&-n)) ret += bit[n];
    return ret;
}

void proc(int arr[MAXN])
{
    for (int i=0;i<N;i++) upd(i, 1);
    for (int i=0;i<N;i++){
        C[N-i-1] += read(arr[i])-1;
        upd(arr[i], -1);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d", A+i);
    for (int i=0;i<N;i++) scanf("%d", B+i);
    proc(A); proc(B);
    for (int i=1;i<N;i++){
        C[i+1] += C[i] / (i+1);
        C[i] %= i+1;
    }
    for (int i=0;i<N;i++) upd(i, 1);
    for (int i=0;i<N;i++){
        int s = 0, e = N-1, t = -1;
        while (s <= e){
            int m = (s+e) >> 1;
            if (read(m)-1 >= C[N-i-1]) e = m-1, t = m;
            else s = m+1;
        }
        printf("%d ", t); upd(t, -1);
    }
    puts("");
}