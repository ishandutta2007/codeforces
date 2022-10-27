#pragma gcc optimize("O3");
#pragma gcc target("sse4");
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n, l, a;
    cin >> n >> l >> a;
    if(n == 0)
    {
    	cout << l / a;
    	return 0;
	}
    vector <pair <int, int> > A(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i].first >> A[i].second;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			count +=(A[i].first) / a;
		}
		else
		{
			count +=(A[i].first  - A[i - 1].first - A[i - 1].second) / a;
		}
	}
	count += (l - A[n - 1].first - A[n - 1].second) / a;
	cout << count;
    return 0;
 }