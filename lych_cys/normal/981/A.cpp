#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int n; char s[109];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	int i,j,k,l,ans=0;
	for (i=1; i<=n; i++)
		for (j=i; j<=n; j++){
			for (k=i,l=j; k<l; k++,l--) if (s[k]!=s[l]) break;
			if (k<l) ans=max(ans,j-i+1);	
		}
	printf("%d\n",ans);
	return 0;
}