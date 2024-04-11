#include <bits/stdc++.h>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int n;
int c[3];
bool isprime[400240];


int main() {
    scanf("%d", &n);
    Rep(i, n) {
        int x;
        scanf("%d", &x);
        c[x]++;
    }
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    int maxv = 2 * n + 100;
    For(i, 2, maxv) if (isprime[i]) {
        for (int j = i + i; j <= maxv; j += i) isprime[j] = false;
    }
    VI result;
    int start = 0;
    while (c[1] > 0 || c[2] > 0) {
        int nextprime = start + 1;
        while (!isprime[nextprime]) ++nextprime;
        while (c[2] > 0 && nextprime >= start + 2) {
            start = start + 2;
            --c[2];
            result.push_back(2);
        }
        while (c[1] > 0 && nextprime >= start + 1) {
            start = start + 1;
            --c[1];
            result.push_back(1);
        }
        while (c[2] > 0 && nextprime > start) {
            start += 2;
            --c[2];
            result.push_back(2);
        }
    }
    Rep(i, n) printf("%d ", result[i]);
    printf("\n");
    return 0;
}