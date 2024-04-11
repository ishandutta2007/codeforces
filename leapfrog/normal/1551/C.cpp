#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n;string s[200005];
struct node{int cnt,len;char operator<(node b) const {return cnt+cnt-len>b.cnt+b.cnt-b.len;}}a[200005];
inline void solve()
{
	read(n);int res=0;for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j].cnt=0,a[j].len=s[j].size();
			for(int k=0;k<a[j].len;k++) a[j].cnt+=s[j][k]==i+'a';
		}
		sort(a+1,a+n+1);int cn=0,tt=0,qw=0;
		for(int j=1;j<=n;j++)
		{
			res=max(res,qw);
			if(cn+a[j].cnt>tt+a[j].len-a[j].cnt)
				cn+=a[j].cnt,tt+=a[j].len-a[j].cnt,qw++;
		}res=max(res,qw);
	}
	printf("%d\n",res);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}