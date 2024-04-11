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
lld L[MAXN], R[MAXN], A[MAXN], B[MAXN];
lld P[MAXN], Q[MAXN];
int X[MAXN], Y[MAXN];
int ans[MAXN];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;i++){
        scanf("%lld%lld", L+i, R+i);
    }
    for (int i=1;i<=M;i++) scanf("%lld", A+i);
    for (int i=1;i<N;i++){
        P[i] = L[i+1]-R[i], Q[i] = R[i+1]-L[i];
    }
    for (int i=1;i<N;i++) X[i] = i;
    sort(X+1, X+N, [](const int &a, const int &b){
        return P[a] < P[b];
    });
    for (int i=1;i<=M;i++) Y[i] = i;
    sort(Y+1, Y+M+1, [](const int &a, const int &b){
        return A[a] < A[b];
    });
    bool finish = 0;
    priority_queue <pli> que;
    for (int i=1,j=1;i<=M;i++){
        int y = Y[i];
        while (j < N && P[X[j]] <= A[y]){
            int x = X[j];
            que.push(mp(-Q[x], x));
            j++;
        }
        if (j == N) finish = 1;
        if (!que.empty() && -que.top().first < A[y]){ puts("No"); return 0; }
        if (que.empty()) continue;
        auto top = que.top(); que.pop();
        ans[top.sc] = y;
    }
    if (!que.empty() || !finish){ puts("No"); return 0; }
    puts("Yes");
    for (int i=1;i<N;i++) printf("%d ", ans[i]); puts("");
}