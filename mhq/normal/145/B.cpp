    #pragma optimize "-O3"
    #include <bits/stdc++.h>
    using namespace std;
    typedef long double ld;
    typedef long long ll;
    int a4, a7, a47, a74;
    bool can(int a4, int a7, int a47, int a74, int last) {
        if (a4 < 0 || a7 < 0 || a47 < 0 || a74 < 0) return false;
        if (a4 == 0 && a7 == 0) {
            if (a47 != 0 || a74 != 0) return false;
            return true;
        }
        if (abs(a47 - a74) > 1) return false;
        if (last == 4 && a47 < a74) return false;
        if (last == 7 && a74 < a47) return false;
        if (a47 > min((last == 4) + a4, a7)) return false;
        if (a74 > min((last == 7) + a7, a4)) return false;
        if (last == 4 && a7 > 0 && a47 == 0) return false;
        if (last == 7 && a4 > 0 && a74 == 0) return false;
        return true;
      /*  int lim = 0;
        if (last == 4 && a47 == 0) lim = max(lim, a7 + 1);
        if (last == 7 && a74 == 0) lim = max(lim, a4 + 1);
        if (last == 4) {
            if (a47 >= a74) a47 = max(a47 - 1, 0);
        }
        if (last == 7) {
            if (a74 >= a47) a74 = max(a74 - 1, 0);
        }
        return max(lim, max(0, abs(a47 - a74) - 1) + a4 + a7);*/
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //freopen("input.txt", "r", stdin);
        cin >> a4 >> a7 >> a47 >> a74;
        string s = "";
        if (can(a4 - 1, a7, a47, a74, 4)) {
            s += '4';
            a4 -= 1;
        }
        else if (can(a4, a7 - 1, a47, a74, 7)){
            s += '7';
            a7 -= 1;
        }
        else {
            cout << -1;
            return 0;
        }
        for (int i = 0; ; i++) {
            int best = INT_MAX;
            int lst = s.back() - '0';
           // cout << s << endl;
            for (int v : {4, 7}) {
                bool q = can(a4 - (v == 4), a7 - (v == 7), a47 - (lst == 4 && v == 7), a74 - (lst == 7 && v == 4), v);
                if (!q) continue;
             //   if (i == 2 && v == 7) cout << q << " gg3" << endl;
                best = min(best, v);
            }
            assert(best != INT_MAX);
            int v = best;
            a4 -= (v == 4);
            a7 -= (v == 7);
            a47 -= (lst == 4 && v == 7);
            a74 -= (lst == 7 && v == 4);
            s += (char)(v + '0');
            if (a4 == 0 && a7 == 0) {
                cout << s;
                return 0;
            }
        }
        return 0;
    }