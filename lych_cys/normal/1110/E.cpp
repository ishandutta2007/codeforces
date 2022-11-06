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
#define N 100009
using namespace std;

int n,a[N],b[N];
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
void gg(){ puts("No"); exit(0); }
int main(){
	n=read();
	int i;
	for (i=1; i<=n; i++) a[i]=read();
	for (i=1; i<=n; i++) b[i]=read();
	if (a[1]!=b[1] || a[n]!=b[n]) gg();
	for (i=1; i<n; i++){ a[i]=a[i+1]-a[i]; b[i]=b[i+1]-b[i]; }
	sort(a+1,a+n); sort(b+1,b+n);
	for (i=1; i<n; i++) if (a[i]!=b[i]) gg();
	puts("Yes");
	return 0;
}