#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[] = {0, 0, 10, 10, 10, 0, 0};
int all_max;
int query(int x, int y, int z) {
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    //int foo;
    int foo;
    cin >> foo;
    //cin >> foo;
    //cout << foo << endl;
    return foo;
}
void answer(int x, int y) {
//    if (a[x] != 0 && a[y] != 0) {
//        cout << "FOUND " <<'\n';
//        for (int i = 1 ; i <= 5 ; ++ i)
//            cout << a[i] << ' ';
//        cout << endl;
//    }
    cout << "! " << x << ' ' << y << endl;
    int res;
}

bool is_unique(vector <int> x) {
    return *min_element(x.begin(), x.end()) == *max_element(x.begin(), x.end());
}

void solve() {
    int n;
    cin >> n;
    //n = 5;
    for (int i = 1 ; i <= n ; ++ i) {
        //a[i] = rand() % 10 + 1;
       // cin >> a[i];
    }
    //a[rand() % 5 + 1] = 0;
//    for (int i = 1 ; i <= n ; ++ i)
//        cout << a[i] << ' ';
//    cout << endl;
//
    int x = 1, y = 2, z;
    vector <int> ans1;
    for (z = 3 ; z <= n ; ++ z) {
        int foo = query(x, y, z);
        ans1.push_back(foo);
    }
    int where_max = 3 + max_element(ans1.begin(), ans1.end()) - ans1.begin();
    vector <int> ans2;
    y = where_max;
    int mx = -1, idx = -1;
    for (int z = 2 ; z <= n ; ++ z) {
        if (z == y) continue;
        int foo = query(x, y, z);
        ans2.push_back(foo);
        if (foo > mx) {
            mx = foo;
            idx = z;
        }
    }
    if (is_unique(ans2)) {
      //  cout << "HERE\n";
        answer(x, y);
        return;
    }

    if (is_unique(ans1) && *ans1.begin() > *min_element(ans2.begin(), ans2.end())) {
        answer(1, 2);
        return;
    }
    where_max = idx;

    int cnt = 0;
//    if (where_max == 1 || where_max == 2) {
//            y = 3 - where_max;
////        if (where_max != 3 - where_max) y = 3 - where_max;
//    }
    answer(where_max, y);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    srand(uint64_t(new char()));
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Alphacode!?
*/