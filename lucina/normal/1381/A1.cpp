#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
char s[nax];

void solve() {
    cin >> n;
    cin >> s;
    for (int i = 0 ; i < n ; ++ i) {
        a[i] = s[i] - '0';
    }
    cin >> s;
    for (int i = 0 ; i < n; ++ i)
        b[i] = s[i] - '0';

    vector <int> op;

    int sum = 0;
    bool par = false;

    for (int i = n - 1 ; i >= 0 ; -- i) {
        int first_pos_ind = sum;
        assert(first_pos_ind >= 0);
        int first_pos = a[first_pos_ind] ^ par;
        int at_i_ind = i * (par ? -1 : 1) + sum;
        assert(at_i_ind >= 0);
        int at_i = a[at_i_ind] ^ par;

        if (at_i == b[i]) continue;
        if (first_pos != b[i]) {
            op.push_back(i);
            par ^= 1;
            sum += par ? i : -i;
        } else {
            op.push_back(0);
            op.push_back(i);
            par ^= 1;
            sum += par ? i : -i;
        }
    }

    cout << int(op.size()) << ' ';
    for (int i : op) {
        cout << i + 1 << ' ';
    }

   /* for (int i : op) {
        for (int j = 0 ; j <= i ; ++ j)
            a[j] ^= 1;
        reverse(a, a + i + 1);
    }
*/
   // for (int i = 0 ; i < n; ++ i)
   //     assert(a[i] == b[i]);

    cout << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;
  //  cout << "ans \n";
    cin >> T;

    for (; T -- ; ) {
        solve();
    }

}
/*
    Good Luck
        -Lucina
*/