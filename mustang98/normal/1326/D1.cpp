#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 1000111222;

bool isp[max_n][max_n];
char buf[max_n];
int n;
string s;

string read_str() {
    scanf("%s", buf);
    return buf;
}

void clr() {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            isp[i][j] = 0;
        }
    }
}

void calc_p() {
    for (int i = 0; i < n; ++i) {
        isp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (len == 2) {
                isp[i][j] = (s[i] == s[j]);
            } else {
                isp[i][j] = (s[i] == s[j] && isp[i + 1][j - 1]);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        s  = read_str();
        n = s.size();
        clr();
        calc_p();
        if (isp[0][n - 1]) {
            cout << s << "\n";
            continue;
        }
        int mx = -1, bp = 0, bm = 0, bdir;
        for (int i = 0; i < n; ++i) {
            int j = n - i - 1;
            if (j <= i) {
                break;
            }
            if (s[i] != s[j]) {
                break;
            }
            int mxm = 0, dir = 0;
            for (int k = i + 1; k < j; ++k) {
                if (isp[i + 1][k]) {
                    mxm = k - i;
                }
            }
            for (int k = j - 1; k > i; --k) {
                if (isp[k][j - 1] && j - k > mxm) {
                    mxm = j - k;
                    dir = 1;
                }
            }

            if ((i + 1) * 2 + mxm > mx) {
                bp = i + 1;
                bm = mxm;
                bdir = dir;
                mx = bp * 2 + bm;
            }
        }
        int mxp = 1, mxs = 1;
        for (int i = 0; i < n; ++i) {
            if (isp[0][i]) {
                mxp = i + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            //c/out << i << ' ' << isp[i][n - 1] << endl;
            if (isp[i][n - 1]) {
                //cout << "AA " << n - i << endl;
                mxs = (n - i);
                //cout << mxs << endl;
            }
        }
        //cout << isp[n - 5][n - 1] << endl;
        //cout << mx << ' '  << mxp << ' ' << mxs << endl;
        if (mx > mxp && mx > mxs) {
            for (int i = 0; i < bp; ++i) {
                cout << s[i];
            }
            if (bdir == 0) {
                for (int i = 0; i < bm; ++i) {
                    cout << s[bp + i];
                }
            } else {
                for (int i = 0; i < bm; ++i) {
                    cout << s[n - bp - bm + i];
                }
            }
            for (int i = 0; i < bp; ++i) {
                cout << s[n - bp + i];
            }
        } else if (mxp > mxs) {
            for (int i = 0; i < mxp; ++i) {
                cout << s[i];
            }
        } else {
            for (int i = 0; i < mxs; ++i) {
                cout << s[n - mxs + i];
            }
        }
        printf("\n");
    }

    return 0;
}