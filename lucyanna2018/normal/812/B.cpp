#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
char s[999][999];
int d[999][2],L[999],R[999];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%s",s[i]);
		L[i] = m+1; R[i] = 0;
		for(int j=1; j<=m; j++)
			if(s[i][j] == '1'){
				L[i] = min(L[i], j);
				R[i] = max(R[i], j);
			}
	}
	int res = 0;

	if(R[n-1] != 0)res = R[n-1];

	d[n-1][0] = 2 * R[n-1];
	d[n-1][1] = m+1;

	for(int i=n-2; i>=0; i--){
		if(R[i] != 0){
			res = min(d[i+1][0] + 1 + R[i], d[i+1][1] + 1 + (m+1 - L[i]));
		}
		d[i][0] = min(d[i+1][0] + 1 + 2 * R[i], d[i+1][1] + 1 + m+1);
		d[i][1] = min(d[i+1][0] + 1 + m+1, d[i+1][1] + 1 + 2*(m+1 -L[i]));
	}
	printf("%d\n",res);
	return 0;
}