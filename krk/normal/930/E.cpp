#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;
const int mod = 1000000007;

int k, n, m;
int L[Maxn], R[Maxn];
vector <int> un;
vector <int> quer[Maxn];
deque <ii> zers, ones;
int sumzers, sumones;
int sumboth;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &k, &n, &m);
    un.push_back(1);
    un.push_back(k + 1);
    for (int i = 0; i < n + m; i++) {
        scanf("%d %d", &L[i], &R[i]);
        un.push_back(L[i]);
        un.push_back(R[i] + 1);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n + m; i++) {
        L[i] = lower_bound(un.begin(), un.end(), L[i]) - un.begin();
        R[i] = lower_bound(un.begin(), un.end(), R[i] + 1) - un.begin();
        quer[R[i]].push_back(i);
    }
    sumboth = 1;
    for (int i = 0; i + 1 < un.size(); i++) {
        int newzers = sumzers, newones = sumones;
        zers.push_back(ii(i, (sumones + sumboth) % mod));
        newzers = (newzers + zers.back().second) % mod;
        ones.push_back(ii(i, (sumzers + sumboth) % mod));
        newones = (newones + ones.back().second) % mod;
        int bothways = (toPower(2, un[i + 1] - un[i]) - 2 + mod) % mod;
        sumboth = (ll(sumzers) + ll(sumones) + ll(sumboth)) * ll(bothways) % mod;
        sumzers = newzers, sumones = newones;
        for (auto ind: quer[i + 1])
            if (ind < n)
                while (!ones.empty() && ones.front().first <= L[ind]) {
                    sumones = (sumones - ones.front().second + mod) % mod;
                    ones.pop_front();
                }
            else while (!zers.empty() && zers.front().first <= L[ind]) {
                sumzers = (sumzers - zers.front().second + mod) % mod;
                zers.pop_front();
            }
    }
    int res = (ll(sumzers) + ll(sumones) + ll(sumboth)) % mod;
    printf("%d\n", res);
    return 0;
}