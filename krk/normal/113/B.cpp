#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

const ll Maxl = 26LL;
const ll mod = 1000000007LL;
const int Maxn = 2005;

string t, sbegin, send;
bool b[Maxn], e[Maxn];
set <int> S;
int res;

int main()
{
    getline(cin, t);
    getline(cin, sbegin);
    getline(cin, send);
    int from = 0;
    while ((from = t.find(sbegin, from)) != string::npos) {
          b[from] = true;
          from++;
    }
    from = 0;
    while ((from = t.find(send, from)) != string::npos) {
          e[from + send.length() - 1] = true;
          from++;
    }
    ll a = 1;
    ll h0 = 0;
    for (int l = 1; l <= t.length(); l++) {
        S.clear();
        ll h;
        for (int i = 0; i + l <= t.length(); i++) {
            if (i) h = ((h - a * (t[i - 1] - 'a') % mod + mod) * Maxl + (t[i + l - 1] - 'a')) % mod;
            else h = h0 = (Maxl * h0 + t[i + l - 1] - 'a') % mod;
            if (b[i] && e[i + l - 1] && l >= sbegin.length() && l >= send.length() && 
                S.find(h) == S.end()) S.insert(h);
        }
        res += S.size();
        a = Maxl * a % mod;
    }
    cout << res << endl;
    return 0;
}