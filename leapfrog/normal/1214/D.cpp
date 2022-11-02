//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m;const int P=1019260817;vector<string>ch;vector<pair<int,int> >nw,ed,tp;
inline char dfs(int x,int y)
{
	if(x==n&&y==m) return 1;else if(x>n||y>m||ch[x][y]=='#') return 0;
	return ch[x][y]=(x!=1||y!=1?'#':ch[x][y]),dfs(x+1,y)||dfs(x,y+1);
}
int main()
{
	read(n),read(m);string s;ch.push_back("?");
	for(int i=1;i<=n;i++) cin>>s,ch.push_back('0'+s);
	if(!dfs(1,1)) return puts("0"),0;
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%c%c",ch[i][j],j==m?'\n':' ');
	else if(!dfs(1,1)) return puts("1"),0;
	else return puts("2"),0;
}