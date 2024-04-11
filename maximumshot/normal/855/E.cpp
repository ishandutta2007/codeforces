#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

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
        //inline void * operator new [] ( size_t ) { assert(0); }
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

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int const B = 11;
int const M = 1 << B;
int const L = 70;

ll dp[B][L][M];
ll f[B][L][M][B];

void prepare() {
    for(int base = 2;base <= 10;base++) {
        dp[base][0][0] = 1;
        for(int l = 1;l < L;l++) {
            for(int x = 0;x < base;x++) {
                for(int mask = 0;mask < (1 << base);mask++) {
                    dp[base][l][mask ^ (1 << x)] += dp[base][l - 1][mask];
                }
            }
        }

        for(int x = 0;x < base;x++) {
            f[base][1][1 << x][x] = 1;
        }
        for(int l = 2;l < L;l++) {
            for(int x = 1;x < base;x++) {
                for(int mask = 0;mask < (1 << base);mask++) {
                    f[base][l][mask ^ (1 << x)][x] += dp[base][l - 1][mask];
                }
            }
        }
    }
}

ll get(vec< int > n, int base) {
    int sz = (int)n.size();
    int cur = 0;
    ll res = 0;
    for(int l = 1;l < sz;l++) {
        for(int x = 1;x < base;x++) {
            res += f[base][l][0][x];
        }
    }
    for(int i = 0;i < sz;i++) {
        for(int x = i == 0;x < n[i];x++) {
            res += dp[base][sz - i - 1][cur ^ (1 << x)];
        }
        cur ^= (1 << n[i]);
    }
    return res;
}

ll simple(ll n, int base) {
    ll res = 0;
    for(ll x = 1;x < n;x++) {
        int cur = 0;
        ll y = x;
        while(y > 0) {
            cur ^= (1 << (y % base));
            y /= base;
        }
        if(cur == 0) {
            res++;
        }
    }
    return res;
}

vec< int > toVector(ll x, int base) {
    vec< int > res;
    while(x > 0) {
        res.push_back(x % base);
        x /= base;
    }
    reverse(ALL(res));
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#else
#endif

    prepare();

    int q = readInt();

    ll l, r, res;

    for(int b, i = 0;i < q;i++) {
        b = readInt<int>();
        l = readInt<ll>();
        r = readInt<ll>();
        res = get(toVector(r + 1, b), b);
        if(l > 1) {
            res -= get(toVector(l, b), b);
        }
        writeInt<ll>(res, '\n');
    }

    return 0;
}