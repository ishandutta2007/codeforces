#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;

bool ans(ll w, ll m, ll cur, ll curpow) {
    if (m == cur)
        return true;
    if (!curpow)
        return false;
    short int mult = (m < cur ? -1 : 1);
    curpow /= w;
    ll rescurpow = curpow;
    for (; curpow; curpow /= w)
        if (abs(cur + curpow * mult - m) < abs(cur + rescurpow * mult - m))
            rescurpow = curpow;
    return ans(w, m, cur + rescurpow * mult, rescurpow);
}

int main() {
    /*ifstream in("input.txt");
    ofstream out("output.txt");*/
    ll w, m, cur = 1, rescur = 1;
    cin >> w >> m;
    if ((w == 2) || (w == 3)) {
        cout << "YES";
        return 0;
    }
    for (; cur < m; cur *= w)
        if (abs(cur - m) < abs(rescur - m))
            rescur = cur;
    if (abs(cur - m) < abs(rescur - m))
        rescur = cur;
    cout << (ans(w, m, rescur, rescur) ? "YES" : "NO");
    return 0;
}