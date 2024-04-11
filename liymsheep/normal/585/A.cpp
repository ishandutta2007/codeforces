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

const int N = 5000;

LL v[N], d[N], p[N];

int main() {
    int n;
    cin >> n;
    REP(i, n) cin >> v[i] >> d[i] >> p[i];
    VI answer;
    vector<bool> in(n);
    fill(ALL(in), true);
    REP(i, n) {
        if (!in[i]) continue;
        int vv = v[i];
        answer.PB(i);
        for (int j = i + 1; j < n && vv; ++j) {
            if (in[j]) {
                p[j] -= vv;
                --vv;
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (in[j] && p[j] < 0) {
                in[j] = false;
                for (int k = j + 1; k < n; ++k) {
                    p[k] -= d[j];
                }
            }
        }
    }
    cout << answer.size() << endl;
    REP(i, answer.size()) {
        if (i) cout << " ";
        cout << answer[i] + 1;
    }
    cout << endl;
    return 0;
}