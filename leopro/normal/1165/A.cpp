#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<bool> todo(n, false);
    for (int i = n - x; i < n; ++i){
        todo[i] = (s[i] == '1');
    }
    todo[n - y - 1] = !todo[n - y - 1];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += todo[i];
    }
    cout << ans << endl;
}