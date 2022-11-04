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

const int N = 1000007;

char s[N];

int main() {
    int n;
    cin >> n;
    scanf("%s", s);
    REP(i, n) s[i] -= '0';
    int ans = 0;
    for (int start = 0; start < 2; ++start) {
        int len = 0, current = start;
        int max_len = 0;
        int cur_len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == current) {
                ++len;
                current = 1 - current;
            } else {
                ++max_len;
            }
        }
        if (max_len == 1) {
            ++len; 
        } else if (max_len >= 2) {
            len += 2;
        }
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}