#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int N; long long ans = 0;
	scanf ("%d",&N);
	map<int,int> a,b; while (N--){
		int x,y; scanf ("%d %d",&x,&y);
		ans += a[x+y]++;
		ans += b[x-y]++;
	}
	printf ("%lld\n",ans);

	return 0;
}