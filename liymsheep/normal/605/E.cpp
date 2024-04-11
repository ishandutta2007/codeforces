#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#include <unordered_set>
#include <unordered_map>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 1007;

double pr[N][N];

double current_pr[N];
double ex[N];

bool vis[N];

int main() {
    int n;
    cin >> n;
    REP(i, n) REP(j, n) {
        int v;
        scanf("%d", &v);
        pr[i][j] = v * 0.01;
    }

    ex[n - 1] = 0.0;
    vis[n - 1] = true;
    for (int i = 0; i < n - 1; ++i) {
        ex[i] += pr[i][n - 1];
        current_pr[i] = 1.0 - pr[i][n - 1];
    }

    for (int step = 0; step < n - 1; ++step) {
        int which = -1;
        REP(i, n) if (!vis[i]) {
            if (fabs(current_pr[i] - 1.0) > 1e-12) {
                // c + cp * (ex + 1) = ex
                // (c + cp) / (1 - cp)
                if (which == -1 
                    || (ex[i] + current_pr[i]) / (1 - current_pr[i])
                        < (ex[which] + current_pr[which]) / (1 - current_pr[which])) {
                    which = i;
                }
            }
        }

        if (which == -1) {
            break;
        }

        vis[which] = true;
        ex[which] = (ex[which] + current_pr[which]) / (1 - current_pr[which]);

        // cout << "which = " << which << ", ex = " << ex[which] << endl;

        REP(i, n) if (!vis[i]) {
            ex[i] += (ex[which] + 1) * current_pr[i] * pr[i][which];
            current_pr[i] *= 1.0 - pr[i][which];
        }
    }

    printf("%.12f\n", ex[0]);
    return 0;
}