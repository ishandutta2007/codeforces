#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x;
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			scanf("%d",&x);
			if(x)printf("%d",abs(3-i)+abs(3-j));
		}
	}
	return 0;
}