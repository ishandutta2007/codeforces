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
    long long x;
    cin >> x;
    vector<int> result;
    for (int i = 2; i <= x; ++i) {
        bool prime = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (!prime) continue;

        int y = 1;
        while (y * i <= x) {
            y *= i;
            result.push_back(y);
        }
    }
    cout << result.size() << endl;
    REP(i, result.size()) {
        if (i) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}