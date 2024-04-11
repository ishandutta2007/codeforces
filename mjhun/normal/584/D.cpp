#include <bits/stdc++.h>
using namespace std;

bool isp(int k){
	for(int i=2;i*i<=k;++i)if(!(k%i))return false;
	return true;
}

int n;

int main(){
	scanf("%d",&n);
	if(isp(n)){printf("1\n%d\n",n);return 0;}
	int p1,p2,p3;
	for(p1=n-6;!isp(p1);p1-=2);
	p3=-1;
	for(p2=3;p3<0;p2+=2){
		if(isp(p2)&&isp(n-p1-p2))p3=n-p1-p2;
	}
	p2-=2;
	printf("3\n%d %d %d\n",p1,p2,p3);
	return 0;
}