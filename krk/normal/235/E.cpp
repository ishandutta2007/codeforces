#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef unsigned int uint;

struct triple {
    int a, b, c;
    triple(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
    bool operator<(const triple &t) const {
        if (a != t.a) return a < t.a;
        if (b != t.b) return b < t.b;
        return c < t.c;
    }
};

const int Maxm = 2001;

bool prime[Maxm];
vector <int> pr;
map <triple, uint> A[Maxm];
map <ii, uint> B[Maxm];
map <int, uint> C[Maxm];

uint getC(int lvl, int a)
{
    if (lvl >= pr.size()) return uint(a);
    if (a < pr[lvl]) return uint(a);
    auto it = C[lvl].find(a);
    if (it == C[lvl].end()) {
        uint cur = getC(lvl + 1, a);
        int num = a;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getC(lvl + 1, num);
        }
        C[lvl].insert(make_pair(a, cur));
        return cur;
    }
    return it->second;
}

uint getB(int lvl,int a, int b)
{
    if (lvl >= pr.size()) return uint(a) * uint(b);
    if (a > b) swap(a, b);
    if (a < pr[lvl]) return uint(a) * getC(lvl, b);
    auto it = B[lvl].find(ii(a, b));
    if (it == B[lvl].end()) {
        uint cur = getB(lvl + 1, a, b);
        int num = a;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getB(lvl + 1, num, b);
        }
        num = b;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getB(lvl + 1, a, num);
        }
        B[lvl].insert(make_pair(ii(a, b), cur));
        return cur;
    }
    return it->second;
}

uint getA(int lvl, int a, int b, int c)
{
    if (lvl >= pr.size()) return uint(a) * uint(b) * uint(c);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a < pr[lvl]) return uint(a) * getB(lvl, b, c);
    auto it = A[lvl].find(triple(a, b, c));
    if (it == A[lvl].end()) {
        uint cur = getA(lvl + 1, a, b, c);
        int num = a;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getA(lvl + 1, num, b, c);
        }
        num = b;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getA(lvl + 1, a, num, c);
        }
        num = c;
        while (num >= pr[lvl]) {
            num /= pr[lvl];
            cur += getA(lvl + 1, a, b, num);
        }
        A[lvl].insert(make_pair(triple(a, b, c), cur));
        return cur;
    }
    return it->second;
}

int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    }
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    cout << getA(0, a, b, c) % (uint(1) << uint(30)) << endl;
    return 0;
}