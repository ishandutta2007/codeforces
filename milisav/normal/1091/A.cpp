#include<bits/stdc++.h>
using namespace std;
int main()
{
	int y,b,r;
	scanf("%d %d %d",&y,&b,&r);
	if(y<=b-1 && y<=r-2) printf("%d",y*3+3);
	else {
		if(b-1<=y && b-1<=r-2) printf("%d",(b-1)*3+3);
		else printf("%d",(r-2)*3+3);
	}
	return 0;
}