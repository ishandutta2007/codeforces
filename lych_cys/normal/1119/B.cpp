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
using namespace std;

int n,m,a[1009],b[1009];
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
bool check(int x){
	int i;
	for (i=1; i<=x; i++) b[i]=a[i]; sort(b+1,b+x+1);
	ll tmp=0;
	for (i=x; i>0; i-=2) tmp+=b[i];
	return tmp<=m;	
}
int main(){
	scanf("%d%d",&n,&m);
	int i;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	for (i=n; i; i--) if (check(i)){
		printf("%d\n",i); return 0;
	}
	return 0;
}