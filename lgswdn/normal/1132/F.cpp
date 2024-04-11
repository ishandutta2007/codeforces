#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=509;

int n,f[N][N];
char s[N];

int dfs(int l,int r) {
	if(f[l][r]) return f[l][r];
	if(l==r) return f[l][r]=1;
	if(l+1==r) return f[l][r]=1+(s[l]!=s[r]);
	if(l>r) return 0;
	f[l][r]=1+min(dfs(l+1,r),dfs(l,r-1)); 
	rep(k,l,r) if(s[k]==s[l])
		f[l][r]=min(f[l][r],dfs(l+1,k-1)+dfs(k,r));
	return f[l][r];
}

int main() {
	scanf("%d%s",&n,s+1);
	printf("%d",dfs(1,n));
	return 0;
}