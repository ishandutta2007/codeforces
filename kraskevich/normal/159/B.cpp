#include <cstdio>
#include <iostream>
using namespace std;

int cnt1[1000][1000], cnt2[1000][1000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < 1000; ++i)
            for(int j = 0; j < 1000; ++j)
                    cnt1[i][j] = cnt2[i][j] = 0;
    for(int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            ++cnt1[a][b];
    }
    int cntd[1000];
    for(int i = 0; i < 1000; ++i)
            cntd[i] = 0;
    for(int i = 0; i < m; ++i) {
            int  a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            ++cnt2[a][b];
            ++cntd[b];
    }
    int all = 0, good = 0;
    for(int i = 0; i < 1000; ++i) 
            for(int j = 0; j < 1000; ++j) {
                    good += min(cnt1[i][j], cnt2[i][j]);
                    all += min(cnt1[i][j], cntd[j]);
                    cntd[j] -= min(cntd[j], cnt1[i][j]);
            }
    cout << all << " " << good << endl;
    cin >> n;
    return 0;
}