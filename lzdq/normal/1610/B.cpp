#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
bool Check(int l,int r,int x){
	if(l>=r) return 1;
	if(a[l]==a[r]) return Check(l+1,r-1,x);
	if(a[l]==x) return Check(l+1,r,x);
	if(a[r]==x) return Check(l,r-1,x);
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		int l=1,r=n;
		while(l<r&&a[l]==a[r]) l++,r--;
		if(l>=r) puts("YES");
		else if(Check(l,r,a[l])||Check(l,r,a[r])) puts("YES");
		else puts("NO");
	}
	return 0;
}