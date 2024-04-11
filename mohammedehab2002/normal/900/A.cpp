#include <iostream>
using namespace std;
int main()
{
	int n,cnt=0,cnt2=0;
	scanf("%d",&n);
	while (n--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>0)
		cnt++;
		else
		cnt2++;
	}
	if (cnt<=1 || cnt2<=1)
	printf("Yes");
	else
	printf("No");
}