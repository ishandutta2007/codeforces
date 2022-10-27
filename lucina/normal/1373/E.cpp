#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const string large = "999999999999999999999999999";
const string fail = "#";



string find_smallest (int f) {
    string v;
    while (f > 0) {
        int cur = min(f, 9);
        v.push_back(cur + '0');
        f -= cur;
    }
    reverse(v.begin(), v.end());
    return v;
}

string find_smallest_not9 (int f) {
    if (f == 0) return string();
    int first = min(f, 8);
    f -= 8;
    string res = find_smallest(f);
    res += (first + '0');
    return res;
}


string find_answer (int first, int last) {
    if (last <= first) return fail;
    int dif = last - first;

    int num9 = -1;
    for (int v = 1 ; v <= 15 ; ++ v) {
        if (9 * v - 1 == dif) {
            num9 = v;
            break;
        }
    }

    if (num9 == -1) return fail;
    last -= 9 * num9;

    string fr = find_smallest_not9(last);
    for (int i = 1 ; i <= num9 ; ++ i)
        fr += '9';
    return fr;
}


int get_real_sum (int start, int k) {
    int res = 0;
    for (int i = 0 ; i <= k ; ++ i)
        res += (start + i);
    return res;
}

int cc (int v) {
    return v * (v - 1) / 2;
}

string find_smallest_fix_last_digit (int num, int last_dig) {
    if (num < last_dig) return large;
    num -= last_dig;
    string res = find_smallest(num);
    res += (last_dig + '0');
    return res;
}

void upd_min (string &ans, string v) {
    if (v.size() < ans.size()) {
        ans = v;
    } else if (v.size() == ans.size()) ans = min(ans, v);
}


void solve() {
    int n, k;
    cin >> n >> k;

    string answer = large;

    for (int last_dig = 0 ; last_dig + k <= 9 ; ++ last_dig) {
        for (int first_num = 0 ; first_num <= n ; ++ first_num) {
            if (get_real_sum(first_num, k) == n) {
                string res = find_smallest_fix_last_digit(first_num, last_dig);
                upd_min(answer, res);
            }
        }
    }

    for (int cnt1 = 1 ; cnt1 <= k + 1 ; ++ cnt1) {
        for (int first_num = 1 ; first_num <= n ; ++ first_num) {
            int c = first_num * cnt1;
            c += cc(cnt1);
            int ret = (k + 1 - cnt1);
            int remain = n - c;
            if (remain < 0) break;

            remain += cc(ret);
            if (remain < 0) break;
            if (ret == 0) {
                if (remain) continue;
                upd_min(answer, find_smallest_fix_last_digit(first_num, 0));
                continue;
            } else if (remain % ret) continue;

            int last_num = remain / ret;

            string get = find_answer(first_num, last_num);
            if (get != fail) {
                -- ret;
                get.back() -= ret;
                upd_min(answer, get);
            }
        }
    }

    if (answer == large) {
        cout << -1 << '\n';
    } else cout << answer << '\n';
}

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Sue is best girl in A19.
*/


/**
1
99 1

*/