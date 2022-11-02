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
const int N=105;int n,cn[3];char ch[N];
inline int id(char x)
{
	if(x>='a'&&x<='z') return 0;
	if(x>='A'&&x<='z') return 1;
	return 2;
}
inline void solve()
{
	memset(cn,0,sizeof(cn)),scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) cn[id(ch[i])]++;
	if(!cn[0]) for(int i=1;i<=n;i++) if(cn[id(ch[i])]>1) {cn[id(ch[i])]--,ch[i]='a',cn[0]++;break;}
	if(!cn[1]) for(int i=1;i<=n;i++) if(cn[id(ch[i])]>1) {cn[id(ch[i])]--,ch[i]='A',cn[1]++;break;}
	if(!cn[2]) for(int i=1;i<=n;i++) if(cn[id(ch[i])]>1) {cn[id(ch[i])]--,ch[i]='0',cn[2]++;break;}
	printf("%s\n",ch+1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}