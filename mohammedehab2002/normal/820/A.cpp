#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int c,v0,v1,a,l;
	cin >> c >> v0 >> v1 >> a >> l;
	int cur=0,sp=v0,ans=0;
	while (cur<c)
	{
		ans++;
		cur+=sp;
		sp=min(sp+a,v1);
		if (cur>=c)
		break;
		cur-=l;
	}
	cout << ans;
}