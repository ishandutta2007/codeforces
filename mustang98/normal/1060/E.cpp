#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> l[max_n];
vector<int> v[max_n];
ll suml_ch[max_n];
ll suml_nech[max_n];
ll cnt_ch[max_n];
ll cnt_nech[max_n];
ll ans = 0;
void dfs(int cur, int pr) {
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        dfs(to, cur);
    }
    if (v[cur].size() == 1 && pr != -1) {
        l[cur].PB(1);
        cnt_ch[cur] = 1;
        return;
    }
    int mn = -1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;

        l[to].PB(1);
        swap(cnt_ch[to], cnt_nech[to]);
        swap(suml_ch[to], suml_nech[to]);
        suml_ch[to] += cnt_ch[to];
        suml_nech[to] += cnt_nech[to];
        cnt_ch[to]++;

        if (mn == -1 || l[to].size() > l[mn].size()) {
            mn = to;
        }

        /*ans += (suml_ch[to] / 2);
        ans += (suml_nech[to] - cnt_nech[to]) / 2 + cnt_nech[to];
        */
        //cout << to << ' ' << suml_ch[to] << ' ' << suml_nech[to] << ' ' << cnt_ch[to] << ' ' << cnt_nech[to] << endl;
       // for (int a : l[to]) {
       //     cout << a << ' ' ;
       // }
       // cout << endl;
    }

    ans += (suml_ch[mn] / 2);
    ans += (suml_nech[mn] - cnt_nech[mn]) / 2 + cnt_nech[mn];
   // cout << ans << endl;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == mn || to == pr) continue;
        vector<int>& v1 = l[to];
        vector<int>& vc = l[mn];
        for (int j = v1.size() - 1; j >= 0; --j) {
            int cur_l = (v1.size() - 1 - j);
            if (cur_l == 0) continue;
            if (cur_l % 2 == 0) {
                ans += 1LL * v1[j] * (suml_ch[mn] / 2 + 1LL * cnt_ch[mn] * cur_l / 2);
                ans += 1LL * v1[j] * ((suml_nech[mn] - cnt_nech[mn]) / 2 + cnt_nech[mn] + 1LL * cnt_nech[mn] * cur_l / 2);
            } else {
                //cout << "!!!" << i << ' ' << suml_ch[mn] << ' ' << suml_nech[mn] << ' ' << cnt_ch[mn] << ' ' << cnt_nech[mn] << endl;
                ans += 1LL * v1[j] * (suml_ch[mn] / 2 + 1LL * cnt_ch[mn] * (cur_l + 1) / 2);
                ans += 1LL * v1[j] * ((suml_nech[mn] - cnt_nech[mn]) / 2 + 1LL * cnt_nech[mn] * (cur_l + 1) / 2);
            }
        }
        for (int j = v1.size() - 1; j >= 0; --j) {
            int cur_l = (v1.size() - 1 - j);
            vc[vc.size() - 1 - cur_l] += v1[j];
        }
        vc.back() = 1;
        cnt_ch[mn] += cnt_ch[to] - 1;
        cnt_nech[mn] += cnt_nech[to];
        suml_ch[mn] += suml_ch[to];
        suml_nech[mn] += suml_nech[to];
    }
    l[cur].swap(l[mn]);
    cnt_ch[cur] = cnt_ch[mn];
    cnt_nech[cur] = cnt_nech[mn];
    suml_ch[cur] = suml_ch[mn];
    suml_nech[cur] = suml_nech[mn];
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
       // a = i + 1, b = i + 2;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, -1);
    cout << ans << endl;

    return 0;
}