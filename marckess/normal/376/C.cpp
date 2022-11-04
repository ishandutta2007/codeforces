#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s, res;
    int a[] = {1, 6, 8, 9};
    int r[] = {1, 3, 2, -1, -3, -2};
    vi cub(10);

    cin >> s;

    for (char c : s)
        cub[c-'0']++;

    int sum = 0;
    for (int i = 0; i < 10;) {
        if (i == 1 || i == 6 || i > 7) {
            if (cub[i] > 1) {
                sum += i * r[res.size()%6];
                res.push_back(i+'0');
                cub[i]--;
            } else {
                i++;
            }
        } else {
            if (cub[i]) {
                sum += i * r[res.size()%6];
                res.push_back(i+'0');
                cub[i]--;
            } else {
                i++;
            }
        }
    }

    do {
        int n = res.size();

        int aux = 0;
        for (int i = 0; i < 4; i++) {
            aux += a[i] * r[(n+i)%6];
        }

        if ((aux + sum) % 7 == 0) {
            for (int i = 0; i < 4; i++)
                res.push_back(a[i]+'0');
            break;
        }
    } while (next_permutation(a, a+4));

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}