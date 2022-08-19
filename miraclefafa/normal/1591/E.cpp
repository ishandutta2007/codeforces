#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

namespace fastIO{ 
	#define BUF_SIZE 100000 
	#define OUT_SIZE 100000 
	#define ll long long 
	//fread->read 
	bool IOerror=0; 
	inline char nc(){ 
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
		if (p1==pend){ 
			p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
			if (pend==p1){IOerror=1;return -1;} 
			//{printf("IO error!\n");system("pause");for (;;);exit(0);} 
		} 
		return *p1++; 
	} 
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
	inline void read(int &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(ll &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (sign)x=-x; 
	} 
	inline void read(double &x){ 
		bool sign=0; char ch=nc(); x=0; 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		if (ch=='-')sign=1,ch=nc(); 
		for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
		if (ch=='.'){ 
			double tmp=1; ch=nc(); 
			for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
		} 
		if (sign)x=-x; 
	} 
	inline void read(char *s){ 
		char ch=nc(); 
		for (;blank(ch);ch=nc()); 
		if (IOerror)return; 
		for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
		*s=0; 
	} 
	inline void read(char &c){ 
		for (c=nc();blank(c);c=nc()); 
		if (IOerror){c=-1;return;} 
	} 
	//getchar->read 
	inline void read1(int &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(ll &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (bo)x=-x; 
	} 
	inline void read1(double &x){ 
		char ch;int bo=0;x=0; 
		for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1; 
		for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar()); 
		if (ch=='.'){ 
			double tmp=1; 
			for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar()); 
		} 
		if (bo)x=-x; 
	} 
	inline void read1(char *s){ 
		char ch=getchar(); 
		for (;blank(ch);ch=getchar()); 
		for (;!blank(ch);ch=getchar())*s++=ch; 
		*s=0; 
	} 
	inline void read1(char &c){for (c=getchar();blank(c);c=getchar());} 
	//scanf->read 
	inline void read2(int &x){scanf("%d",&x);} 
	inline void read2(ll &x){ 
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
	inline void read2(double &x){scanf("%lf",&x);} 
	inline void read2(char *s){scanf("%s",s);} 
	inline void read2(char &c){scanf(" %c",&c);} 
	//inline void readln2(char *s){gets(s);} 
	//fwrite->write 
	struct Ostream_fwrite{ 
		char *buf,*p1,*pend; 
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
		void out(char ch){ 
			if (p1==pend){ 
				fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
			} 
			*p1++=ch; 
		} 
		void print(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(int x){ 
			static char s[15],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); out('\n'); 
		} 
		void print(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); 
		} 
		void println(ll x){ 
			static char s[25],*s1;s1=s; 
			if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
			while(x)*s1++=x%10+'0',x/=10; 
			while(s1--!=s)out(*s1); out('\n'); 
		} 
		void print(double x,int y){ 
			static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
				1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
				100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
			if (x<-1e-12)out('-'),x=-x;x*=mul[y]; 
			ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
			ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
			if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];++i) out('0'); print(x3);} 
		} 
		void println(double x,int y){print(x,y);out('\n');} 
		void print(char *s){while (*s)out(*s++);} 
		void println(char *s){while (*s)out(*s++);out('\n');} 
		void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
		~Ostream_fwrite(){flush();} 
	}Ostream; 
	inline void print(int x){Ostream.print(x);} 
	inline void println(int x){Ostream.println(x);} 
	inline void print(char x){Ostream.out(x);} 
	inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
	inline void print(ll x){Ostream.print(x);} 
	inline void println(ll x){Ostream.println(x);} 
	inline void print(double x,int y){Ostream.print(x,y);} 
	inline void println(double x,int y){Ostream.println(x,y);} 
	inline void print(char *s){Ostream.print(s);} 
	inline void println(char *s){Ostream.println(s);} 
	inline void println(){Ostream.out('\n');} 
	inline void flush(){Ostream.flush();} 
	//puts->write 
	char Out[OUT_SIZE],*o=Out; 
	inline void print1(int x){ 
		static char buf[15]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(int x){print1(x);*o++='\n';} 
	inline void print1(ll x){ 
		static char buf[25]; 
		char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x; 
		while(x)*p1++=x%10+'0',x/=10; 
		while(p1--!=buf)*o++=*p1; 
	} 
	inline void println1(ll x){print1(x);*o++='\n';} 
	inline void print1(char c){*o++=c;} 
	inline void println1(char c){*o++=c;*o++='\n';} 
	inline void print1(char *s){while (*s)*o++=*s++;} 
	inline void println1(char *s){print1(s);*o++='\n';} 
	inline void println1(){*o++='\n';} 
	inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}} 
	struct puts_write{ 
		~puts_write(){flush1();} 
	}_puts; 
	inline void print2(int x){printf("%d",x);} 
	inline void println2(int x){printf("%d\n",x);} 
	inline void print2(char x){printf("%c",x);} 
	inline void println2(char x){printf("%c\n",x);} 
	inline void print2(ll x){ 
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
	inline void println2(ll x){print2(x);printf("\n");} 
	inline void println2(){printf("\n");} 
	#undef ll 
	#undef OUT_SIZE 
	#undef BUF_SIZE 
}; 
using namespace fastIO; 


const int N=1010000;
int c[N],a[N],n,q,ans[N],cnt[N];
set<int> num[N];
vector<array<int,3>> que[N];
VI son[N];
void modify(int x,int s) {
	assert(x);
	for (;x<=n;x+=x&-x) c[x]+=s;
}

int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}
int query2(int val) {
	int pos=0;
	per(j,0,20) if (pos+(1<<j)<=n&&c[pos+(1<<j)]<val) {
		pos+=(1<<j);
		val-=c[pos];
	}
	return pos;
}


void dfs(int u) {
	int cc=cnt[a[u]];
	if (cc!=0) {
		modify(cc,-1);
		if (num[cc].count(a[u])) num[cc].erase(a[u]);
	}
	cnt[a[u]]++;
	cc++;
	modify(cc,1);
	num[cc].insert(a[u]);
	for (auto x:que[u]) {
		int id=x[2],l=x[0],k=x[1];
		int pos=query2(query(l-1)+k)+1; // k ? k-1
		if (pos==n+1) ans[id]=-1;
		else {
			assert(!num[pos].empty());
			ans[id]=*num[pos].begin();
		}
	}

	for (auto x:son[u]) dfs(x);

	modify(cc,-1);
	num[cc].erase(a[u]);
	--cc; --cnt[a[u]];
	if (cc) modify(cc,1);
	num[cc].insert(a[u]);

}

void solve() {
	read(n); read(q);
	rep(i,1,n+1) read(a[i]);
	rep(i,1,n+1) son[i].clear(),que[i].clear();
	rep(i,2,n+1) {
		int p;
		read(p);
		son[p].pb(i);
	}
	rep(i,1,n+1) c[i]=0;
	rep(i,0,n+1) num[i].clear();
	rep(i,0,q) {
		int v,l,k;
		read(v); read(l); read(k);
		que[v].pb({l,k,i});
	}
	rep(i,1,n+1) cnt[i]=0;
	dfs(1);
	rep(i,0,q) println(ans[i]);
}

int _;
int main() {
	for (read(_);_;_--) {
		solve();
	}
}