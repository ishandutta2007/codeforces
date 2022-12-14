#include <iostream>
#include <string>
using namespace std;
typedef long long int ll;
string str;
ll lefti,righti;
int main()
{
	cin >> str;
	int len = str.length() ,i ,j ,sign;
	for(i = 0;i < len;i ++)
		if(str[i] == '^')
		{
			sign = i;
			break;
		}
	for(i = sign - 1,j = 1;i >= 0;i --,j ++)
		if(str[i] >= '1' && str[i] <= '9')
			lefti += (str[i] - '0') * j;
	for(i = sign + 1,j = 1;i < len;i ++,j ++)
		if(str[i] >= '1' && str[i] <= '9')
			righti += (str[i] - '0') * j;
	if(righti > lefti)
		cout << "right";
	else if(righti < lefti)
		cout << "left";
	else cout << "balance";
	return 0;
}