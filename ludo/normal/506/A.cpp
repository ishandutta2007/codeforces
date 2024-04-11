#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#ifdef LOCAL
#define MAXN 80
#else
#define MAXN 30010
#endif // LOCAL

#define UNINIT (-100000000)

const int maxdiff = 5 + sqrt(2 * MAXN);
const int diffdp = 2 * maxdiff + 1;

int d, gems[MAXN];

int dp[MAXN][diffdp];

bool input()
{
    int n, a;
    cin >> n >> d;
    if (!cin) {
        return false;
    }
    for (int i = 0; i < MAXN; i++) {
        gems[i] = 0;
    }
    while (n--) {
        cin >> a;
        if (!cin) {
            return false;
        }
        gems[a]++;
    }
    return true;
}

inline void smax(int &a, int b)
{
	if (b > a) a = b;
}

void run()
{
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < diffdp; j++) {
            dp[i][j] = UNINIT;
        }
//        cerr << gems[i] << " ";
    }
//    cerr << endl;

//    cerr << "MAXDIFF = " << maxdiff << endl;

    int ret = dp[d][maxdiff] = gems[0] + gems[d];
    for (int i = d; i < MAXN; i++) {
        for (int j = 0; j < diffdp; j++) {
            if (dp[i][j] == UNINIT) {
                continue;
            }

            int l = d + j - maxdiff;

//            cerr << i << " " << l << "(" << j << "): " << dp[i][j] << endl;

            if (l > 0) {
                // accelerate
                if (i + l + 1 < MAXN && j + 1 < diffdp) {
                    smax(dp[i + l + 1][j + 1], dp[i][j] + gems[i + l + 1]);
//                    cerr << (i + l + 1) << " " << (j + 1) << ": " << dp[i + l + 1][j + 1] << endl;
                }
                // stay same
                if (i + l < MAXN) {
                    smax(dp[i + l][j], dp[i][j] + gems[i + l]);
                }

                if (l > 1) {
                    // decelerate
                    if (i + l - 1 < MAXN && j - 1 >= 0) {
                        smax(dp[i + l - 1][j - 1], dp[i][j] + gems[i + l - 1]);
                    }
                }
            }

//			int curl = d + j - maxdiff;
//			if (j > 0 && i - curl - 1 >= d) {
//				// accelerate
//				dp[i][j] = max(dp[i][j], dp[i - curl - 1][j - 1]);
//			}
//			if (i - curl >= d) {
//				dp[i][j] = max(dp[i][j], dp[i - curl][j]);
//			}
//			if (j + 1 < diffdp && i - curl + 1 >= d) {
//				// decelerate
//				dp[i][j] = max(dp[i][j], dp[i - curl + 1][j + 1]);
//			}

//            if (ret < dp[i][j]) {
//				cerr << i << " " << l << ": " << dp[i][j] << endl;
//            }
            ret = max(ret, dp[i][j]);

        }
    }
    cout << ret << endl;
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
//    freopen("debug.txt", "w", stderr);
    while (input()) {
        run();
    }
#else
    input();
    run();
#endif // LOCAL
}