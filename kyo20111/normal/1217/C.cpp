#include<bits/stdc++.h>
using namespace std;
int t,n,a[202020];
char s[202020];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n = strlen(s+1);
		for(int i=1;i<=n;i++) a[i] = a[i-1] + (s[i]-'0');

		int bit = 0, mask = 262143,ans = 0;
		for(int i=1;i<=n;i++){
			bit = (bit*2+a[i]-a[i-1]) & mask;
			for(int j=1;j<=min(i,18);j++){
				if(((1<<(j-1))&bit) == 0) continue;
				int c = ((1<<j)-1)&bit;
				if(c<=i && a[i-j]-a[i-c] == 0) ans++;
			}
		}
		printf("%d\n",ans);
	}
}