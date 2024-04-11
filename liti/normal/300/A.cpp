#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int counter = 0;
	for(int i = 0 ; i < n; i++)
	{
		cin >> a[i];
		if ( a[i] < 0 ) 
			counter++;
	}
	int c2 = 0 ; 
	if ( counter % 2 == 0 ) 
		c2 = 1;

	vector<int> nums[3];
	
	for(int i = 0 ; i < n; i++)
	{
		if ( a[i] < 0 && c2 == 0 ) 
		{
			if ( nums[0].size() == 0 ) 
			   nums[0].push_back(a[i]);
			else
				nums[1].push_back(a[i]);
		}	
		if ( a[i] < 0 && c2 ) {
			nums[2].push_back(a[i]);
			c2 = 0;
		}
		if ( a[i] == 0 ) 
			nums[2].push_back(a[i]);
		if ( a[i] > 0 ) 
			nums[1].push_back( a[i] );
	}
	for(int i = 0 ;i < 3; i++) 
	{
		cout << nums[i].size() << ' ';
		for(int j  =0; j < nums[i].size() ; j++ )
			cout << nums[i][j] << ' ';
		cout << endl;
	}
	
}