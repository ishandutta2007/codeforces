#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int mv(int x,int y){
	return labs(x-y);
}
int main(){
	int n,pos,l,r,res;
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	if(l == 1 && r == n)
		res = 0;
	else
	if(l == 1)
		res = mv(pos, r) + 1;
	else
	if(r == n)
		res = mv(pos, l) + 1;
	else
		res = min(mv(pos, l), mv(pos, r)) + mv(l, r) + 2;
	printf("%d\n",res);
	return 0;
}