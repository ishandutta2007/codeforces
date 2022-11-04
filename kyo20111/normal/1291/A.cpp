#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
char s[3030], chk[3030];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,s+1);
		for(int i=1;i<=n;i++) chk[i] = 1;

		int sum = 0;
		for(int i=1;i<=n;i++) sum += s[i];

		while(n > 1 && !(s[n] % 2)) n--;
		if(n <= 1){
			puts("-1");
			continue;
		}

		if(sum % 2){
			for(int i=1;i<=n;i++) if(s[i] == '0') chk[i] = 0;
			int fl = 0;
			for(int i=1;i<n;i++) if(chk[i] && s[i]%2){
				chk[i] = 0;
				fl = 1;
				break;
			}
			if(!fl){
				puts("-1");
				continue;
			}
		}

		int fl = 0;
		for(int i=1;i<=n;i++) if(chk[i]) fl = 1;

		if(!fl){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++) if(chk[i]) printf("%c",s[i]);
		puts("");
	}
}