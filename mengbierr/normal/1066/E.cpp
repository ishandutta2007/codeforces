#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define N 200010
int n,m,a[N][2];
ll ans=0;
char s[N],t[N];
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	for(int i=0;i<m;i++){
		if(t[i]=='0') a[0][0]++;
		else a[0][1]++;
	}
	for(int i=m-1;i;i--){
		a[m-i][0]=a[m-i-1][0];
		a[m-i][1]=a[m-i-1][1];
		if(t[i]=='0') a[m-i][0]--;
		else a[m-i][1]--;
	}
	for(int i=n-1,k=1;i>=0;i--){
		if(s[i]=='1') ans=(ans+(ll)a[n-i-1][1]*k%mod)%mod;
		k=2ll*k%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}