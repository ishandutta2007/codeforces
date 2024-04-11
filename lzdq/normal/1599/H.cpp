#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int m=1e9;
ll k1,k2,k3;
ll x,y,p,q;
ll _x=2,_y=3,_p=4,_q=5;
ll Query(int x,int y){
	int res=m*2;
	/*
	for(int i=_x; i<=_p; i++)
		for(int j=_y; j<=_q; j++)
			res=min(res,abs(i-x)+abs(j-y));
	return res;
	*/
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}
int main(){
	k1=Query(1,1)+2;
	k2=Query(m,1)+1-m;
	k3=m*2-Query(m,m);
	//printf("k1 %lld k2 %lld\n",k1,k2);
	y=Query(k1-k2>>1,1)+1;
	x=k1-y;
	p=y-k2;
	q=k3-p;
	printf("! %lld %lld %lld %lld\n",x,y,p,q);
	fflush(stdout);
	return 0;
}