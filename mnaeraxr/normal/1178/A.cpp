#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int s = 0;

    vector<pii> a(n);

    for (int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i + 1;
        s += a[i].first;
    }

    sort(a.begin() + 1, a.end());

    int x = a[0].first;

    if (2 * x > s){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i){
        if (a[0].first < 2 * a[i].first){
            cout << 0 << endl;
            return 0;
        }

        x += a[i].first;

        if (2 * x > s){
            cout << i + 1 << endl;

            for (int j = 0; j <= i; ++j){
                cout << a[j].second << " \n"[j == i];
            }

            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}