#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> s(n);
	for (int i = 0;i < n; i++)
		cin >> s[i];

	sort(s.begin(),s.begin() + n);

	if ( k >= m )
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = n -1 ; i >= 0;i--)
	{
		k = k + s[i] - 1;
		if ( k >= m ){
			cout << n - i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

}