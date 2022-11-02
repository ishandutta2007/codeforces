//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int a,b,c,n;char s[1000005],t[1000005];
int main()
{
	read(a),read(b),read(c),n=a+b;
	if(c==0)
	{
		puts("Yes");
		for(int i=1;i<=b;i++) putchar('1');
		for(int i=1;i<=a;i++) putchar('0');
		putchar('\n');
		for(int i=1;i<=b;i++) putchar('1');
		for(int i=1;i<=a;i++) putchar('0');
		return putchar('\n'),0;
	}
	if(a==0||b==1) return puts("No"),0;
	for(int i=1;i<=n;i++) s[i]=t[i]='0';
	if(a<c)
	{
		int d=c-a;b-=d;
		if(b<=1) return puts("No"),0;
		for(int i=1;i<b;i++) s[i]=t[i]='1';
		s[b]='1',t[n]='1';
		for(int i=b+1;i<=b+d;i++) s[i]=t[i]='1';
		return printf("Yes\n%s\n%s\n",s+1,t+1),0;
	}
	s[n-c]=t[n]='1';
	for(int i=1;i<b;i++) s[i]=t[i]='1';
	for(int i=b;i<n-c;i++) s[i]=t[i]='0';
	return printf("Yes\n%s\n%s\n",s+1,t+1),0;
}