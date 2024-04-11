#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

int ask(vector<int> a) {
    cout << "next ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
    int sm = 0;
    int cn = 0;
    int k;
    cin >> k;
    while (sm < 10) {
        string s;
        cin >> s;
        sm += (int)s.size();
        cn++;
    }
    return cn;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    while (1) {
        int t = ask({0, 1});
        t = ask({1});
        if (t == 2) {
            break;
        }
    }

    while (1) {
        int t = ask({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        if (t == 1) {
            break;
        }
    }

    cout << "done" << endl;

    return 0;
}