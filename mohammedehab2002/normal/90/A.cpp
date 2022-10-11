#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int r,g,b;
	cin >> r >> g >> b;
	r=(((r/2)+(r%2))-1)*3+30;
	g=(((g/2)+(g%2))-1)*3+30+1;
	b=(((b/2)+(b%2))-1)*3+30+2;
	cout << max(max(r,g),b);
}