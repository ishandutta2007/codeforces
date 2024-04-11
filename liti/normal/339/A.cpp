#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	string s; 
	vector<int> num;
	cin >> s; 

	for(int i =0 ; i < s.size() ; i++ )
	{
		if ( s[i] != '+' ) 
		{
			num.push_back( s[i] - 48 ) ; 
		}
	}

	sort(num.begin(), num.begin() + num.size() ) ; 
	for(int i = 0 ; i < num.size() ; i++ ) 
	{
		cout << num[i];
		if ( i != num.size() - 1 ) 
			cout << '+';
	}
	cout << endl;
}