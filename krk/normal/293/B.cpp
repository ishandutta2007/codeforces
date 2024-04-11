#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int Maxn = 12;
const int mod = 1000000007;

int n, m, k;
int col[Maxn][Maxn];
int isin[Maxn];
int cur[Maxn];
map <int, int> M[Maxn];

bool Possible(int r, int c)
{
    int need = n - r - (c == m - 1);
    for (int i = 1; i <= k && need; i++)
        need -= m - 1 < cur[i];
    return !need;
}

int getRes(int r);

int getCalc(int r, int c)
{
    if (c >= m) return getRes(r + 1);
    int res = 0;
    if (col[r][c]) {
        if (c < cur[col[r][c]]) {
            int tmp = cur[col[r][c]];
            cur[col[r][c]] = c;
            if (Possible(r, c)) res = getCalc(r, c + 1);
            cur[col[r][c]] = tmp;
        }
    } else for (int i = 1; i <= k; i++) if (c < cur[i]) {
        int tmp = cur[i];
        cur[i] = c;
        if (Possible(r, c)) res = (res + getCalc(r, c + 1)) % mod;
        cur[i] = tmp;
    }
    return res;
}

int getRes(int r)
{
    if (r >= n) return 1;
    int id = 0;
    vector <int> tmp;
    for (int i = 1; i <= k; i++) 
        if (isin[i] >= r) id = (m + 1) * id + cur[i];
        else tmp.push_back(cur[i]);
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i++)
        id = (m + 1) * id + tmp[i];
    if (!M[r].count(id)) M[r][id] = getCalc(r, 0);
    return M[r][id];
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if (n + m - 1 > k) printf("0\n");
    else {
        if (m <= n)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    scanf("%d", &col[i][j]);
        else {
            swap(m, n);
            for (int j = 0; j < m; j++)
                for (int i = 0; i < n; i++)
                    scanf("%d", &col[i][j]);
        }
        fill(isin + 1, isin + k + 1, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (col[i][j]) isin[col[i][j]] = i;
        fill(cur + 1, cur + k + 1, m);
        printf("%d\n", getRes(0));
    }
    return 0;
}