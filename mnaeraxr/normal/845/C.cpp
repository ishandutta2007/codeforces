#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int A = -1, B = -1;

    vector<pii> show(n);
    for (int i = 0; i < n; ++i)
        cin >> show[i].first >> show[i].second;

    sort(show.begin(), show.end());

    for (auto sh : show){
        if (sh.first > A)
            A = sh.second;
        else if (sh.first > B)
            B = sh.second;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}