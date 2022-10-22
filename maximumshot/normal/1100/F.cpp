#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;


/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#define VERSION "0.1.4"

#include <cassert>
#include <cstdio>
#include <algorithm>

/** Fast allocation */

#ifdef FAST_ALLOCATOR_MEMORY
        int allocator_pos = 0;
        char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
        inline void * operator new ( size_t n ) {
                char *res = allocator_memory + allocator_pos;
                allocator_pos += n;
                assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
                return (void *)res;
        }
        inline void operator delete ( void * ) noexcept { }
//        inline void * operator new [] ( size_t ) { assert(0); }
        //inline void operator delete [] ( void * ) { assert(0); }
#endif

/** Fast input-output */

template <class T = int> inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar(); // first non-blank character
inline void readWord( char *s );
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int getChar();
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();

template <class T> inline void writeInt( T x, char end = 0, int len = -1 );
inline void writeChar( int x );
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

static struct buffer_flusher_t {
        ~buffer_flusher_t() {
                flush();
        }
} buffer_flusher;

/** Read */

static const int buf_size = 4096;

static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
        if (buf_pos == buf_len) {
                buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
                if (buf_pos == buf_len)
                        return 1;
        }
        return 0;
}

inline int getChar() {
        return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() {
        return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() {
        int c;
        while ((c = peekChar()) != -1 && c <= 32)
                buf_pos++;
        return c == -1;
}

inline void skipBlanks() {
        while (!isEof() && buf[buf_pos] <= 32U)
                buf_pos++;
}

inline int readChar() {
        int c = getChar();
        while (c != -1 && c <= 32)
                c = getChar();
        return c;
}

inline int readUInt() {
        int c = readChar(), x = 0;
        while ('0' <= c && c <= '9')
                x = x * 10 + c - '0', c = getChar();
        return x;
}

template <class T>
inline T readInt() {
        int s = 1, c = readChar();
        T x = 0;
        if (c == '-')
                s = -1, c = getChar();
        else if (c == '+')
                c = getChar();
        while ('0' <= c && c <= '9')
                x = x * 10 + c - '0', c = getChar();
        return s == 1 ? x : -x;
}

inline double readDouble() {
        int s = 1, c = readChar();
        double x = 0;
        if (c == '-')
                s = -1, c = getChar();
        while ('0' <= c && c <= '9')
                x = x * 10 + c - '0', c = getChar();
        if (c == '.') {
                c = getChar();
                double coef = 1;
                while ('0' <= c && c <= '9')
                        x += (c - '0') * (coef *= 1e-1), c = getChar();
        }
        return s == 1 ? x : -x;
}

inline void readWord( char *s ) {
        int c = readChar();
        while (c > 32)
                *s++ = c, c = getChar();
        *s = 0;
}

inline bool readLine( char *s ) {
        int c = getChar();
        while (c != '\n' && c != -1)
                *s++ = c, c = getChar();
        *s = 0;
        return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
        if (write_buf_pos == buf_size)
                fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
        write_buf[write_buf_pos++] = x;
}

inline void flush() {
        if (write_buf_pos)
                fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}

template <class T>
inline void writeInt( T x, char end, int output_len ) {
        if (x < 0)
                writeChar('-'), x = -x;

        char s[24];
        int n = 0;
        while (x || !n)
                s[n++] = '0' + x % 10, x /= 10;
        while (n < output_len)
                s[n++] = '0';
        while (n--)
                writeChar(s[n]);
        if (end)
                writeChar(end);
}

inline void writeWord( const char *s ) {
        while (*s)
                writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
        if (x < 0)
                writeChar('-'), x = -x;
        int t = (int)x;
        writeInt(t), x -= t;
        writeChar('.');
        for (int i = output_len - 1; i > 0; i--) {
                x *= 10;
                t = std::min(9, (int)x);
                writeChar('0' + t), x -= t;
        }
        x *= 10;
        t = std::min(9, (int)(x + 0.5));
        writeChar('0' + t);
}

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 5e5 + 5;
const int LOG = 20;
const int X = 1 << LOG;

int n;
int a[N];

int f(int x) { return (1 << __lg(x)); }

void add(vector< int > &a, int x) {
    for(int v : a) {
        if(f(v) & x) x ^= v;
    }
    if(!x) return;
    for(int &v : a) {
        if(f(x) & v) v ^= x;
    }
    a.push_back(x);
}

int merge(const vector< int > &a, const vector< int > &b) {
    vector< int > c;
    for(int x : a) add(c, x);
    for(int x : b) add(c, x);
    sort(c.rbegin(), c.rend());
    int x = 0;
    for(int y : c) x = max(x, x ^ y);
    return x;
}

int res[N];
vector< int > pre[N], suf[N];
vector< pair< pii, int > > qs[4 * N];

void update(int v, int l, int r, int i, int ql, int qr) {
    if(ql < l || ql > r || qr < l || qr > r) return;
    int m = (l + r) >> 1;
    if(ql <= m && qr > m || l == r) {
        qs[v].push_back({{ql, qr}, i});
        return;
    }
    update(v << 1, l, m, i, ql, qr);
    update(v << 1 | 1, m + 1, r, i, ql, qr);
}

void solve(int v, int l, int r) {
    if(l == r) {
        pre[l] = suf[r] = {a[l]};
        for(auto it : qs[v]) {
            res[it.second] = a[l];
        }
        return;
    }
    int m = (l + r) >> 1;

    solve(v << 1, l, m);
    solve(v << 1 | 1, m + 1, r);

    for(auto it : qs[v]) {
        if(it.first.first <= m && it.first.second > m) {
            res[it.second] = merge(suf[it.first.first], pre[it.first.second]);
        }
    }

    for(int i = m + 1;i <= r;i++) {
        pre[i] = pre[i - 1];
        add(pre[i], a[i]);
    }

    for(int i = m;i >= l;i--) {
        suf[i] = suf[i + 1];
        add(suf[i], a[i]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

//     cin >> n;
    n = readInt();
//    n = 10000;

    mt19937 rnd(time(NULL));

    for(int i = 1;i <= n;i++) {
//         cin >> a[i];
        a[i] = readInt();
//        a[i] = rnd() % X;
    }

    int q;

//     cin >> q;
    q = readInt();

//    q = 5e5;

//    vector< pair< pii, int > > qs;

    for(int iter = 1;iter <= q;iter++) {
        int l, r;
//        cin >> l >> r;
        l = readInt();
        r = readInt();
//        qs.push_back({{l, r}, iter});
        update(1, 1, n, iter, l, r);
    }

    solve(1, 1, n);

    for(int i = 1;i <= q;i++) {
        writeInt(res[i], '\n');
    }

    return 0;
}