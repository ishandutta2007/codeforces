#include<bits/stdc++.h>
#define maxn 500
using namespace std;
int t;
int n;
char s[2][maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		scanf("%s",s[0]);
		scanf("%s",s[1]);
		bool ok=true;
		for(int i=0;i<n;i++) {
			if(s[0][i]=='1' && s[1][i]=='1') ok=false;
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
}