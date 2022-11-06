#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,dgr[100009];
int f(int x){
	int i=1; for (; x; x--) i=(i<<1)%mod; return i;
}
int main(){
	scanf("%d",&n);
	int i,x,y;
	for (i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		dgr[x]++; dgr[y]++;
	}
	x=0;
	for (i=1; i<=n; i++) if (dgr[i]==1) x++;
	printf("%lld\n",((ll)x*f(n-(x-1))+(ll)(n-x)*f(n-x))%mod);
	return 0;
}