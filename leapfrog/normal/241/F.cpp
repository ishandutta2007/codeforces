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
int n,m,K;pair<int,int>id[35];char ch[105][105],s[1005];
int main()
{
	read(n,m,K);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(ch[i][j]>='a'&&ch[i][j]<='z') id[ch[i][j]-'a']=make_pair(i,j),ch[i][j]=1;
		else if(ch[i][j]>='0'&&ch[i][j]<='9') ch[i][j]^=48;
	int x,y,rx,ry,l;read(x,y);scanf("%s",s+1),read(rx,ry),l=strlen(s+1);
	id[30]=make_pair(rx,ry),s[++l]=30+'a';
	for(int i=1;i<=l&&K>0;i++) while(x!=id[s[i]-'a'].first||y!=id[s[i]-'a'].second)
	{
		if((K-=ch[x][y])<0) break;
		if(x<id[s[i]-'a'].first) x++;else if(x>id[s[i]-'a'].first) x--;
		if(y<id[s[i]-'a'].second) y++;else if(y>id[s[i]-'a'].second) y--;
	}return printf("%d %d\n",x,y),0;
}