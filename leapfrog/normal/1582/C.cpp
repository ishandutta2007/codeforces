//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
//
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
const int N=100005;char ch[N];int n;
inline void solve()
{
	read(n),scanf("%s",ch+1);int rs=1e9;
	for(int i=0;i<26;i++)
	{
		int sm=0;
		for(int l=1,r=n;l<=r;)
		{
			if(ch[l]==ch[r]) {l++,r--;continue;}
			if(ch[l]==i+'a') l++,sm++;
			else if(ch[r]==i+'a') r--,sm++;
			else {sm=1e9;break;}
		}
		rs=min(rs,sm);
	}
	if(rs!=1000000000) printf("%d\n",rs);else puts("-1");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}