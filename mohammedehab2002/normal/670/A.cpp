#include <iostream>
#include <vector>
using namespace std;
vector <int> v[5005];
int main()
{
	int n;
	cin >> n;
	int ans1=n/7*2,ans2=n/7*2;
	ans1+=max(n%7-5,0);
	ans2+=min(n%7,2);
	cout << ans1 << ' ' << ans2;
}