#include <bits/stdc++.h>
using namespace std;

char s[256];
int c[256][256];
int n;

int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<n;++i){
		for(int j=0;j<256;++j){
			c[i+1][j]=c[i][j];
		}
		c[i+1][s[i]]++;
	}
	int r=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			r+=(c[j]['U']-c[i]['U']==c[j]['D']-c[i]['D']&&c[j]['L']-c[i]['L']==c[j]['R']-c[i]['R']);
		}
	}
	printf("%d\n",r);
	return 0;
}