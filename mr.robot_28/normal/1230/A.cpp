#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a + b == c + d || a + c == b + d || a + d == b + c || a == b + c + d || b == c + d + a || c == a + b + d || d == a + b + c){
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}