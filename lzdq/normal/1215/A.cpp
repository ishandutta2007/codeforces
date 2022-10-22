#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a,b,c,d;
int CalcMin(int a1,int a2,int k1,int k2){
	int m=n;
	while(a1--) m-=k1-1;
	while(a2--) m-=k2-1;
	if(m<=0) return 0;
	return min(m,a+b);
}
int CalcMax(int a1,int a2,int k1,int k2){
	int m=n,res=0;
	if(k1>k2) swap(a1,a2),swap(k1,k2);
	while(a1--){
		m-=k1;
		if(m<0) break;
		res++;
	}
	if(m<0) return res;
	while(a2--){
		m-=k2;
		if(m<0) break;
		res++;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	printf("%d %d\n",CalcMin(a,b,c,d),CalcMax(a,b,c,d));
	return 0;
}