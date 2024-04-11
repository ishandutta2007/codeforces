#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m;
char s[66][66];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int fl = 0;
		int fl2 = 0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j] != 'A') fl2 = 1;
			
		if(!fl2){
			puts("0");
			continue;
		}

		int F = 0;
		for(int i=1;i<=n;i++){
			if(s[i][1] != 'A'){
				F = 1;
				break;
			}
		}
		if(!F) fl = 1;
		F = 0;
		for(int i=1;i<=n;i++){
			if(s[i][m] != 'A'){
				F = 1;
				break;
			}
		}
		if(!F) fl = 1;
		F = 0;
		for(int i=1;i<=m;i++){
			if(s[1][i] != 'A'){
				F = 1;
				break;
			}
		}
		if(!F) fl = 1;
		F = 0;
		for(int i=1;i<=m;i++){
			if(s[n][i] != 'A'){
				F = 1;
				break;
			}
		}
		if(!F) fl = 1;

		if(fl){
			puts("1");
			continue;
		}

		if(s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') fl = 1;

		for(int i=1;i<=n;i++){
			int fl2 = 1;
			for(int j=1;j<=m;j++) if(s[i][j] != 'A'){
				fl2 = 0;
				break;
			}
			if(fl2){
				fl = 1;
				break;
			}
		}

		for(int j=1;j<=m;j++){
			int fl2 = 1;
			for(int i=1;i<=n;i++) if(s[i][j] != 'A'){
				fl2 = 0;
				break;
			}
			if(fl2){
				fl = 1;
				break;
			}
		}

		if(fl){
			puts("2");
			continue;
		}

		for(int i=1;i<=n;i++) if(s[i][1] == 'A' || s[i][m] == 'A') fl = 1;
		for(int i=1;i<=m;i++) if(s[1][i] == 'A' || s[n][i] == 'A') fl = 1;

		if(fl){
			puts("3");
			continue;
		}

		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j] == 'A') fl = 1;

		if(fl) puts("4");
		else puts("MORTAL");
	}
}