#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LB long double
#define ull unsigned long long
#define x first
#define y second
#define pb push_back
#define pf push_front
#define mp make_pair
#define Pair pair<int,int>
#define pLL pair<LL,LL>
#define pii pair<double,double>
#define LOWBIT(x) x & (-x)
// #define LOCAL true

const int INF=2e9;
const LL LINF=2e16;
const int magic=348;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);

struct fastio
{
	static const int S=1e7;
	char rbuf[S+48],wbuf[S+48];int rpos,wpos,len;
	fastio() {rpos=len=wpos=0;}
	inline char Getchar()
	{
		if (rpos==len) rpos=0,len=fread(rbuf,1,S,stdin);
		if (!len) return EOF;
		return rbuf[rpos++];
	}
	template <class T> inline void Get(T &x)
	{
		char ch;bool f;T res;
		while (!isdigit(ch=Getchar()) && ch!='-') {}
		if (ch=='-') f=false,res=0; else f=true,res=ch-'0';
		while (isdigit(ch=Getchar())) res=res*10+ch-'0';
		x=(f?res:-res);
	}
	inline void getstring(char *s)
	{
		char ch;
		while ((ch=Getchar())<=32) {}
		for (;ch>32;ch=Getchar()) *s++=ch;
		*s='\0';
	}
	inline void flush() {fwrite(wbuf,1,wpos,stdout);fflush(stdout);wpos=0;}
	inline void Writechar(char ch)
	{
		if (wpos==S) flush();
		wbuf[wpos++]=ch;
	}
	template <class T> inline void Print(T x,char ch)
	{
		char s[20];int pt=0;
		if (x==0) s[++pt]='0';
		else
		{
			if (x<0) Writechar('-'),x=-x;
			while (x) s[++pt]='0'+x%10,x/=10;
		}
		while (pt) Writechar(s[pt--]);
		Writechar(ch);
	}
	inline void printstring(char *s)
	{
		int pt=1;
		while (s[pt]!='\0') Writechar(s[pt++]);
	}
}io;

template<typename T> inline void check_max(T &x,T cmp) {x=max(x,cmp);}
template<typename T> inline void check_min(T &x,T cmp) {x=min(x,cmp);}
template<typename T> inline T myabs(T x) {return x>=0?x:-x;}

const int MAXN=1e5;

int n;
string s[MAXN+48];int Mask[MAXN+48];
int cnt[48];
map<int,int> Mp;

int main ()
{
#ifdef LOCAL
	double TIME=clock();
	freopen ("a.in","r",stdin);
	freopen ("a.out","w",stdout);
	cerr<<"Running..."<<endl;
#endif
	ios::sync_with_stdio(false);
	cin>>n;Mp.clear();
	for (register int i=1;i<=n;i++)
	{
		cin>>s[i];
		// cerr<<s[i]<<endl;
		for (register int j=1;j<=26;j++) cnt[j]=0;
		for (register int j=0;j<int(s[i].size());j++) cnt[s[i][j]-'a'+1]++;
		Mask[i]=0;for (register int j=1;j<=26;j++) if (cnt[j]%2==1) Mask[i]|=(1<<(j-1));
		// cerr<<i<<' '<<Mask[i]<<endl;
		Mp[Mask[i]]++;
	}
	// cerr<<Mp.size()<<endl;
	int full=(1<<26)-1;LL ans1=0,ans2=0;
	for (map<int,int>::iterator iter=Mp.begin();iter!=Mp.end();iter++)
	{
		int vvv=(iter->y);
		ans1+=1ll*vvv*(vvv-1)/2;
		for (register int j=1;j<=26;j++)
		{
			int vv=(iter->x);
			int toMask=(vv^(1<<(j-1)));
			if (Mp.find(toMask)!=Mp.end()) ans2+=1ll*vvv*(Mp[toMask]);
		}
	}
	// cerr<<ans1<<' '<<ans2<<endl;
	cout<<ans1+ans2/2<<endl;
	// io.flush();
#ifdef LOCAL
	cerr<<"Exec Time: "<<(clock()-TIME)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}