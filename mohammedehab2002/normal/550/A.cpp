#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	size_t p1,p2,p3,p4;
	string s;
	cin >> s;
	p1=s.find("AB");
	p2=s.rfind("BA");
	p3=s.rfind("AB");
	p4=s.find("BA");
	if (p1!=p2 && p1+1!=p2 && p1-1!=p2 && p1!=string::npos && p2!=string::npos)
	cout << "YES";
	else if (p1!=p4 && p1+1!=p4 && p1-1!=p4 && p1!=string::npos && p4!=string::npos)
	cout << "YES";
	else if (p3!=p2 && p3+1!=p2 && p3-1!=p2 && p3!=string::npos && p2!=string::npos)
	cout << "YES";
	else if (p3!=p4 && p3+1!=p4 && p3-1!=p4 && p3!=string::npos && p4!=string::npos)
	cout << "YES";
	else
	cout << "NO";
}