#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long m;

	cin >> m;
	vector<long long> num;

	int n = log2( m ) / 2 ;
//	cout << n << endl;
	long long tmp;
	for(long i = 0 ; i < m ;i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort( num.begin() , num.end() ) ;

	long long result = 0;
	long long zarib = 1;
	int time = 0;
	for(int i = num.size() - 1 ; i >= 0 ;i--) 
	{
		result += max(1, n + 1 - time) * num[i];
		if ( num.size() - i == zarib ) 
		{
			zarib *= 4;
			time++;
		}
	}
	cout << result << endl;
}