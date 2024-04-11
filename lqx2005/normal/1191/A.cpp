#include <bits/stdc++.h>
using namespace std;
int calc(int x)
{
	if(x%4==1) return 4;
	if(x%4==3) return 3;
	if(x%4==2) return 2;
	return 1;
}
void print(int x)
{
	if(x==4) printf("A\n");
	else if(x==3) printf("B\n");
	else if(x==2) printf("C\n");
	else printf("D\n");
	return;
}
int n;
int main()
{
	scanf("%d",&n);
	int ans=-100,id;
	for(int i=0;i<=2;i++) if(ans<calc(n+i)) id=i,ans=calc(n+i); 
	printf("%d ",id);
	print(ans); 
	return 0;
}