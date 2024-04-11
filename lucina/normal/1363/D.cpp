#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int ask (vector <int> const &a) {
    cout <<  "? " <<(int)a.size();
    for (int i : a) cout << ' ' << i;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int n, k;
int id[1010];
vector <int> keep[1010];

void solve () {
    cin >> n >> k;

    memset(id, 0, sizeof(id));


    for (int i = 1 ; i <= k ; ++ i) {
        int sz;
        cin >> sz;
        while (sz --) {
            int x;
            cin >> x;
            id[x] = i;
        }
    }

    vector <int> to_ask(n);
    iota(to_ask.begin(), to_ask.end(), 1);
    int mx = ask(to_ask);

    while ((int)to_ask.size() != 1) {

        vector <int> split;
        int out = (int)to_ask.size() / 2;
        while (out -- ) split.push_back(to_ask.back()), to_ask.pop_back();

        int get = ask(to_ask);
        if (get != mx) to_ask = split;
    }

    int mx_index = to_ask[0];
    int spook = -1;
    int ans_spook;

    if (id[mx_index]) {
        spook = id[mx_index];
        vector <int> huh;
        for (int i = 1 ; i <= n ; ++ i) {
            if (id[i] != spook) huh.push_back(i);
        }
        ans_spook = ask(huh);

    }

    cout << "! ";
    for (int i = 1 ; i <= k ; ++ i) {
        if (i == spook) {
            cout << ans_spook;
        } else cout << mx;
        cout << ' ';
    }

    cout << endl;

    string useless;
    cin >> useless;
    assert(useless == "Correct");
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/