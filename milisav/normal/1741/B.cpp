#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
/*

1 2 3 4 5
5 4 1 2 3


1 2 3 4 5 6 7 8 9
9 8 7 6 1 2 3 4 5


7 6 5 1 2 3 4

*/
int t;
int n;
int p[maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) p[i]=n-i+1;
		if(n%2==1) {
			if(n==3) {
				printf("-1\n");
				continue;
			}
			reverse(p+(n+1)/2,p+n+1);
		}
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		printf("\n");
	}
}