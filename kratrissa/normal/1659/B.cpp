#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef long long ll;
int T,n,k,a[N],c[N];char s[N];
void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)a[i]=(s[i]=='1')^(k&1);
	fill(c,c+n+1,0);
	for(int i=1;i<n;i++)
		if(a[i]==0&&k)a[i]=1,k--,c[i]=1;
	c[n]=k,a[n]^=(k&1);
	for(int i=1;i<=n;i++)putchar('0'+a[i]);putchar('\n');
	for(int i=1;i<=n;i++)printf("%d ",c[i]);putchar('\n');
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}