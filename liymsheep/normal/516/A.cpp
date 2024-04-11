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
    VI ans;
    string x;
    cin >> x >> x;
    REP(i, x.size()) {
        int a = x[i] - '0';
        if (a == 2 || a == 3 || a == 5 || a == 7) {
            ans.PB(a);
        }
        if (a == 4) {
            ans.PB(3);
            ans.PB(2);
            ans.PB(2);
        }
        if (a == 6) {
            ans.PB(5);
            ans.PB(3);
        }
        if (a == 8) {
            ans.PB(7);
            ans.PB(2);
            ans.PB(2);
            ans.PB(2);
        }
        if (a == 9) {
            ans.PB(7);
            ans.PB(3);
            ans.PB(3);
            ans.PB(2);
        }
    }
    SORT(ans);
    REP(i, ans.size()) cout << ans[ans.size() - 1 - i];
    cout << endl;
    return 0;
}