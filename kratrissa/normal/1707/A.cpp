#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,q,a[N];char res[N];
void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(q>=n){for(int i=1;i<=n;i++)putchar('1');putchar('\n');return;}
	int t=(a[n]==1);
	for(int i=n;i;i--)
		if(t<q)res[i]='1',t+=(a[i]>t);
		else res[i]=(q>=a[i])+'0';
	for(int i=1;i<=n;i++)putchar(res[i]);putchar('\n');
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}