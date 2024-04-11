//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#include <sys/time.h>  
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
long long getCurrentTime()  
{  
   struct timeval tv;  
   gettimeofday(&tv,NULL);  
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;  
}  
int sushu(int k)
{
	for (int i=2;i*i<=k;i++)
		if (k%i==0) return 0;
	return 1;
}
mt19937_64 rnd(getCurrentTime());
int f[N],Z[N],z[N],pow10[N];
int n,m,s;
string st,st1;
int mod;
int query(int l,int r)
{
	return (f[r]-f[l-1]*pow10[r-l+1]%mod+mod)%mod;
}
void Z_init()
{
	string st2=st1+st;
	int l=0,r=0;
	z[0]=0;
	for (int i=1;i<st2.size();i++)
	{
		z[i]=0;
		if (i>r)
		{
			int now=i;
			while (now<st2.size())
			{
				if (st2[now]!=st2[now-i]) break;
				z[i]++;
				now++;
			}
		} else
		{
			if (z[i-l]<r-i+1) z[i]=z[i-l];
			else
			{
				z[i]=r-i+1;
				for (int now=r+1;now<st2.size();now++)
				{
					if (st2[now]!=st2[z[i]]) break;
					z[i]++;
				}
			}
		}
		if (i+z[i]-1>r) r=i+z[i]-1,l=i;
	}
	for (int i=m+1;i<st2.size();i++)
		Z[i-m]=z[i];
}
void ret(int x,int y,int l,int r)
{
	writesp(x);writeln(y);
	writesp(l);writeln(r);
	exit(0);
}
signed main()
{
	cin>>st;
	mod=rnd()%500000000+500000000;
	while (!sushu(mod)) 
	mod=rnd()%500000000+500000000;
	n=st.size();
	st=' '+st;
	pow10[0]=1;
	for (int i=1;i<=n;i++) pow10[i]=pow10[i-1]*10%mod;
	for (int i=1;i<=n;i++)
	{
		f[i]=(f[i-1]*10+(st[i]-'0'))%mod;
	}
	cin>>st1;
	m=st1.length();
	for (auto u:st1) s=(s*10+u-'0')%mod;
//	writeln(s);
//	cout<<query(1,2)<<endl;
	Z_init();
//	for (int i=1;i<=n;i++) cout<<Z[i]<<" ";
//	puts("");
	for (int i=1;i<=n;i++)
	{
		if (i>=m&&i+m-2<=n)
		{
			int x=(query(i-m+1,i-1)+query(i,i+m-2))%mod;
			if (x==s) ret(i-m+1,i-1,i,i+m-2);
		}
		int len=m-Z[i];
		if (len>0&&len<=i-1)
		{
			int x=(query(i-len,i-1)+query(i,i+m-1))%mod;
//			cout<<"?"<<i<<" "<<len<<" "<<x<<endl;
			if (x==s) ret(i-len,i-1,i,i+m-1);
		}
		len--;
		if (len>0&&len<=i-1)
		{
			int x=(query(i-len,i-1)+query(i,i+m-1))%mod;
//			cout<<"?"<<i<<" "<<len<<" "<<x<<endl;
			if (x==s) ret(i-len,i-1,i,i+m-1);
		}
	}
//	cout<<query(3,3)<<endl;
	for (int i=m;i<=n;i++)
	{
		int len=m-Z[i-m+1];
		if (len>0&&len<=n-i)
		{
			int x=(query(i-m+1,i)+query(i+1,i+len))%mod;
//			cout<<"!"<<i<<" "<<x<<" "<<len<<endl;
			if (x==s) ret(i-m+1,i,i+1,i+len);
		}
		len--;
		if (len>0&&len<=n-i)
		{
			int x=(query(i-m+1,i)+query(i+1,i+len))%mod;
//			cout<<"!"<<i<<" "<<x<<" "<<len<<endl;
			if (x==s) ret(i-m+1,i,i+1,i+len);
		}
	}
}
/*

*/