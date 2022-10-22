#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
vector <int> seq;

bool Mor(int x)
{
    printf("> %d\n", x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int Get(int ind)
{
    printf("? %d\n", ind); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Print(int a1, int d)
{
    printf("! %d %d\n", a1, d); fflush(stdout);
}

int Rand(int bits)
{
    int res = 0;
    for (int i = 0; i < bits; i++) if (rand() % 2)
        res |= 1 << i;
    return res;
}

int Random(int lef, int rig)
{
    int siz = rig - lef + 1;
    int pw = 0;
    while ((1 << pw) < siz) pw++;
    int res;
    while (true) {
        res = Rand(pw);
        if (res < siz) return lef + res;
    }
    return -1;
}

int myrandom (int i) { return Random(0, i - 1);}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        seq.push_back(i);
    int lef = 1, rig = 1000000000;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Mor(mid - 1)) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    shuffle(seq.begin(), seq.end(), rng);
    int g = 0;
    for (int i = 0; i < 30 && i < seq.size(); i++)
        g = gcd(g, lef - Get(seq[i]));
    Print(lef - (n - 1) * g, g);
    return 0;
}