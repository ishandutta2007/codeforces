#include <iostream>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <set>
#define MN 10100000

typedef long long ll;

namespace IO {
    const int lim = 1 << 20;
     
    char buf[lim + 5], *S, *T;
     
    inline char gc() {
        if (S == T) {
            T = (S = buf) + fread(buf, 1, lim, stdin);
            if (S == T)
                return EOF;
        }
        return *S++;
    }
     
    inline int read() {
        int x;
        bool f;
        char c;
        for (f = 0; (c = gc()) < '0' || c > '9'; f = c == '-')
            ;
        for (x = c ^ '0'; (c = gc()) >= '0' && c <= '9'; x = (x << 1) + (x << 3) + (c ^ '0'))
            ;
        return f ? -x : x;
    }
    
    inline int readc() {
        int x;
        bool f;
        char c;
        for (f = 0; (c = gc()) < '0' || c > '9'; f = c == '-')
            ;
        return c;
    }
}

using namespace IO;

char s[MN];
ll f[MN];
int q[MN], h = 0, t = -1;

int main()
{
	int n = read(), k = read();
	k = std::min(k, n);
	for(int i = 1; i <= n; i++) s[i] = readc();
	f[0] = 0;
	h = 0; t = -1;
	q[++t] = 0;
	ll ans = 1e18;
	for(int i = 1; i <= n + k; i++)
	{
		f[i] = f[i - 1] + i;
		if(s[i - k] == '1')
		{
			while(h <= t && q[h] < i - 2 * k - 1) h++;
			if(h <= t) f[i] = std::min(f[i], f[q[h]] + i - k);
		}
		while(h <= t && f[q[t]] >= f[i]) t--;
		q[++t] = i;
		if(i >= n) ans = std::min(ans, f[i]);
	}
	printf("%lld\n", ans);
}