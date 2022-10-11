#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int a=count(s.begin(),s.end(),'A'),d=count(s.begin(),s.end(),'D');
	if (a>d)
	cout << "Anton";
	else if (a<d)
	cout << "Danik";
	else
	cout << "Friendship";
}