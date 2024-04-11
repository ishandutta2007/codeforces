#include <iostream>
#include <cstdio>
using namespace std;
int p,q,r,s;
bool a,b,c,d;
int main()
{
	scanf("%d %d %d %d",&p,&q,&r,&s);
	if(p>0) a=true;
	if(q>0) b=true;
	if(r>0) c=true;
	if(s>0) d=true;
	if((((((p^q))&((r|s))))^((((q&r))|((p^s)))))==0) printf("0");
	else printf("1");
	return 0;
}