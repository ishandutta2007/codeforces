#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;double h;
	scanf("%d%lf",&n,&h);
	for(int i=1; i<n; i++){
		printf("%.12lf%c",h*sqrt((double)i/n),i<n-1?' ':'\n');
	}
	return 0;
}