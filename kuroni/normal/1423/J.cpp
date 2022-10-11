#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;

int prec[1000100];
int main() {
    prec[0] = 1;
    for (int i = 1; i < 1000100; ++i) {
       for (int z = i&1; z <= min(7, i); z += 2) {
          prec[i] += prec[(i-z)>>1];
          if (prec[i] >= MOD) prec[i] -= MOD;
       }
    }
    int T; read(T);
    while (T--) {
        int64_t N; read(N);
        int64_t lo = N, hi = N;
        array<int, 7> dp{};
        dp[0] = 1;
        while (true) {
           if (hi < 1000100) {
              int ans = 0;
              for (int i = lo; i <= hi; ++i) {
                 ans = (ans + int64_t(dp[i-lo]) * prec[i]) % MOD;
              }
write(ans, '\n');              break;
           } 
            int64_t nlo = max<int64_t>(lo - 6, 0) >> 1;
            int64_t nhi = hi >> 1;
            array<int, 7> ndp{};
            for (int64_t i = lo; i <= hi; ++i) {
                int64_t l = (max<int64_t>(i-6, nlo << 1) >> 1) - nlo;
                int64_t r = (i >> 1) - nlo;
                ndp[l] += dp[i-lo];
                ndp[r+1] -= dp[i-lo];
                if (ndp[l] >= MOD) ndp[l] -= MOD;
                if (ndp[r+1] < 0) ndp[r+1] += MOD;
            }
            for (int i = 1; i <= nhi - nlo; ++i) {
               ndp[i] += ndp[i-1];
               if (ndp[i] >= MOD) ndp[i] -= MOD;
            }
            lo = nlo;
            hi = nhi;
            dp = ndp;
        }
    }
}