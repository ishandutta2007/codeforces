#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
char s[111];
int main(){
	scanf("%d",&t);
	while(t--){
		int ans = 0, l = 0;
		scanf("%d %s",&n,s+1);

		for(int i=1;i<=n;i++){
			if(s[i] == 'A'){
				if(l) ans = max(ans, i-l-1);
				l = i;
			}
		}
		if(l) ans = max(ans, n-l);
		printf("%d\n",ans);
	}
}