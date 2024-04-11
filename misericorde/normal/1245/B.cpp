#include <bits/stdc++.h>
int n,a,b,c;
char s[1000],opt[1000];

void solve(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;++i)opt[i]=0;
	for(int i=1;i<=n;++i){
		if (s[i]=='R'&&b){cnt++;b--;opt[i]='P';}
		else if (s[i]=='P'&&c){cnt++;c--;opt[i]='S';}
		else if (s[i]=='S'&&a){cnt++;a--;opt[i]='R';}
	}if (cnt*2<n){printf("NO\n");return;}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		if (opt[i]!=0)printf("%c",opt[i]);
		else {
			if (a){a--;printf("R");}
			else if (b){b--;printf("P");}
			else{c--;printf("S");}
		}
	}printf("\n");
	return;
}
	

int main(){int t;
	scanf("%d",&t);while (t--)solve();
	return 0;
}