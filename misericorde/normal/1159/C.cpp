#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
int A[maxn],B[maxn],n,m;
ll ans=0;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&A[i]);
	for (int i=1;i<=m;++i) scanf("%d",&B[i]);
	std::sort(A+1,A+n+1);
	std::sort(B+1,B+m+1);
	if (A[n]>B[1]) {printf("-1");return 0;}
	int p=m;
	for (int i=n;i>=1;i--) {
		int cnt=m-1;
		while (cnt>0&&p>0) {
			ans+=B[p]; p--; cnt--; 
		}ans+=(ll)(cnt+1)*(ll)A[i];if (A[i]==B[p]) p--;
	}std::cout<<ans;
	return 0;
}