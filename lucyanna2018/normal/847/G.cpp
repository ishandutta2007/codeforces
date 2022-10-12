#include<stdio.h>
#include<algorithm>
using namespace std;
int a[7];
int main(){
	char s[99];
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%s",s);
		for(int i=0; i<7; i++)
			a[i] += s[i] - '0';
	}
	int res = 0;
	for(int i=0; i<7; i++)
		res = max(res, a[i]);
	printf("%d\n",res);
	return 0;
}