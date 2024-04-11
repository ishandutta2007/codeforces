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
const int N=100005;int n,tn[60];char ch[N];
int main()
{
	read(n),scanf("%s",ch+1);if(n>26) return puts("-1"),0;
	for(int i=1;i<=n;i++) tn[ch[i]-'a']++;
	int rs=0;for(int i=0;i<26;i++) if(tn[i]) rs+=tn[i]-1;
	return printf("%d\n",rs),0;
}