#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<complex>
using namespace std;
namespace fastIO
{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
	#define IL inline
	//fread->read
	bool IOerror=0;
	IL char nc()
	{
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);if(pend==p1){IOerror=1;return -1;}}
		return *p1++;
	}
	IL bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	IL void read(int&x)
	{
		bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(sign)x=-x;
	}
	IL void read(ll&x)
	{
		bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';if(sign)x=-x;
	}
	IL void read(double&x)
	{
		bool sign=0;char ch=nc();x=0;for(;blank(ch);ch=nc());if(IOerror)return;
		if(ch=='-')sign=1,ch=nc();for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){double tmp=1;ch=nc();for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');}if(sign)x=-x;
	}
	IL void read(char*s){char ch=nc();for(;blank(ch);ch=nc());if(IOerror)return;for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;*s=0;}
	IL void read(char&c){for(c=nc();blank(c);c=nc());if(IOerror){c=-1;return;}}
	//getchar->read
	IL void read1(int&x)
	{
		char ch;int bo=0;x=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')bo=1;
		for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());if(bo)x=-x;
	}
	IL void read1(ll&x)
	{
		char ch;int bo=0;x=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')bo=1;
		for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());if(bo)x=-x;
	}
	IL void read1(double&x)
	{
		char ch;int bo=0;x=0;for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')bo=1;for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
		if(ch=='.'){double tmp=1;for(ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());}if(bo)x=-x;
	}
	IL void read1(char*s){char ch=getchar();for(;blank(ch);ch=getchar());for(;!blank(ch);ch=getchar())*s++=ch;*s=0;}
	IL void read1(char&c){for(c=getchar();blank(c);c=getchar());}
	//scanf->read
	IL void read2(int&x){scanf("%d",&x);}
	IL void read2(ll&x)
	{
		#ifdef _WIN32
			scanf("%I64d",&x);
		#else
		#ifdef __linux
			scanf("%lld",&x);
		#else
			puts("error:can't recognize the system!");
		#endif
		#endif
	}
	IL void read2(double&x){scanf("%lf",&x);}
	IL void read2(char*s){scanf("%s",s);}
	IL void read2(char&c){scanf(" %c",&c);}
	IL void readln2(char*s){gets(s);}
	//fwrite->write
	struct Ostream_fwrite
	{
		char *buf,*p1,*pend;
		IL Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
		IL void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		IL void write(int x){static char s[15],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
		IL void writeln(int x){static char s[15],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);out('\n');}
		IL void write(ll x){static char s[25],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);}
		IL void writeln(ll x){static char s[25],*s1;s1=s;if(!x)*s1++='0';if(x<0)out('-'),x=-x;while(x)*s1++=x%10+'0',x/=10;while(s1--!=s)out(*s1);out('\n');}
		IL void write(double x,int y)
		{
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if(x<-1e-12)out('-'),x=-x;x*=mul[y];ll x1=(ll)floor(x);if(x-floor(x)>=0.5)++x1;ll x2=x1/mul[y],x3=x1-x2*mul[y];write(x2);
			if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);write(x3);}
		}
		IL void writeln(double x,int y){write(x,y);out('\n');}
		IL void write(char*s){while(*s)out(*s++);}
		IL void writeln(char*s){while(*s)out(*s++);out('\n');}
		IL void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		IL ~Ostream_fwrite(){flush();}
	}Ostream;
	IL void write(int x){Ostream.write(x);}
	IL void writeln(int x){Ostream.writeln(x);}
	IL void write(char x){Ostream.out(x);}
	IL void writeln(char x){Ostream.out(x);Ostream.out('\n');}
	IL void write(ll x){Ostream.write(x);}
	IL void writeln(ll x){Ostream.writeln(x);}
	IL void write(double x,int y){Ostream.write(x,y);}
	IL void writeln(double x,int y){Ostream.writeln(x,y);}
	IL void write(char*s){Ostream.write(s);}
	IL void writeln(char*s){Ostream.writeln(s);}
	IL void writeln(){Ostream.out('\n');}
	IL void flush(){Ostream.flush();}
	//puts->write
	char Out[OUT_SIZE],*o=Out;
	IL void write1(int x){static char buf[15];char *p1=buf;if(!x)*p1++='0';if(x<0)*o++='-',x=-x;while(x)*p1++=x%10+'0',x/=10;while(p1--!=buf)*o++=*p1;}
	IL void writeln1(int x){write1(x);*o++='\n';}
	IL void write1(ll x){static char buf[25];char *p1=buf;if(!x)*p1++='0';if(x<0)*o++='-',x=-x;while(x)*p1++=x%10+'0',x/=10;while(p1--!=buf)*o++=*p1;}
	IL void writeln1(ll x){write1(x);*o++='\n';}
	IL void write1(char c){*o++=c;}
	IL void writeln1(char c){*o++=c;*o++='\n';}
	IL void write1(char*s){while(*s)*o++=*s++;}
	IL void writeln1(char*s){write1(s);*o++='\n';}
	IL void writeln1(){*o++='\n';}
	IL void flush1(){if(o!=Out){if(*(o-1)=='\n')*--o=0;puts(Out);}}
	struct puts_write{IL ~puts_write(){flush1();}}_puts;
	//printf->write
	IL void write2(int x){printf("%d",x);}
	IL void writeln2(int x){printf("%d\n",x);}
	IL void write2(char x){printf("%c",x);}
	IL void writeln2(char x){printf("%c\n",x);}
	IL void write2(ll x)
	{
		#ifdef _WIN32
			printf("%I64d",x);
		#else
		#ifdef __linux
			printf("%lld",x);
		#else
			puts("error:can't recognize the system!");
		#endif
		#endif
	}
	IL void writeln2(ll x){write2(x);printf("\n");}
	IL void writeln2(){printf("\n");}
	#undef IL
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
const int maxn = 111111;
int id[11][11];
typedef int mat[55][4];
struct node {
	node *l, *r;
	int L,R;
	mat c;
	node(int x, int cc):l(0),r(0),L(x),R(x) {
		memset(c,0,sizeof c);
		for(int i = 1; i <= 10; ++i) {
			c[id[i][x%i]][cc] += 1;
		}
	}
	node(node*l, node*r):l(l),r(r),L(l->L),R(r->R) {
		for(int i = 0; i < 55; ++i) {
			for(int j = 0; j < 4; ++j) {
				c[i][j] = l->c[i][j] + r->c[i][j];
			}
		}
	}
};
node *build(int *a, int L, int R) {
	if(L==R) return new node(L, a[L]);
	int mid = (L+R)/2;
	return new node(build(a,L,mid), build(a, mid+1, R));
}
void fix(node *a, int x, int s, int t) {
	if(x<a->L) return;
	if(x>a->R) return;
	for(int i = 1; i <= 10; ++i) {
		a->c[id[i][x%i]][s] -= 1;
		a->c[id[i][x%i]][t] += 1;
	}
	if(a->L == a->R) return;
	fix(a->l, x, s, t);
	fix(a->r, x, s, t);
}
int query(node *a, int L, int R, int *s, int d) {
	if(L<a->L) L=a->L;
	if(R>a->R) R=a->R;
	if(L>R) return 0;
	if(L==a->L && R==a->R) {
		int ans = 0;
		for(int i = 0; i < d; ++i) {
			ans += a->c[id[d][i]][s[i]];
		}
		return ans;
	} else {
		return query(a->l, L,R,s,d) + query(a->r, L,R,s,d);
	}
}
int cc[256];
char sss[maxn]; int n;
int ss[maxn];
char ggg[233];
int gg[233], tg[233];
int main() {
	cc['A'] = 0;
	cc['T'] = 1;
	cc['G'] = 2;
	cc['C'] = 3;
	memset(id, 0x3f, sizeof id);
	int tot = 0;
	for(int i = 1; i <= 10; ++i) {
		for(int j = 0; j < i; ++j) {
			id[i][j] = tot++;
		}
	}
	scanf("%s", sss);
	n = strlen(sss);
	for(int i = 1; i <= n; ++i) {
		ss[i] = cc[sss[i-1]];
	}
	node *r = build(ss, 1, n);
	int q; scanf("%d", &q);
	for(int qq = 1; qq <= q; ++qq) {
		int t,x;
		scanf("%d%d",&t, &x);
		if(t==1) {
			scanf("%s", ggg);
			int y = cc[ggg[0]];
			fix(r, x, ss[x], y);
			ss[x] = y;
		} else {
			int y;
			scanf("%d%s", &y, ggg);
			int pl = strlen(ggg);
			for(int i = 0; i < pl; ++i) tg[i] = cc[ggg[i]];
			int of = x %pl;
			// tg xhyw of
			for(int i = 0; i < pl; ++i) {
				gg[(i + of) % pl] = tg[i];
			}
			printf("%d\n", query(r, x, y, gg, pl));
		}
	}
	return 0;
}