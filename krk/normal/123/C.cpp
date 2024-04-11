#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 205;

int n, m, l;
ll k;
int val[Maxn], ind[Maxn];
char c[Maxn];
ll ways[Maxn][Maxn];

const bool Less(const int &a, const int &b)
{
    return val[a] < val[b];
}

int main()
{
    cin >> n >> m >> k;
    l = n + m - 1;
    fill(val, val + l, n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int v; cin >> v;
            val[i + j] = min(val[i + j], v);
        }
    for (int i = 0; i < l; i++) ind[i] = i;
    sort(ind, ind + l, Less);
    for (int i = 0; i < l; i++) {
        c[ind[i]] = '(';
        ways[0][0] = 1;
        for (int j = 0; j < l; j++)
            for (int z = 0; z <= j && z <= l - j; z++) 
                if (ways[j][z]) {
                                if (ways[j][z] > k) ways[j][z] = k;
                                if (c[j] != ')') ways[j + 1][z + 1] += ways[j][z];
                                if (c[j] != '(' && z) ways[j + 1][z - 1] += ways[j][z];
                                ways[j][z] = 0;
                }
        if (ways[l][0] < k) {
                       k -= ways[l][0];
                       c[ind[i]] = ')';
        }
        ways[l][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << c[i + j];
        cout << endl;
    }
    return 0;
}