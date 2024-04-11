#include<bits/stdc++.h>
using namespace std;
int main(){
	int res = 0,n,x,y;
	scanf("%d",&n);
	int maxL = -1, minR = 2147483647;
	for(int i=0; i<n; i++){
		scanf("%d%d",&x,&y);
		maxL = max(x, maxL);
		minR = min(y, minR);
	}
	int maxL2 = maxL, minR2 = minR;
	scanf("%d",&n);
	maxL = -1;
	minR = 2147483647;
	for(int i=0; i<n; i++){
		scanf("%d%d",&x,&y);
		maxL = max(x, maxL);
		minR = min(y, minR);
	}
	res = max(res, maxL2 - minR);
	res = max(res, maxL - minR2);
	printf("%d\n",res);
	return 0;
}