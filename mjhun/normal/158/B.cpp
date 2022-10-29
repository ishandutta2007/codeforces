#include <cstdio>
#include <iostream>
using namespace std;

int ng[8];

int main(){
	int n,k,i,r=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		ng[k]++;
	}
	r+=ng[4];
	k=min(ng[3],ng[1]);
	r+=k;
	ng[3]-=k;
	ng[1]-=k;
	r+=ng[3];
	r+=ng[2]/2;
	if(ng[2]%2)
		ng[1]+=2;
	r+= (ng[1]+3)/4;
	printf("%d\n",r);
	return 0;
}