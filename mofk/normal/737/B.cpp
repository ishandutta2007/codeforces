#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N, a, b, K;
string s;
vector <ii> lengths;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> a >> b >> K >> s; --a; s += '1';
    int last = -1;
    ff(i, 0, s.size() - 1) if (s[i] == '1') lengths.pb(ii((i - last - 1) / b, last)), last = i;
    int need = 0;
    K = lengths.size();
    ff(i, 0, K - 1) need += lengths[i].first;
    need -= a;
    cout << need << endl;
    ff(rep, 1, need) {
        while (lengths.back().first == 0) lengths.pop_back();
        lengths.back().second += b; --lengths.back().first;
        cout << lengths.back().second + 1 << " ";
    }
    cout << endl;
    return 0;
}