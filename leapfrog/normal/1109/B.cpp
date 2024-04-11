//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n;string s,t;
int main()
{
	cin>>s,n=s.size(),s=" "+s;int tag=0;
	for(int i=2;i<=n&&!tag;i++) if((n&1)&&((i<<1)==n+1||(i<<1)==n+3));else if(s[i]!=s[i-1]) tag=1;
	if(!tag) return puts("Impossible"),0;else tag=0;
	for(int i=1;i<=n&&!tag;i++)
	{
		string t=" ";int zkak=0;
		t=t+s.substr(i,n-i+1),t=t+s.substr(1,i-1);
		for(int i=1;i<=n&&!zkak;i++) if(t[i]!=s[i]) zkak=1;
		if(!zkak) continue;else zkak=0;
		for(int i=1;i<=(n>>1)&&!zkak;i++) if(t[i]!=t[n-i+1]) zkak=1;
		if(zkak) continue;else tag=1;
	}
	return printf("%d\n",2-tag),0;
}