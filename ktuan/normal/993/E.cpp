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
#include <complex>
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

struct Complex {
    double x, y;
    Complex operator+(const Complex &d) const { return (Complex){x + d.x, y + d.y}; }
    Complex operator-(const Complex &d) const { return (Complex){x - d.x, y - d.y};}
    Complex operator*(const Complex &d) const { return (Complex){x * d.x - y * d.y, x * d.y + y * d.x}; }
    Complex operator/(const double &d) const { return (Complex){x / d, y / d}; }
    Complex& operator=(int d) { x = d; y = 0; return *this; }
};

const double PI = acosl(0) * 2;

template<int D, class T> void FFT(T a, Complex *res, int step, int n) {
    if(n==1)
        res[0] = a[0];
    else {
        double angle = D*2*PI/n;
        Complex wn = (Complex){cos(angle), sin(angle)}, w = (Complex){1, 0}, tmp;
        n/=2;
        FFT<D>( a, res, step * 2, n);
        FFT<D>( a + step, res + n, step * 2, n);
        for(int k=0;k<n;++k) {
            tmp = res[k+n] * w;
            res[k+n] = res[k] - tmp;
            res[k] = res[k] + tmp;
            w = w * wn;
        }
    }
}

// A, B, a, b, res's length must be 2 * n, n is power of 2
Complex A[1<<19], B[1<<19];
void mul(int *a, int *b, int n, LL *res) {
    n *= 2;
    FFT<1>(&a[0],&A[0],1,n);
    FFT<1>(&b[0],&B[0],1,n);
    for(int i=0;i<n;++i) A[i] = A[i] * B[i];
    FFT<-1>(&A[0],&B[0],1,n);
    for(int i=0;i<n;++i) res[i] = (LL)(B[i].x / n + 0.5);
}

// n must be power of 2, FF, GG, c's length must be 2 * n
// a and b's length can be n
LL FF[1 << 19], GG[1 << 19], nt;
map<int, int> lengthToPos;
void mul2(LL *a, LL * b, int st, int end, LL *c) {
    int n = (end - st);
    if (n <= 40) {
        Rep(i, 2 * n) c[i] = 0;
        Rep(i, n) Rep(j, n) c[i + j] += a[i + st] * b[j + st];
        return;
    }
    int mid = n / 2;
    int baseF;
    if (lengthToPos. count(n)) baseF = lengthToPos[n];
    else { baseF = nt; nt += n; lengthToPos[n] = baseF; }
    LL *F = FF + baseF; LL *G = GG + baseF;
    mul2(a, b, st, st + mid, F);
    mul2(a, b, st + mid, end, G);
    Rep(i, 2 * n) c[i] = 0;
    Rep(i, n) c[i] = F[i];
    Rep(i, n) c[i + mid + mid] += G[i];
    Rep(i, n) F[i] = F[i] + G[i];
    Rep(i, mid) {
        a[st + i] = a[st + i] + a[st + mid + i];
        b[st + i] = b[st + i] + b[st + mid + i];
    }
    mul2(a, b, st, st + mid, G);
    Rep(i, mid) {
        a[st + i] = a[st + i] - a[st + mid + i];
        b[st + i] = b[st + i] - b[st + mid + i];
    }
    Rep(i, n) c[i + mid] += G[i] - F[i];
}


int n;
int a[200020];
int L[1<<19], R[1<<19];
LL O[1<<19];
int num0 = 0;

int main() {
    int x;
    scanf("%d%d", &n, &x);
    int c = 0;
    Rep(i, n) {
        scanf("%d", a+i);
        if (a[i] < x) a[i] = ++c;
        else a[i] = 0;
    }
    num0 = c;
    c = 0;
    int id = 0;
    LL r0 = 0;
    Rep(i, n) {
        ++c;
        if (a[i]) {
            if (c > 0) r0 = r0 + c * 1LL * (c-1) / 2;
            L[id++] = c;
            c = 0;
        }
    }
    if (c > 0) r0 = r0 + c * 1LL * (c+1) / 2;
    c = 0;
    id = 0;
    Ford(i, n-1, 0) {
        ++c;
        if (a[i]) {
            R[id++] = c;
            c = 0;
        }
    }
    // Rep(i, num0) cout << L[i] << endl;
    // cout << endl;
    // Rep(i, num0) cout << R[i] << endl;
    int p2 = 1 << 18;
    // while (p2 < n) p2 *= 2;
    // mul2(L, R, 0, p2, O);
    mul(L, R, p2, O);
    
    printf("%lld ", r0);
    For(i, 1, num0) printf("%lld ", O[num0 - i]);
    For(i, num0 + 1, n) printf("0 ");
    printf("\n");
    return 0;
}