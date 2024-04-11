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

int main() {
    int n;
    cin >> n;
    VI a(n);
    REP(i, n) scanf("%d", &a[i]);
    VI length(n);
    length[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            length[i] = 1;
        } else {
            length[i] = length[i - 1] + 1;
        }
    }

    int rad = 0;
    for (int i = n - 1; i >= 0; ) {
        if (length[i] % 2 == 1) {
            for (int j = i - length[i] + 1; j <= i; ++j) {
                a[j] = a[i];
            }
            rad = max(rad, length[i] / 2);
        } else {
            int half = length[i] / 2;
            for (int j = i - length[i] + 1; j < i - half + 1; ++j) {
                a[j] = a[i - length[i] + 1];
            }

            for (int j = i - half + 1; j <= i; ++j) {
                a[j] = a[i];
            }
            rad = max(rad, length[i] / 2 - 1);
        }
        i -= length[i];
    }

    cout << rad << endl;
    REP(i, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}