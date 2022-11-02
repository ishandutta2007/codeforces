#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <unordered_map>
using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef complex<double> cd;


#ifdef LOCAL_DEBUG
const int SZ = 10;
const int logN = 18;
const int polynomLength = 1 << (logN + 1);
#else
const int SZ = 200500;
const int logN = 18;
const int polynomLength = 1 << (logN + 1);
#endif

ll res = 0;

int movesCnt(int x1, int y1, int x2, int y2) {
    return mabs(x1-x2) + mabs(y1-y2);
}

bool canMove(int x1, int y1, int x2, int y2, int steps) {
    return movesCnt(x1, y1, x2, y2) <= steps;
}

void run() {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    
    bool win = false;
    if (x1 + y1 <= max(x2, y2))
        win = true;
    
    rep(i, 1, min(x2, y2) + 1) {
        if (canMove(x1, y1, x2 - i, y2 - i, i))
            win = true;
    }
    
    string wr = "Vasiliy";
    if (win)
        wr = "Polycarp";
    printf("%s\n", wr.c_str());
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    time_t st = clock();
#else 
#ifdef prob
    freopen(prob".in", "r", stdin);
    freopen(prob".out", "w", stdout);
#endif
#endif
    
    run();
    
#ifdef LOCAL_DEBUG
    printf("\n=============\n");
    printf("Time: %.4lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif
    
    return 0;
    
}