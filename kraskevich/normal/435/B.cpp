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

    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    for (int pos = 0; pos < n; pos++)
    {
        for (int d = '9'; d >= '0'; d--)
        {
            int f = pos;
            while (f < n && s[f] != d)
                f++;
            if (f == n || f - pos > k)
                continue;
            k -= f - pos;
            for (int j = f; j > pos; j--)
                swap(s[j], s[j - 1]);
            break;
        }
    }
    cout << s;

    return 0;
}