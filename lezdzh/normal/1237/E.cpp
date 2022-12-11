#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=2,o=-1;i<=1000000;){
		if(n==i||n==i+o){
			printf("1\n");
			return 0;
		}
		i=max(i,i+o)*2;
		o=-o;
	}
	printf("0\n");
}