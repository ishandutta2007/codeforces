//
#include<bits/stdc++.h>
using namespace std;const long long INF=1e6;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,v[100005][26];char c[100005],s[100005];
inline char jump(int n,char *s,int &i)
{
	int x=0;if(!v[x][s[i]-'a']) return 0;
//	printf("i = %d\n",i);
	for(;i<=n;i++) if(!v[x][s[i]-'a']) return 1;else x=v[x][s[i]-'a'];
	return 1;
}
int main()
{
	for(read(T);T--;)
	{
		scanf("%s%s",c+1,s+1);int n=strlen(c+1),m=strlen(s+1);
		memset(v[n],0,sizeof(v[n]));
		for(int i=n;i>=1;i--) memcpy(v[i-1],v[i],sizeof(v[i])),v[i-1][c[i]-'a']=i;
		int ans=0;for(int i=1;i<=m;) if(jump(m,s,i)) ++ans;else {ans=-1;break;}
		printf("%d\n",ans);
	}
	return 0;
}