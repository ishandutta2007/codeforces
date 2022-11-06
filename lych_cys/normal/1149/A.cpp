#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
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
	int n;scanf("%d",&n);
	int i,j,s1=0,s2=0;
	for (i=1; i<=n; i++){
		scanf("%d",&j);
		if (j==1) s1++; else s2++;	
	}
	if (!s1){
		for (i=1; i<=n; i++) printf("2 "); puts(""); return 0;	
	}
	if (!s2){
		for (i=1; i<=n; i++) printf("1 "); puts(""); return 0;
	}
	s1--; s2--;
	printf("2 1 ");
	while (s2--) printf("2 "); while (s1--) printf("1 "); puts("");
	return 0;
}