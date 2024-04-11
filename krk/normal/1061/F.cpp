#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k;
int H;

ii getRand()
{
    int a = uniform_int_distribution<int>(0, n - 1)(rng);
    int b = uniform_int_distribution<int>(1, n - 1)(rng);
    b = (a + b) % n;
    return ii(a + 1, b + 1);
}

bool Ask(int a, int b, int c)
{
    printf("? %d %d %d\n", a, b, c); fflush(stdout);
    string res; cin >> res;
    return res == "Yes";
}

bool Solve(int a, int b)
{
    vector <int> seq;
    for (int i = 1; i <= n; i++) if (i != a && i != b)
        if (Ask(a, i, b)) seq.push_back(i);
    if (seq.size() != 2 * H - 1) return false;
    for (int i = 0; i < seq.size(); i++) {
        int st = 0;
        for (int j = 0; j < seq.size(); j++) if (i != j)
            if (Ask(a, seq[j], seq[i])) st++;
        if (st == H - 1) {
            printf("! %d\n", seq[i]); fflush(stdout);
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    int cur = 1, lft = n - 1;
    while (lft > 0) {
        cur *= k;
        lft -= cur;
        H++;
    }
    while (true) {
        ii ab = getRand();
        if (Solve(ab.first, ab.second)) break;
    }
    return 0;
}