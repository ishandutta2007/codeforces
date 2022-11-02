//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=105;int n,ls[N],nx[N];char ch[N],vs[N];
inline char chk(int x) {return ch[ls[x]]==ch[x]-1||ch[nx[x]]==ch[x]-1;}
int main()
{
	read(n),scanf("%s",ch+1);int tot=0;
	priority_queue<pair<char,int> >q;
	for(int i=1;i<=n;i++) nx[i]=i+1,ls[i]=i-1;
	for(int i=1;i<=n;i++) if(chk(i)) q.push(make_pair(ch[i],i));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();if(vs[x]) continue;else vs[x]=1,tot++;
		ls[nx[x]]=ls[x],nx[ls[x]]=nx[x];
		if(!vs[ls[x]]&&chk(ls[x])) q.push(make_pair(ch[ls[x]],ls[x]));
		if(!vs[nx[x]]&&chk(nx[x])) q.push(make_pair(ch[nx[x]],nx[x]));
	}
	return printf("%d\n",tot),0;
}