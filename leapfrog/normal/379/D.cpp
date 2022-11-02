//why xtw always boom zero
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,x,k;
struct node
{
	long long A,B,AB,BA,AA,BB;char s,t;
	inline node operator+(node b)
	{
		node c=(node){A+b.A,B+b.B,AB+b.AB,BA+b.BA,AA+b.AA,BB+b.BB,s,b.t};
		if(t=='A'&&b.s=='B') c.AB++;else if(t=='B'&&b.s=='A') c.BA++;
		if(t=='A'&&b.s=='A') c.AA++;else if(t=='B'&&b.s=='B') c.BB++;
		return c;
	}
}f[55];
inline long long slv(int A,int B,int as,int at,int bs,int bt)
{
	if((!A&&as==1&&at==2)||(!B&&bs==1&&bt==2)) return -1;
	long long res=f[k].A*A+f[k].B*B;
	res+=(at==1)*(bs==2)*f[k].AB,res+=(bt==1)*(as==2)*f[k].BA;
	res+=(at==1)*(as==2)*f[k].AA,res+=(bt==1)*(bs==2)*f[k].BB;
	return res;
}
inline void paint(int n,int L,int s,int t)
{
	if(n==1) return(void)(putchar(s==1?'A':(s==2?'C':'B')),putchar('\n'));
	int l=1;if(s==1) putchar('A');else if(s==2) putchar('C');else putchar('B');
	if(s==1&&t==2)
	{
		for(int i=1;i<L;i++) putchar('C'),putchar('A'),++l,++l;
		for(int i=L+L;i<n;i++) putchar('B'),++l;
	}
	else if(n!=2)
	{
		for(int i=1;i<=L;i++) if(s==1) putchar('C'),++l;else putchar('A'),putchar('C'),++l,++l;
		for(int i=2+L+L;i<n;i++) putchar('B'),++l;
	}
	if(t==1&&l!=n) puts("A");else if(t==2&&l!=n) puts("C");else if(l!=n) puts("B");else putchar('\n');
}
int main()
{
	f[1]=(node){1,0,0,0,0,0,'A','A'},f[2]=(node){0,1,0,0,0,0,'B','B'};
	for(int i=3;i<=50;i++) f[i]=f[i-2]+f[i-1];
	read(k),read(x),read(n),read(m);
	for(int as=0;as<3;as++) for(int bs=0;bs<3;bs++) for(int at=0;at<3;at++) for(int bt=0;bt<3;bt++)
		for(int A=0,ae=(n-(as!=1)-(at!=2))/2;A<=ae;A++) for(int B=0,be=(m-(bs!=1)-(bt!=2))/2;B<=be;B++)
			if(slv(A,B,as,at,bs,bt)==x&&(n!=1||as==at)&&(m!=1||bs==bt)) return paint(n,A,as,at),paint(m,B,bs,bt),0;
	return puts("Happy new year!"),0;
}