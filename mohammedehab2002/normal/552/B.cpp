#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	ostringstream con;
	int n,i;
	cin >> n;
	con << n;
	int size=con.str().size();
	string s="";
	for (i=0;i<size;i++)
	s+='1';
	cout << (long long)size*(n+1)-atoi(s.c_str());
}