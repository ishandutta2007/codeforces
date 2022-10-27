#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
   	int n;
   	cin >> n;
   	string s;
   	cin >> s;
   	int count = 0;
   	for(int i = 0; i < s.size(); i++)
   	{
   		if((s[i] - '0') % 2 == 0)
   		{
   			count += i + 1;
		}
	}
	cout << count;
	return 0;
}