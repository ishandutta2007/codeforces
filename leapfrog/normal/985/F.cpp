#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int>pii;
const int N=200005,P1=1000000007,P2=1000000009,b1=29,b2=37;
pii h[30][N];int n,m,pw1[N],pw2[N];char str[N];
inline pii Get(pii h[],int l,int r)
{
	pii ans=h[r];l--;
	if(l>=0) ans.fi=(ans.fi-1ll*h[l].fi*pw1[r-l]%P1+P1)%P1,ans.se=(ans.se-1ll*h[l].se*pw2[r-l]%P2+P2)%P2;
	return ans;
}
signed main()
{
	pw1[0]=pw2[0]=1,scanf("%d%d%s",&n,&m,str+1);
	for(int i=1;i<=n;i++) pw1[i]=1ll*pw1[i-1]*b1%P1,pw2[i]=1ll*pw2[i-1]*b2%P2;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) h[j][i].fi=(ll(h[j][i-1].fi)*b1+('a'+j==str[i]))%P1,h[j][i].se=(ll(h[j][i-1].se)*b2+('a'+j==str[i]))%P2;
	for(int x,y,len;m--;)
	{
		scanf("%d%d%d",&x,&y,&len);multiset<pii>s1,s2;
		for (int i=0;i<26;i++) s1.insert(Get(h[i],x,x+len-1)),s2.insert(Get(h[i],y,y+len-1));
		printf("%s\n",s1==s2?"YES":"NO");
	}
	return 0;
}