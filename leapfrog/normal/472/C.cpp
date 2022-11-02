//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
string s[100005][2];int n,id[100005];
int main()
{
	ios::sync_with_stdio(false),cin>>n;
	for(int i=1;i<=n;i++) {cin>>s[i][0]>>s[i][1];if(s[i][0]>s[i][1]) swap(s[i][0],s[i][1]);}
	for(int i=1;i<=n;i++) cin>>id[i];
	string nw=s[id[1]][0];
	for(int i=2;i<=n;i++) if(s[id[i]][0]>=nw) nw=s[id[i]][0];else if(s[id[i]][1]>=nw) nw=s[id[i]][1];else return puts("NO"),0;
	return puts("YES"),0;
}