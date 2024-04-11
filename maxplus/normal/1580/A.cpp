//#130350076

#define NDEBUG

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define PRINT(x)                         \
    if (debug)                           \
    {                                    \
        cout << #x << ": " << x << endl; \
    }
#define PRINTARR(x)           \
    if (debug)                \
    {                         \
        cout << #x << ": ";   \
        for (auto i : x)      \
        {                     \
            cout << i << ' '; \
        }                     \
        cout << endl;         \
    }
#define MODP(a, b) ((a % b + b) % b)
#define divideCeil(a, b) ((a + b - 1) / b)
#define INF 1000000007
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
bool debug;

//libraries
//2D Prefix Sum
/**
 * Returns the 2D prefix sum of a 2D array
 * prefixSum2D[i+1][j+1] = sum of elements in 2D array from array[0][0] until array[i][j]
 */
template <typename T>
vector<vector<T>> prefixSum2D(vector<vector<T>> &matrix)
{
    assert(!matrix.empty());
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<T>> ps(n + 1, vector<T>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + matrix[i][j];

    return ps;
}
/**
 * Calculates the rectangle range sum of a 2D array
 * @param ps 2D Prefix sum array
 * @param top Top-most row
 * @param left Left-most column
 * @param bottom Bottom-most row
 * @param right Right-most column
 * @return The sum of elements from array[top][left] until array[bottom][right]
 */
template <typename T>
T areaSum(vector<vector<T>> &ps, int top, int left, int bottom, int right)
{
    assert(!ps.empty());
    assert(top >= 0 && top + 1 < ps.size() && bottom >= 0 && bottom + 1 < ps.size() && left >= 0 && left + 1 < ps[0].size() && right >= 0 && right + 1 < ps[0].size());
    return ps[bottom + 1][right + 1] - ps[bottom + 1][left] - ps[top][right + 1] + ps[top][left];
}

int main(int argc, char *argv[])
{
    debug = argc > 0; //set to 1 to disable debug mode

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        char line[m + 1];
        vector<vi> arr(n, vi(m));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", line);
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = line[j] - '0';
            }
        }
        auto prefsum = prefixSum2D(arr);
        int minCost = INF;
        for (int i = 0; i < n - 4; i++)
        {
            int rstart = i;
            for (int j = 0; j < m - 3; j++)
            {
                int cstart = j;

                for (int k = rstart + 5 - 1; k < n; k++)
                {
                    int rend = k;
                    for (int l = cstart + 4 - 1; l < m; l++)
                    {
                        int cend = l;
                        int atas = areaSum(prefsum, rstart, cstart + 1, rstart, cend - 1);
                        int bawah = areaSum(prefsum, rend, cstart + 1, rend, cend - 1);
                        int kiri = areaSum(prefsum, rstart + 1, cstart, rend - 1, cstart);
                        int kanan = areaSum(prefsum, rstart + 1, cend, rend - 1, cend);
                        int tengah = areaSum(prefsum, rstart + 1, cstart + 1, rend - 1, cend - 1);

                        int hl = cend - cstart - 1;
                        int vl = rend - rstart - 1;

                        int cost = (hl - atas) + (hl - bawah) + (vl - kiri) + (vl - kanan) + tengah;
                        minCost = min(minCost, cost);
                        if (cost - (vl - kanan) > minCost)
                        {
                            break;
                        }
                    }
                }
            }
        }
        cout << minCost << endl;
    }

    return 0;
}