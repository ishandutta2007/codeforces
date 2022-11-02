#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 200010
int n,m;
char s[maxn];
int cnt,pos,len;
inline void add(int t)
{
	s[t]++;
	if (s[t]>'9')	{s[t]='0';add(t-1);}
}
void doit(int x)
{
	if (m==0)	return;
	m--;
	if (x==pos)	{add(x-1);len=x-1;return;}
	add(x);
	len=x;
	if (s[x]>'4')	doit(x-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	s[0]='0';
	len=n;
	for (int i=1;i<=n;i++)
	if (s[i]=='.')	pos=i;
	if (pos==0)	{printf("%s\n",s);return 0;}
	cnt=0;
	for (int i=pos+1;i<=n;i++)
	{
		if (s[i]=='4')	cnt++;else
		if (s[i]>'4')	{doit(i-1);break;}
		if (s[i]<'4')	cnt=0;
	}
	if (s[0]!='0')	putchar(s[0]);
	for (int i=1;i<=len;i++)	putchar(s[i]);
	return 0;
}