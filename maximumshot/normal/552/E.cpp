#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 1000ll + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << ' ';
    return os;
}

bool solve()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    if(n == 1) {
        cout << s << '\n';
        return true;
    }

    s = "0+" + s + "+0";
    n = (int)s.size();

    //cout << s << '\n';

    LL ans = 0;

    vec< LL > preff(n), suff(n);

    preff[0] = s[0] - '0';

    for(int i(2);i < n;i += 2) {
        if(s[i - 1] == '+') {
            preff[i] = preff[i - 2] + s[i] - '0';
        }else {
            int j = i;
            LL x = 1;
            while(j > 0 && s[j - 1] == '*') x *= LL(s[j] - '0'), j -= 2;
            x *= LL(s[j] - '0');
            preff[i] = (j > 1?preff[j - 2] : 0) + x; 
        }
    }

    suff[n - 1] = s[n - 1] - '0';

    for(int i(n - 3);i >= 0;i -= 2) {
        if(s[i + 1] == '+') {
            suff[i] = suff[i + 2] + s[i] - '0';
        }else {
            int j = i;
            LL x = 1;
            while(j + 1 < n && s[j + 1] == '*') x *= LL(s[j] - '0'), j += 2;
            x *= LL(s[j] - '0');
            suff[i] = (j + 2 < n?suff[j + 2] : 0) + x;
        }
    }

    ans = preff[n - 1];

    vec< LL > valL(n), valR(n), lenL(n), lenR(n);
    LL x = 0, y, tmp;

    for(int i(0);i < n;i += 2) {
        if(i == 0 || i > 0 && s[i - 1] == '+') {
            x = s[i] - '0';
            y = s[i] - '0';
            lenL[i] = 1;
        }else {
            x = x - y + y * LL(s[i] - '0');
            y *= LL(s[i] - '0');
            lenL[i] = lenL[i - 2] + 2;
        }
        valL[i] = x;
    }

    x = 0;

    for(int i(n - 1);i >= 0;i -= 2) {
        if(i == n - 1 || i < n - 1 && s[i + 1] == '+') {
            x = s[i] - '0';
            y = s[i] - '0';
            lenR[i] = 1;
        }else {
            x = x - y + y * LL(s[i] - '0');
            y *= LL(s[i] - '0');
            lenR[i] = lenR[i + 2] + 2;
        }
        valR[i] = x;
    }

    /*cout << '\n';
    for(int i(0);i < n;i++) cout << preff[i] << ' ';
    cout << '\n';
    for(int i(0);i < n;i++) cout << suff[i] << ' ';
    cout << '\n';
    for(int i(0);i < n;i++) cout << valL[i] << ' ';
    cout << '\n';
    for(int i(0);i < n;i++) cout << valR[i] << ' ';
    cout << '\n';
    for(int i(0);i < n;i++) cout << lenL[i] << ' ';
    cout << '\n';
    for(int i(0);i < n;i++) cout << lenR[i] << ' ';
    cout << '\n';*/

    for(int l = 2;l + 2 < n;l += 2) {
        x = 0;
        for(int r = l;r + 2 < n;r += 2) {
            if(r > l && s[r - 1] == '+' || l == r) {
                x += s[r] - '0';
                y =  s[r] - '0';
            }else { // r > l && s[r - 1] == '*'
                x = x - y + y * LL(s[r] - '0');
                y *= LL(s[r] - '0');
            }
            // 3+5*7+8*4

            //cout << l << ' ' << r << " " << x << " : ";

            if(s[l - 1] == '+') {
                if(s[r + 1] == '+') {
                    tmp = preff[l - 2] + x + suff[r + 2];
                }else {
                    //if(l == 2 && r == 2) cout << r + 2 + lenR[r + 2] + 1 << ' ';
                    tmp = preff[l - 2] + x * valR[r + 2] + (r + 2 + lenR[r + 2] + 1 < n?suff[r + 2 + lenR[r + 2] + 1] : 0);
                }
            }else {
                if(s[r + 1] == '+') {
                    tmp = (l - 2 - lenL[l - 2] - 1 >= 0?preff[l - 2 - lenL[l - 2] - 1] : 0) + valL[l - 2] * x + suff[r + 2];
                }else {
                    tmp = (l - 2 - lenL[l - 2] - 1 >= 0?preff[l - 2 - lenL[l - 2] - 1] : 0) + 
                        (r + 2 + lenR[r + 2] + 1 < n?suff[r + 2 + lenR[r + 2] + 1] : 0) + 
                        valL[l - 2] * x * valR[r + 2];
                }
            }
            ans = max(ans, tmp);
            //cout << tmp << ' ';

            //cout << '\n';
        }
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}