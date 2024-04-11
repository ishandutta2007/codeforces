#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Foreach(i,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }

int n;
int a[1000010];
int cs[1000010];

int main() {
    // cout.sync_with_stdio(false);
    scanf("%d", &n);
    Rep(i, n) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int countNeg = 0, countPos = 0;
    long long totalNeg = 0, totalPos = 0;
    Rep(i, n) {
        int needShift;

        if (a[i] >= i) {
            countPos++;
            totalPos += a[i] - i;
            needShift = a[i] - i;
        } else {
            countNeg++;
            totalNeg += i - a[i];
            needShift = n - i + a[i];
        }

        cs[needShift]++;
    }

    long long best = 1000000000000000LL;
    int bestk = -1;

    Rep(k, n) {
        // cout << k << " " << totalPos << " " << totalNeg << endl;
        if (best > totalNeg + totalPos) {
            best = totalNeg + totalPos;
            bestk = k;
        }

        int zero = cs[k];
        int aend = a[n - 1 - k];
        if (aend == n - 1) {
            --zero;
            --countPos;

            countPos -= zero;
            totalPos -= countPos;

            countNeg += zero;
            totalNeg += countNeg;  

            ++countPos;
            totalPos += aend - 0;          
        } else {
            --countNeg;
            totalNeg -= (n - 1 - aend);

            // cout << "== " << k << " " << countNeg << " " << totalNeg << endl;

            countPos -= zero;
            totalPos -= countPos;

            countNeg += zero;
            totalNeg += countNeg;

            ++countPos;
            totalPos += aend - 0;
        }
    }

    cout << best << " " << bestk << endl;
    return 0;
}