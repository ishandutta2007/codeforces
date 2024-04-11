#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,a[N],b[N]; char s[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	scanf("%d",&n);
	int i,t1=0,ans=0;
	for (i=1; i<=n; i++){
		scanf("%s",s+1); int len=strlen(s+1);
		int x=0,y=0;
		for (int j=1; j<=len; j++) if (s[j]=='('){
			x++;
		} else{
			if (x) x--; else y++;
		}
		if (x && y) continue;
		if (!x && !y) t1++;
		a[x]++; b[y]++;
	}
	for (i=1; i<=500000; i++) ans+=min(a[i],b[i]);
	ans+=t1/2;
	printf("%d\n",ans);
	return 0;
}