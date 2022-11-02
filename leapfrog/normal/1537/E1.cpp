//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
char ch[500005];int n,m;
int main()
{
	read(n),read(m),scanf("%s",ch);int wh=1;
	for(int i=0;i<n;i++) if(ch[i]>ch[i%wh]) break;else if(ch[i]<ch[i%wh]) wh=i+1;
	for(int i=0;i<m;i++) putchar(ch[i%wh]);
	putchar('\n');
}