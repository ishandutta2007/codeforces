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


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    int res = 0;
    int have = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (have >= a)
        {
            have -= a;
            continue;
        }
        res++;
        have = m - a;
    }
    cout << res << endl;

    return 0;
}