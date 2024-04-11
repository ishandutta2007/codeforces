#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef pair<int, int> pii;

int N, cnt_1, cnt_2;
int A[MAXN], idx_1[MAXN], idx_2[MAXN], sum_1[MAXN], sum_2[MAXN];

int calc(int t)
{
    int win_1 = 0, win_2 = 0;
    for (int i=0;i<N;){
        int x_1 = sum_1[i]+t > cnt_1 ? 1e9 : idx_1[sum_1[i]+t];
        int x_2 = sum_2[i]+t > cnt_2 ? 1e9 : idx_2[sum_2[i]+t];
        if (x_1 == x_2) return 0;
        if (x_1 < x_2){
            win_1++;
            i = x_1;
        }else{
            win_2++;
            i = x_2;
        }
    }
    if (A[N] == 1 && win_1 > win_2) return win_1;
    if (A[N] == 2 && win_2 > win_1) return win_2;
    return 0;
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    for (int i=1;i<=N;i++){
        if (A[i] == 1){
            idx_1[++cnt_1] = i;
        }else{
            idx_2[++cnt_2] = i;
        }
        sum_1[i] = cnt_1;
        sum_2[i] = cnt_2;
    }
    vector <pii> ans;
    for (int t=1;t<=N;t++){
        int s = calc(t);
        if (!s) continue;
        ans.emplace_back(s, t);
    }
    sort(all(ans));
    printf("%d\n", sz(ans));
    for (auto &p: ans) printf("%d %d\n", p.first, p.second);
}