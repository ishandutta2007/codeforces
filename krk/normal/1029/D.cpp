#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int Maxn = 200005;
const int Maxl = 12;

int n, k;
int A[Maxn][Maxl];
map <int, int> has[Maxl];
vector <int> my[Maxl];
ll res;

int getCnt(int x)
{
    int res = 0;
    do {
        res++;
        x /= 10;
    } while (x);
    return res;
}

int Get(map <int, int> &M, int key)
{
    map <int, int>::iterator it = M.find(key);
    return it != M.end()? it->second: 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        int mult = 1;
        for (int j = 0; j < Maxl; j++) {
            A[i][j] = ull(a) * ull(mult) % ull(k);
            has[j][A[i][j]]++;
            mult = ll(mult) * 10ll % k;
        }
        my[getCnt(a)].push_back(i);
    }
    for (int i = 0; i < Maxl; i++)
        for (int j = 0; j < my[i].size(); j++) {
            int ind = my[i][j];
            if ((A[ind][i] + A[ind][0]) % k == 0)
                res--;
            res += Get(has[i], (k - A[ind][0]) % k);
        }
    cout << res << endl;
    return 0;
}