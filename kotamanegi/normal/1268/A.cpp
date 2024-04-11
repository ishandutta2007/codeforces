/*
#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
#define int ll
ll seg_tree[seg_size * 4];
ll seg_find(int now, int n_l, int n_r, int w_l, int w_r) {
    if (w_l <= n_l && n_r <= w_r) {
        return seg_tree[now];
    }
    if (w_r <= n_l || n_r <= w_l) {
        return 0;
    }
    return seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r) + seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
}
void seg_set(int now) {
    seg_tree[now] = seg_tree[now * 2] + seg_tree[now * 2 + 1];
    if (now != 1) seg_set(now / 2);
    return;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(mp(a, i));
    }
    sort(ALL(inputs));
    vector<ll> answers;
    ll now_ans = 0;
    REP(i, inputs.size()) {
        now_ans += seg_find(1, 0, seg_size, inputs[i].second, seg_size);
        seg_tree[(seg_size + inputs[i].second)]++;
        seg_set((seg_size + inputs[i].second) / 2);
        answers.push_back(now_ans);
    }
    REP(i, answers.size()) {
        cout << answers[i] << " ";
    }
    cout << endl;
}

#undef int
int main() {
    init();
    solve();
}
*/
#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL

#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ok = 1;
    for (int i = 0; i < n - k; ++i) {
        if (s[i] != s[i + k]) {
            ok = 0;
        }
    }
    string ans = s;
    REP(i, k) {
        for (int q = i; q < ans.length(); q += k) {
            ans[q] = s[i];
        }
    }
    for (int i = 0; i < ans.length(); ++i) {
        if (ans[i] > s[i]) {
            break;
        }
        else if (ans[i] < s[i]) {
            for (int q = k - 1; q >= 0; --q) {
                if (s[q] != '9') {
                    s[q]++;
                    for (int t = q; t < ans.length(); t += k) {
                        ans[t] = s[q];
                    }
                    for (int t = q + 1; t < k; ++t) {
                        for (int j = t; j < ans.length(); j += k) {
                            ans[j] = '0';
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}
int main() {
    init();
    solve();
}