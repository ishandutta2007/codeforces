//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define ull ll
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 1204
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int cnt,c[N];
vector<string>ans;
int XOR(int x,int y)
{
	if (x>0&&y>0) 
		ans.push_back(to_string((long long)x)+" ^ "+to_string((long long)y));
	return x^y;
}
int ad(int x,int y)
{
	if (x>0&&y>0) 
		ans.push_back(to_string((long long)x)+" + "+to_string((long long)y));
	return x+y;
}
void ins(int x)
{
	for (int i=0;i<40;i++)
		if (x&(1ll<<i))
		{
			if (!c[i]) 
			{
				c[i]=x;
				cnt++;
				return;
			}
			x=XOR(c[i],x);
		}
}
				
ull rnd(ull &k1, ull &k2) {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
signed main()
{
	int n=read();
	srand(114518);
	ins(n);
	while (cnt<40)
	{
		int x=1e17,y=1e17;
		while (x+y>=(1ll<<40))
		{
			int p=0;
			for (int i=0;i<40;i++)
				if (rand()%2) p+=(1ll<<i);
			x=0;
			for (int i=0;i<40;i++)
				if ((p>>i)%2) 
					x=XOR(c[i],x);
					p=0;
			for (int i=0;i<40;i++)
				if (rand()%2) p+=(1ll<<i);
			y=0;
			for (int i=0;i<40;i++)
				if ((p>>i)%2) 
					y=XOR(c[i],y);
//			cout<<x<<" "<<y<<" "<<p<<endl;
		}
		ins(ad(x,y));
	}
//	cout<<rand()<<endl;
	int now=1,p=0;
	for (int i=0;i<40;i++)
		if ((now>>i)%2) now^=c[i],p=XOR(p,c[i]);
	writeln(ans.size());
	for (auto u:ans) cout<<u<<endl;
}
/*

*/