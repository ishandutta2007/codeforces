#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
int main() {
	#define int long long
	int cons = 1e9 + 7;
	string s;
	cin >> s;
	bool flag = true;
	vector <int> A;
	for(int i = 0; i < s.size(); i++)
	{
		int cnt = 0;
		while(i < s.size() && s[i] != 'b')
		{
			if(s[i] == 'a')
			{
				cnt++;
			}
			i++;
		}
		A.push_back(cnt);
	}
	int rez = 1;
	for(int i = 0; i < A.size(); i++)
	{
		rez = (rez * (A[i] + 1)) % cons;
	}
	cout << rez - 1;
	return 0;
}