//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=10953223;int h[500005];bitset<P+2>s;
int n,bs=1145141;char ch[500005],f[2][500005];
int main()
{
	read(n),scanf("%s",ch+1);for(int i=1;i<=n;i++) h[i]=ch[i],f[1][i]=1;
	for(int nw=2,sm=3,tg=0;sm-nw<=n;nw++,sm+=nw,tg=0)
	{
		memset(f[nw&1],0,n+1);for(int i=n-sm+1;i>0;i--)
		{
			int p=i+nw;if(f[(nw&1)^1][p]) s[h[p]]=1;
			if(s[h[i]]||s[h[i+1]]) f[nw&1][i]=1,tg=1;
		}
		if(!tg) return printf("%d\n",nw-1),0;else for(int i=n-sm+1;i>0;i--) s[h[i+nw]]=0;
		for(int i=1;i+sm-1<=n;i++) h[i]=(1ll*h[i]*bs+ch[i+nw-1])%P;
	}
}