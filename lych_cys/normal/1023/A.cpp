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
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int m,n; char a[200009],b[200009];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void gg(){ puts("NO"); exit(0);}
int main(){
	scanf("%*d%*d%s%s",a+1,b+1);
	m=strlen(a+1); n=strlen(b+1);
	int i,k;
	for (i=1; i<=m; i++) if (a[i]=='*') break; k=i;
	if (k>m){
		if (m!=n) gg();
		for (i=1; i<=m; i++) if (a[i]!=b[i]) gg();
		puts("YES"); return 0;
	}
	if (m-1>n) gg();
	for (i=1; i<k; i++) if (a[i]!=b[i]) gg();
	for (i=1; i<=m-k; i++) if (a[m-i+1]!=b[n-i+1]) gg();
	puts("YES");
	return 0;
}