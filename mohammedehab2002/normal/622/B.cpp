#include <iostream>
using namespace std;
int main()
{
	int h,m,add;
	scanf("%d:%d%d",&h,&m,&add);
	m+=add;
	h=(h+m/60)%24;
	m%=60;
	printf("%02d:%02d",h,m);
}