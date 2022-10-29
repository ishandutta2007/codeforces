#include <bits/stdc++.h>
using namespace std;

char b[128][128];
int n,m;
char c;
bool h[128];

int main(){
	scanf("%d%d%s",&n,&m,&c);
	for(int i=1;i<=n;++i){
		scanf("%s",*(b+i)+1);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]==c){
				h[b[i+1][j]]=1;
				h[b[i-1][j]]=1;
				h[b[i][j+1]]=1;
				h[b[i][j-1]]=1;
			}
		}
	}
	int r=0;
	for(int i='A';i<='Z';++i)if(i!=c)r+=h[i];
	printf("%d\n",r);
	return 0;
}