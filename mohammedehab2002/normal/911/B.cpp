#include <iostream>
using namespace std;
int main()
{
	int n,a,b,ans=1;
	cin >> n >> a >> b;
	for (int x=1;x<=200;x++)
	{
		if (a/x+b/x>=n && a/x>0 && b/x>0)
		ans=x;
	}
	printf("%d",ans);
}