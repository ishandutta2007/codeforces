#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main()
{
	scanf("%d %d %d",&x,&y,&z);
	if(x>y) {if(x>y+z) puts("+");else puts("?");}
	else if(x==y) {if(z) puts("?");else puts("0");}
	else {if(x+z<y) puts("-");else puts("?");}
}