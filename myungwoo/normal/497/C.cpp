#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef pair<int, int> pii;

int N, M;
int ans[MAXN];

struct PART{
    int a, b, idx;
} A[MAXN];

struct ACTOR{
    int a, b, c, idx;
} B[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d%d", &A[i].a, &A[i].b), A[i].idx = i;
    scanf("%d", &M);
    for (int i=1;i<=M;i++) scanf("%d%d%d", &B[i].a, &B[i].b, &B[i].c), B[i].idx = i;
    sort(A+1, A+N+1, [](const PART &a, const PART &b){
        return a.a < b.a;
    });
    sort(B+1, B+M+1, [](const ACTOR &a, const ACTOR &b){
        return a.a < b.a;
    });
    set <pii> S;
    for (int i=1,j=1;i<=N;i++){
        while (j <= M && B[j].a <= A[i].a){
            S.insert(pii(B[j].b, j));
            j++;
        }
        for (;;){
            auto it = S.lower_bound(pii(A[i].b, 0));
            if (it == S.end()){ puts("NO"); return 0; }
            if (!B[it->second].c){
                S.erase(it);
                continue;
            }
            ans[A[i].idx] = B[it->second].idx;
            B[it->second].c--;
            break;
        }
    }
    puts("YES");
    for (int i=1;i<=N;i++) printf("%d ", ans[i]); puts("");
}