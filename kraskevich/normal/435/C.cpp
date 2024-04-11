#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> PLL;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

#ifdef TEST
    class Timer
    {
    public:
        Timer()
        {
            start = clock();
        }

        ~Timer()
        {
            cerr << "Execution time: " << clock() - start << " ms" << endl;
        }
    private:
        int start;
    };

    Timer timer;
#endif

const int N = 3000;
const int ADD = 1500;

char c[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = ' ';
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x = ADD;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        int dy = a[i];
        int d = (i % 2 ? 1 : -1);
        int dx = d * a[i];
        for (int rep = 0; rep < dy; rep++)
        {
            c[x][y] = (i % 2 == 0 ? '/' : '\\');
            x += d;
            y++;
        }
        x -= d;
    }
    int mi = N, mj = N, mxi = 0, mxj = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (c[i][j] != ' ')
            {
                mi = min(mi, i);
                mj = min(mj, j);
                mxi = max(mxi, i);
                mxj = max(mxj, j);
            }
    for (int i = mi; i <= mxi; i++)
    {
        for (int j = mj; j <= mxj; j++)
            cout << c[i][j];
        cout << "\n";
    }

    return 0;
}