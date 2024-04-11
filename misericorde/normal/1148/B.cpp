#include <bits/stdc++.h>
#define ll long long
#define maxn 300005
int n,m,k,ta,tb,a[maxn]={0},b[maxn];

int check(int x) {
	int p=1;
	for (int i=0;i<=n;++i) {
		if (a[i+1]+ta>b[x]) return i<=k;
		while (a[i+1]+ta>b[p]&&p<=m) p++;
		if (i+(x-p)<=k) return 1;
	}return 0;
}

int main() {
	std::cin>>n>>m>>ta>>tb>>k;
	for (int i=1;i<=n;++i) std::cin>>a[i];
	for (int i=1;i<=m;++i) std::cin>>b[i];
	b[m+1]=(int)1e9+7; a[n+1]=(int)1e9+7;
	int l=1,r=m+1,ans;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}if (ans<=m) std::cout<<(long long)b[ans]+tb;
	else std::cout<<-1;
	return 0;
}