#include<cstdio>
#include<cmath>
using namespace std;
int t,d;
double del;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&d);
		if(d*d>=4*d){
			del=sqrt(d*d-4*d);
			printf("Y %.9lf %.9lf\n",(d+del)/2,(d-del)/2);
		}
		else
			printf("N\n");
	}
	return 0;
}