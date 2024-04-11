#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

#ifndef _LIB_FASTIO_
#define _LIB_FASTIO_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wconversion"

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

inline unsigned int readUInt() {
	int c = readChar();
	unsigned int x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T = int>
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

inline long long readLong() {
	return readInt<long long>();
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

inline void readWord( string &s ) {
	s.clear();
	int c = readChar();
	while (c > 32)
		s += c, c = getChar();
}

inline bool readLine( char *s ) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

inline bool readLine( string &s ) {
	s.clear();
	int c = getChar();
	while (c != '\n' && c != -1)
		s += c, c = getChar();
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
	if (write_buf_pos) {
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
		fflush(stdout);
	}
}

template <class T> 
inline void writeInt( T x, char end = 0, int output_len = -1) {
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

inline void writeWord(const string& s) {
	writeWord(s.c_str());
}

inline void writeDouble( double x, int output_len = 11) {
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

/** Buffer flusher */

static struct buffer_flusher_t {
	~buffer_flusher_t() {
		flush();
	}
} buffer_flusher;

/** Reader and writer */

struct fast_reader {
    fast_reader& operator>>(int& n) {
        n = readInt(); return *this;
    }
    fast_reader& operator>>(unsigned int& n) {
        n = readUInt(); return *this;
    }
    fast_reader& operator>>(llong& n) {
        n = readLong(); return *this;
    }
	fast_reader& operator>>(double& n) {
        n = readDouble(); return *this;
    }
	fast_reader& operator>>(float& n) {
        n = (float) readDouble(); return *this;
    }
    fast_reader& operator>>(string& s) {
        readWord(s); return *this;
    }
    fast_reader& operator>>(char& c) {
        c = (char) readChar(); return *this;
    }
    template<typename T>
    fast_reader& operator>>(vector<T>& a) {
        for (T& i : a) {
            (*this) >> i;
        }
        return *this;
    }
} f_reader;

struct fast_writer {
    template<typename T>
    fast_writer& operator<<(T n) {
        writeInt(n); return *this;
    }
	fast_writer& operator<<(double n) {
		writeDouble(n); return *this;
	}
	fast_writer& operator<<(float n) {
		writeDouble(n); return *this;
	}
    fast_writer& operator<<(const string& s) {
        writeWord(s); return *this;
    }
    fast_writer& operator<<(const char* s) {
        writeWord(s); return *this;
    }
    fast_writer& operator<<(char c) {
        writeChar(c); return *this;
    }
    template<typename T>
    fast_writer& operator<<(const vector<T>& a) {
        for (size_t i = 0; i < a.size(); ++i) {
            if (i) {
                (*this) << ' ';
            }
            (*this) << a[i];
        }
        return *this;
    }
    void flush() {
        ::flush();
    }
} f_writer;

#define cin f_reader
#define cout f_writer

#pragma GCC diagnostic pop
#endif //_LIB_FASTIO_

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    struct DSU {
        vector<int> a;
        vector<int> r;

        void init(int n) {
            a.resize(n);
            iota(begin(a), end(a), 0);
            r.assign(n, 1);
        }

        int get(int x) {
            return a[x] == x ? x : a[x] = get(a[x]);
        }

        void unite(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return;
            }
            if (r[x] < r[y]) {
                a[x] = y;
            } else {
                a[y] = x;
                if (r[x] == r[y]) {
                    r[x]++;
                }
            }
        }

        bool same(int x, int y) {
            return get(x) == get(y);
        }
    };

    string s;
    cin >> s;
    int n = isz(s);

    DSU d;

    vector<int> used(4 * n);

    const llong M = 998244353;

    llong ans = 0;

    for (int m = 1; m < n; m++) {
        d.init(4 * n);

        for (int i = 0; i < n; i++) {
            d.unite(i, n - 1 - i);
            d.unite(i + n, n - 1 - i + n);
        }

        for (int i = 0; i < m; i++) {
            d.unite(n - m + i + 2 * n, n - m + m - 1 - i + 2 * n);
            d.unite(n - m + i + 3 * n, n - m + m - 1 - i + 3 * n);
        }
        for (int i = 1; i < n - m; i++) {
            d.unite(i + 2 * n, i + 2 * n - 1);
            d.unite(i + 3 * n, i + 3 * n - 1);
        }

        d.unite(2 * n, 3 * n + n - m);
        d.unite(3 * n, 2 * n + n - m);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                d.unite(i, i + 2 * n);
                d.unite(i + n, i + 3 * n);
            } else if (s[i] == '1') {
                d.unite(i, i + 3 * n);
                d.unite(i + n, i + 2 * n);
            }
        }

        fill(begin(used), end(used), 0);
        
        llong cur = 1;

        for (int i = 0; i < n; i++) {
            if (d.same(i, i + n) || d.same(i + 2 * n, i + 3 * n)) {
                cur = 0;
                break;
            }

            int cn = 0;
            int cg = 0;

            for (int j = 0; j < 2; j++) {
                int t = d.get(i + j * n);
                if (!used[t]) {
                    used[t] = 1;
                    cn++;
                    if (!d.same(t, 0)) {
                        cg++;
                    }
                }
            }

            if (cn == 2) {
                cur = cur * cg % M;
            }

            cn = 0;
            cg = 0;

            for (int j = 2; j < 4; j++) {
                int t = d.get(i + j * n);
                if (!used[t]) {
                    used[t] = 1;
                    cn++;
                    if (!d.same(t, 0)) {
                        cg++;
                    }
                }
            }

            if (cn == 2) {
                cur = cur * cg % M;
            }
        }

        ans = (ans + cur) % M;
    }

    cout << ans << "\n";

    return 0;
}