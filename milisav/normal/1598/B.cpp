#include<bits/stdc++.h>
#define maxn 20000
using namespace std;
int t;
int n;
int a[maxn][5];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			for(int j=0;j<5;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		bool ok=false;
		for(int g=0;g<5;g++) {
			for(int h=0;h<5;h++) {
				if(g==h) continue;
				int c1=0,c2=0,tot=0;
				for(int i=0;i<n;i++) {
					c1+=a[i][g];
					c2+=a[i][h];
					tot+=max(a[i][g],a[i][h]);
				}
				if(tot==n && c1>=n/2 && c2>=n/2) ok=true;
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}