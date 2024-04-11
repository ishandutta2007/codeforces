#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= 4; j++) {
            int x;
            cin >> x;
            sum += x;
        }
        a.push_back(make_pair(-sum, i));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i].second == 1) cout << i + 1 << endl;
    }
}