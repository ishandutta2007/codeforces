#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef pair <int, int> pii;

#define MAXN 100005

int N, K;
int A[MAXN], B[MAXN][30];
vector <pii> seg[30], noseg[30];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=K;i++){
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        for (int j=0;j<30;j++){
            if (v & (1 << j)){
                seg[j].pb(mp(a, b));
            }else{
                noseg[j].pb(mp(a, b));
            }
        }
    }
    bool imp = 0;
    for (int i=0;i<30;i++){
        sort(all(seg[i]));
        priority_queue <int> que;
        for (int j=1,k=0;j<=N;j++){
            while (k < sz(seg[i]) && seg[i][k].first <= j){
                que.push(-seg[i][k].second);
                k++;
            }
            while (!que.empty() && -que.top() < j) que.pop();
            if (!que.empty()) A[j] |= (1 << i), B[j][i] = 1;
        }
        for (int j=1;j<=N;j++) B[j][i] += B[j-1][i];
        for (auto &p: noseg[i]){
            int a = p.first, b = p.second;
            if (B[b][i] - B[a-1][i] == b-a+1) imp = 1;
        }
    }
    if (imp){ puts("NO"); return 0; }
    puts("YES");
    for (int i=1;i<=N;i++) printf("%d ", A[i]); puts("");
}