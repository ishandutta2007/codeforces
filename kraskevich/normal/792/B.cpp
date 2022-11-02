#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x %= a.size();
        cout << a[x] << " ";
        a.erase(a.begin() + x);
        rotate(a.begin(), a.begin() + x, a.end());
    }
    cout << endl;
}