#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
 
const int Maxm = 1000005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxm], pw2[Maxm];
int my[Maxm], len;
int mx[Maxm];
int n;

struct Hash {
    bool tk[Maxm];
    ii h;
    Hash() {
        fill(tk, tk + Maxm, false);
        h = ii(0, 0);
    }
    void Flip(int x) {
        if (tk[x]) {
            h.first = (h.first - pw1[my[x]] + mod1) % mod1;
            h.second = (h.second - pw2[my[x]] + mod2) % mod2;
        } else {
            h.first = (h.first + pw1[my[x]]) % mod1;
            h.second = (h.second + pw2[my[x]]) % mod2;
        }
        tk[x] = !tk[x];
    }
};
 
bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

Hash G;
Hash H;
ii myex[Maxm];
map <ii, int> M;
bool ntk[Maxm];

void enterNumber(Hash &H, int num)
{
    while (num > 1) {
        int cur = mx[num];
        int cnt = 0;
        while (mx[num] == cur) {
            num /= cur;
            cnt++;
        }
        if (cnt % 2) H.Flip(cur);
    }
}

vector <int> Solve(int n)
{
    vector <int> res;
    while (Prime(n)) {
        res.push_back(n);
        n--;
    }
    for (int i = n; i > 1; i -= 2)
        enterNumber(G, i);
    if (G.h == ii(0, 0)) return res;
    for (int i = 1; i <= n; i++) {
        enterNumber(H, i);
        myex[i] = H.h;
        if (G.h == myex[i]) {
            res.push_back(i);
            return res;
        }
    }
    H = G;
    M.clear();
    for (int i = 1; i <= n; i++) {
        auto it = M.find(myex[i]);
        if (it != M.end()) {
            res.push_back(i);
            res.push_back(it->second);
            return res;
        }
        enterNumber(H, i);
        M[H.h] = i;
    }
    H = G;
    M.clear();
    for (int i = 3; i <= n; i++) {
        auto it = M.find(myex[i]);
        if (it != M.end()) {
            res.push_back(i);
            res.push_back(it->second);
            res.push_back(2);
            return res;
        }
        enterNumber(H, i);
        M[H.h] = i;
    }
    assert(false);
    return res;
}
 
int main()
{
    mod1 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(100000000, 1000000000)(rng);
    arg1 = uniform_int_distribution<int>(1000000, 2000000)(rng);
    arg2 = uniform_int_distribution<int>(1000000, 2000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxm; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    for (int i = 2; i < Maxm; i++) if (mx[i] == 0) {
        my[i] = len++;
        for (int j = i; j < Maxm; j += i)
            mx[j] = i;
    }
    scanf("%d", &n);
    auto res = Solve(n);
    for (int i = 0; i < res.size(); i++)
        ntk[res[i]] = true;
    printf("%d\n", n - int(res.size()));
    bool pr = false;
    for (int i = 1; i <= n; i++) if (!ntk[i]) {
        if (pr) printf(" ");
        else pr = true;
        printf("%d", i);
    }
    printf("\n");
    return 0;
}