#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    int a_odd = 0, a_even = 0, b_odd = 0, b_even = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) a_odd++; else a_even++;
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] % 2 == 1) b_odd++; else b_even++;
    }
    cout << min(a_odd, b_even) + min(a_even, b_odd) << endl;
    return 0;
}