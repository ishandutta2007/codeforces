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
char ch[10005];const char c[15]="heidi";
int main()
{
	int mt=0;scanf("%s",ch+1);int n=strlen(ch+1);
	for(int i=1;i<=n;i++) if(ch[i]==c[mt]) mt++;
	if(mt==5) return puts("YES"),0;else return puts("NO"),0;
}