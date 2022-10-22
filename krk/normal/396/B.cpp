#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxm = 100005;

bool npr[Maxm];
vector <int> pr;
int t;

bool Prime(int x)
{
    for (int i = 0; pr[i] * pr[i] <= x; i++)
        if (x % pr[i] == 0) return false;
    return true;
}

ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }

int main()
{
    for (int i = 2; i < Maxm; i++) if (!npr[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxm; j += i)
            npr[j] = true;
    }
    scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int l = n;
        while (!Prime(l)) l--;
        int r = n + 1;
        while (!Prime(r)) r++;
        ll a = ll(l - 2) * r + ll(n - l + 1) * 2;
        ll b = 2ll * l * r;
        ll g = gcd(a, b);
        a /= g; b /= g;
        printf("%I64d/%I64d\n", a, b);
    }
    return 0;
}