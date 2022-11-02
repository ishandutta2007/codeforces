//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k,ch[100005][26],cht=1;char c[100005],win[100005],los[100005];
inline void ins(char *c)
{
	int n=strlen(c+1),x=1;
	for(int i=1;i<=n;i++)
	{
		if(!ch[x][c[i]-'a']) ch[x][c[i]-'a']=++cht;
		x=ch[x][c[i]-'a'];
	}
}
inline int dfswin(int x)
{
	for(int i=0;i<26;i++) if(ch[x][i]) if(!dfswin(ch[x][i])) return win[x]=1;
	return win[x];
}
inline int dfslos(int x)
{
	int tag=0;
	for(int i=0;i<26;i++) if(ch[x][i]) {if(!dfslos(ch[x][i])) return los[x]=1;else tag=1;}
	if(tag) return los[x]=0;else return los[x]=1;
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++) scanf("%s",c+1),ins(c);
	dfswin(1),dfslos(1);
	if(win[1]&&los[1]) return puts("First"),0;
	if(win[1]&&!los[1]) return puts(k&1?"First":"Second");
	return puts("Second"),0;
}