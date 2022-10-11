#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
bool a1[100005],a2[100005];
int main()
{
	long long n,m;
	cin >> n >> m;
	long long v1=n,v2=n;
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		if (!a1[a])
		v1--;
		if (!a2[b])
		v2--;
		a1[a]=true;
		a2[b]=true;
		cout << v1*v2 << ' ';
	}
}