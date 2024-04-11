#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int la,ra,ta,lb,rb,tb;
int pd(int z){
//	printf("%d %d!!\n",z,min(ra-la+1,rb-lb+1+z)-max(1,z+1)+1);
	return min(ra-la+1,rb-lb+1+z)-max(1,z+1)+1;
}
int main(){
	scanf("%d%d%d%d%d%d",&la,&ra,&ta,&lb,&rb,&tb);
	int o=gcd(ta,tb);
	printf("%d\n",max(0,max(pd(((lb-la)%o+o)%o),pd(((lb-la)%o+o)%o-o))));
}