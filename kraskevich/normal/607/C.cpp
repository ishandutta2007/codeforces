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
    n--;
    string a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'N')
            a[i] = 'S';
        else if (a[i] == 'S')
            a[i] = 'N';
        else if (a[i] == 'E')
            a[i] = 'W';
        else if (a[i] == 'W')
            a[i] = 'E';
    }
    reverse(a.begin(), a.end());
    string s = a + '$' + b;
    int k = s.length();
    int l = -1;
    int r = -1;
    vector<int> z(k);
    for (int i = 1; i < k; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < k && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = n + 1; i < k; i++)
        if (i + z[i] == k) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
}