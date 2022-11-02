#include <stdio.h>
#include <algorithm>
#include <vector>

int a[300000];

bool srt(int x,int y){
	if(x>y) return true;
	return false;
}

void solve(int n){
	int i;
	long long int ans;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	ans=0;
	ans+=((long long int)a[n-1])*n;
	for(i=0;i<n-1;i++){
		ans+=((long long int)a[i])*(i+2);
	}
	printf("%I64d",ans);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
	int n;
	while(scanf("%d",&n)!=EOF){
	solve(n);
	}
	return 0;
}