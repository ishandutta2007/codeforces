#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int c256=min(a,min(c,d));
	cout << c256*256+min(a-c256,b)*32;
}