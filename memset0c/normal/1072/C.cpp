// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}


const int maxn = 2000010;
int a, b, ans, lena, lenb, p[maxn], s[maxn];
bool used[maxn];

signed main() {
	read(a), read(b);
	for(int x = 1; x <= 1e5; x++)
		if (a>=x) a-=x,used[x]=true,ans++;
		else {
			used[x] = 1;
			used[x - a] = 0;
			break;
		}
	for(int x=1;x<=1e5;x++) if(used[x]) p[++lena]=x;
	for(int x=1;x<=1e5;x++)
		if(!used[x]&&b>=x) ans++,b-=x,s[++lenb]=x;
//	cout<<ans<<endl;
//	printf("%d\n",ans);
	print(lena, '\n');
	for(int i=1;i<=lena;i++) print(p[i]);
	putc('\n'), print(lenb, '\n');
	for(int i=1;i<=lenb;i++) print(s[i]);
	putc('\n');
    return 0;
}