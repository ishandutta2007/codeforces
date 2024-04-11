#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        deque <int> d;
        int n;
        cin >> n;

        for (int i = 0 ; i < n ; ++ i) {
            int x;
            cin >> x;
            d.push_back(x);
        }

        while (!d.empty()) {
            cout << d.front() << ' ';
            d.pop_front();
            if (!d.empty()) {
                cout << d.back() << ' ';
                d.pop_back();
            }
        }
        cout << '\n';
    }
}