#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K,rs,a[100005];char s[100005];
inline void solve()
{
	scanf("%s",s+1),n=strlen(s+1);int on=0;
	for(int i=1;i<=26;i++) a[i]=0;
	for(int i=1;i<=n;i++) a[s[i]-'a'+1]++;
	for(int i=1;i<=26;i++) if(a[i]==1&&!on) on=i;
	if(on)
	{
		putchar(on+'a'-1);for(int i=1;i<=26;i++) if(i^on)
			for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
		return putchar('\n'),void();
	}
	int cnt=0;for(int i=1;i<=26;i++) if(a[i]) cnt++;
	if(cnt==1) {for(int i=1;i<=n;i++) putchar(s[i]);return putchar('\n'),void();}
	if(cnt==2)
	{
		int x=0,y=0;for(int i=1;i<=26;i++) if(a[i]) {x=i;break;}
		for(int i=x+1;i<=26;i++) if(a[i]) {y=i;break;}
		if(a[x]>a[y]+2)
		{
			putchar(x+'a'-1),a[x]--;
			for(int i=1;i<=a[y];i++) putchar(y+'a'-1);
			for(int i=1;i<=a[x];i++) putchar(x+'a'-1);
			return putchar('\n'),void();
		}
		else
		{
			putchar(x+'a'-1),putchar(x+'a'-1),a[x]-=2;
			for(int i=1;i<=a[x];i++) putchar(y+'a'-1),putchar(x+'a'-1);
			for(int i=a[x]+1;i<=a[y];i++) putchar(y+'a'-1);
			return putchar('\n'),void();
		}
	}
	if(cnt>=3)
	{
		int x=0,y=0,z=0;
		for(int i=1;i<=26;i++) if(a[i]) {x=i;break;}
		for(int i=x+1;i<=26;i++) if(a[i]) {y=i;break;}
		for(int i=y+1;i<=26;i++) if(a[i]) {z=i;break;}
		if(a[x]>n-a[x]+2)
		{
			putchar(x+'a'-1),putchar(y+'a'-1);
			for(int i=1;i<a[x];i++) putchar(x+'a'-1);
			putchar(z+'a'-1),a[y]--,a[z]--;
			for(int i=x+1;i<=26;i++) for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
			return putchar('\n'),void();
		}
		else
		{
			putchar(x+'a'-1),putchar(x+'a'-1),putchar(y+'a'-1),a[x]-=2,a[y]--;
			while(a[x])
			{
				putchar(x+'a'-1);while(!a[y]) {y++;if(y>26) break;}
				a[y]--;a[x]--;if(y<=26) putchar(y+'a'-1);
			}
			for(int i=x+1;i<=26;i++) for(int j=1;j<=a[i];j++) putchar(i+'a'-1);
			return putchar('\n'),void();
		}
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}