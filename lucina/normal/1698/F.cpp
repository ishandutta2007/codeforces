#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;

/**
    this might be crucial, but we should note that

    1uvwxyz1

    No matter what we did
    the adjacent of "inside", never change

    I.e, u is still connect to 1 v , v is sill connect to u, w
    1|u|v|w|x|y|z|1|    u
    if v never used as reversing end
    then w|v|u must presented in the final sequence

    Then, is it enough to just have the same set of adjacent elements?
*/

int n;
int a[nax];
int b[nax];
vector <pair < int, int>> ans;

void my_reverse(int l, int r) {
    reverse(a + l, a + r + 1);
    ans.emplace_back(l, r);
}

void solve() {
    cin >> n;
    vector <pair <int, int>> adj_a, adj_b;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (i > 1) adj_a.push_back(minmax(a[i], a[i - 1]));
    }

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        if (i > 1) adj_b.push_back(minmax(b[i], b[i - 1]));
    }
    sort(adj_a.begin(), adj_a.end());
    sort(adj_b.begin(), adj_b.end());
    if (a[1] != b[1] || a[n] != b[n] || adj_a != adj_b) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    ans.clear();


    for (int i = 1 ; i < n ; ++ i) {
        if (make_pair(a[i], a[i + 1]) == make_pair(b[i], b[i + 1])) continue;
//        cout << i << endl;
//        for (int j = 1 ; j <= n ; ++ j) {
//            cout << a[j] << ' ';
//        }
//        cout << endl;

        assert(a[i] == b[i]);
        /**
            a b     c  a
            a c
        */
        bool ok = false;
        for (int j = i + 1 ; j < n ; ++ j) {
            if (make_pair(a[j + 1], a[j]) == make_pair(b[i], b[i + 1])) {
                my_reverse(i, j + 1);
                ok = true;
                break;
            }
        }
        if (ok) continue;
        /**
            a b        a c
            a c
        */
        int pos = -1;
        for (int j = i + 1 ; j < n ; ++ j) {
            if (make_pair(a[j], a[j + 1]) == make_pair(b[i], b[i + 1])) {
                pos = j;
                break;
            }
        }
        assert(pos != -1);

        int l = -1, r = -1;
        bool found = false;
        for (l = i + 1; l <= pos  ; ++ l)
        for (r = pos + 1 ; r <= n ; ++ r) {
            if (a[l] == a[r]) {
                found = true;
                goto FOUND;
            }
        }

        FOUND:;
        if (!found) exit(0);

        my_reverse(l, r);

        if (make_pair(a[i], a[i + 1]) == make_pair(b[i], b[i + 1])) continue;

        ok = false;
        for (int j = i + 1 ; j < n ; ++ j) {
            if (make_pair(a[j + 1], a[j]) == make_pair(b[i], b[i + 1])) {
                my_reverse(i, j + 1);
                ok = true;
                break;
            }
        }
        assert(ok);
    }


    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
    /**
        now if the above necessary condition pass, then we can fix element one by one

        a b
        a c

        suppose that next element is not equal, from the assumption
        we can find some 'c' that adjacent to 'a' in the later part
        like            'a' c or c 'a', then we can just
        1) c 'a' case -> just reverse it and c will be in place
        2) 'a' c case?
        the information we know
        a b   ?    a c   ?
        we hope to find "?" that is equal in the latter part?
        we can make "c" back to that side and flip it to adjacent to 'a'
        if such thing always exist?

        a b  . . .  a c
        if
        a b u1 u2 u3 a c v1 v2 v3 v4
        a c
        a b  a  c
        a c x1 x2

        (a, b), (a, b), (a, c)
        there must be something follow c

        a b        a c
        a c  ? a b ?
        a b () () () a c () () ()
        a c () () () a b () () ()

        a b u1 u2 u3 a c v1 v2 v2
        They're all differ, we can't swap anything

        a c v1 v2 v3 a b u1 u2 u3
        since they're all different, this should be only
        valid configuration
        (v3, a) and pair (u3, a) must the the same
        means that (u3 = v3) contradiction
        so, you must be able to find some satisfied the condition

    */
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}