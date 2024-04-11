#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef pair <int, int> ii;
typedef long long ll;

const int mod = 998244353;
const int Maxn = 100;

int pw[Maxn];
int k, a, h;
map <int, uint> M[Maxn][Maxn];
int res[Maxn];
bool noAns;

int getPlace(int ind)
{
    return ind < k? (1 << (k - ind - 1)) + 1: 1;
}

int getA(int ind)
{
    return pw[getPlace(ind)];
}

void Add(map <int, uint> &M, int val, int ind)
{
    auto it = M.find(val);
    if (it == M.end())
        M.insert(make_pair(val, uint(1) << uint(ind)));
    else it->second |= uint(1) << uint(ind);
}

void Solve(int k, int a, int d, int h, int ind)
{
    if (a == d) {
        if (ind == -1) res[a] = getPlace(k);
    } else {
        int b = (a + d) / 2;
        int c = b + 1;
        for (auto it1: M[a][b])
            for (int z = a; z <= b; z++) if (bool(it1.second & uint(1) << uint(z)) && (ind == z || ind == -1)) {                        
                int sum = (it1.first - ll(z + 1) * getA(k - 1) % mod + mod) % mod;
                sum = (sum + ll(z + 1) * getA(k)) % mod;            
                int nd = (h - sum + mod) % mod;
                auto it2 = M[c][d].find(nd);
                if (it2 == M[c][d].end()) continue;
                if (ind == -1) res[z] = getPlace(k);
                Solve(k - 1, a, b, it1.first, z);
                Solve(k - 1, c, d, it2->first, -1);
                return;
            }
        for (auto it2: M[c][d])
            for (int z = c; z <= d; z++) if (bool(it2.second & uint(1) << uint(z)) && (ind == z || ind == -1)) {                        
                int sum = (it2.first - ll(z + 1) * getA(k - 1) % mod + mod) % mod;
                sum = (sum + ll(z + 1) * getA(k)) % mod;            
                int nd = (h - sum + mod) % mod;
                auto it1 = M[a][b].find(nd);
                if (it1 == M[a][b].end()) continue;
                if (ind == -1) res[z] = getPlace(k);
                Solve(k - 1, a, b, it1->first, -1);
                Solve(k - 1, c, d, it2.first, z);
                return;
            }
        noAns = true;
    }
}

void Print()
{
    for (int i = 0; i < 1 << k; i++)
        printf("%d%c", res[i], i + 1 < (1 << k)? ' ': '\n');
}

int main()
{
    scanf("%d %d %d", &k, &a, &h);
    pw[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw[i] = ll(a) * pw[i - 1] % mod;
    for (int i = 0; i < 1 << k; i++)
        Add(M[i][i], ll(i + 1) * getA(0) % mod, i);
    for (int j = 0; j + 1 < k; j++) {
        int my = 1 << j;
        for (int i = 0; i < 1 << k; i += 2 * my) {
            int a = i, b = i + my - 1;
            int c = i + my, d = i + 2 * my - 1;
            for (auto it1: M[a][b])
                for (int z = a; z <= b; z++) if (it1.second & uint(1) << uint(z)) {                        
                    int sum = (it1.first - ll(z + 1) * getA(j) % mod + mod) % mod;
                    sum = (sum + ll(z + 1) * getA(j + 1)) % mod;
                    for (auto it2: M[c][d]) {
                        int csum = (sum + it2.first) % mod;
                        Add(M[a][d], csum, z);
                    }
                }
            for (auto it2: M[c][d])
                for (int z = c; z <= d; z++) if (it2.second & uint(1) << uint(z)) {                        
                    int sum = (it2.first - ll(z + 1) * getA(j) % mod + mod) % mod;
                    sum = (sum + ll(z + 1) * getA(j + 1)) % mod;
                    for (auto it1: M[a][b]) {
                        int csum = (sum + it1.first) % mod;
                        Add(M[a][d], csum, z);
                    }
                }
        }
    }
    Solve(k, 0, (1 << k) - 1, h, -1);
    if (noAns) printf("-1\n");
    else Print();
    return 0;
}