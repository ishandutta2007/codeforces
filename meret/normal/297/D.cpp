
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

char rig[1005][1005];
char dow[1005][1005];

int t[1005][1005];

int tmp[1005][1005];
char tc1[1005][1005];
char tc2[1005][1005];

int h, w, k;

bool transposed;

int cnt_hor, cnt_ver;

void transpose() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tmp[j][i] = t[i][j];
            tc1[j][i] = rig[i][j];
            tc2[j][i] = dow[i][j];
        }
    }
    memcpy(t, tmp, sizeof(t));
    memcpy(dow, tc1, sizeof(tc1));
    memcpy(rig, tc2, sizeof(tc2));
    swap(cnt_hor, cnt_ver);
    swap(h, w);
    transposed ^= 1;
}

void print() {
    if (transposed) {
        transpose();
    }
    printf("YES\n");
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%d", 1 + t[i][j]);
            if (j < w - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    exit(0);
}

int main() {
    scanf("%d %d %d", &h, &w, &k);
    for (int i = 0; i < h; ++i) {
        scanf("%s", rig[i]);
        if (i < h - 1) {
            scanf("%s", dow[i]);
        } else {
            for (int j = 0; j < w; ++j) {
                dow[i][j] = 'X';
            }
        }
        rig[i][w - 1] = 'X';
    }
    cnt_hor = h * (w - 1);
    cnt_ver = (h - 1) * w;

    if (k == 1) {
        int cne = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                t[i][j] = 0;
                if (rig[i][j] == 'N') {
                    ++cne;
                }
                if (dow[i][j] == 'N') {
                    ++cne;
                }
            }
        }
        if (4 * cne > cnt_hor + cnt_ver) {
            printf("NO\n");
            exit(0);
        } else {
            print();
        }
    }

    if (cnt_ver > cnt_hor) {
        transpose();
    }

    for (int i = 0; i < h; ++i) {
        t[i][0] = 0;
        for (int j = 1; j < w; ++j) {
            t[i][j] = t[i][j - 1] ^ (rig[i][j - 1] == 'N');
        }
        if (i > 0) {
            int score = 0;
            for (int j = 0; j < w; ++j) {
                if ((dow[i - 1][j] == 'E') == (t[i - 1][j] == t[i][j])) {
                    ++score;
                }
            }
            if (2 * score < w) {
                for (int j = 0; j < w; ++j) {
                    t[i][j] ^= 1;
                }
            }
        }
    }

    print();
}