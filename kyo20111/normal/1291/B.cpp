#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, a[300300];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);

		int u = 0, cur = 1;
		for(;cur<=n;cur++){
			if(u > a[cur]) break;
			u++;
		}
		if(cur > n){
			puts("Yes");
			continue;
		}

		u = a[cur-1];
		for(;cur<=n;cur++){
			if(u <= a[cur]) u--;
			else u = a[cur];
		}
		puts(u>=0?"Yes":"No");
	}
}