#include<bits/stdc++.h>
int main(){
	double x = 0, y,z;int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%lf%lf",&z,&y);
		x += y;
	}
	printf("%lf\n",5+x/n);
	return 0;
}