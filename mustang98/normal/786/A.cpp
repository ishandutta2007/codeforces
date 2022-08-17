#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 7111, inf = 1000111222;

int x[max_n][2];
int k[2];

int ans[max_n][2];
int cnt[max_n][2];
bool vis[max_n][2];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> k[0];
    for (int i = 0; i < k[0]; ++i) {
        scanf("%d", &x[i][0]);
    }

    cin >> k[1];
    for (int i = 0; i < k[1]; ++i) {
        scanf("%d", &x[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        ans[i][0] = -1;
        ans[i][1] = -1;
    }

    queue<pair<int, int> > q; //pos
    ans[0][0] = 0;
    ans[0][1] = 0;
    q.push(mp(0, 0));
    q.push(mp(0, 1));
    while (!q.empty()) {
        int pos = q.front().F;
        int pl = q.front().S;
        int pl2 = pl == 1 ? 0 : 1;
        q.pop();
        if (ans[pos][pl] == 0) {
            for (int i = 0; i < k[pl2]; ++i) {
                int curx = x[i][pl2];
                int last = pos - curx;
                //cout << last << ' ' << pl2 << endl;
                if (last < 0) last += n;
                //cout << ans[last][pl2] << endl;
                if (ans[last][pl2] == -1) {
                    ans[last][pl2] = 1;
                    q.push(mp(last, pl2));
                }
            }
        } else {
            for (int i = 0; i < k[pl2]; ++i) {
                int curx = x[i][pl2];
                int last = pos - curx;
                if (last < 0) last += n;
                if (ans[last][pl2] == -1) {
                    cnt[last][pl2]++;
                    if (cnt[last][pl2] == k[pl2]) {
                        ans[last][pl2] = 0;
                        q.push(mp(last, pl2));
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (ans[i][0] == 0) {
            printf("Lose ");
        } else if (ans[i][0] == 1) {
            printf("Win ");
        } else {
            printf("Loop ");
        }
    }
    printf("\n");
    for (int i = 1; i < n; ++i) {
        if (ans[i][1] == 0) {
            printf("Lose ");
        } else if (ans[i][1] == 1) {
            printf("Win ");
        } else {
            printf("Loop ");
        }
    }
    return 0;
}