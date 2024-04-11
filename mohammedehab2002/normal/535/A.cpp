#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	string num[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},s[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	cin >> n;
	if (n<20)
	cout << num[n];
	else
	{
		if (n%10)
		cout << s[(n/10)-2] << '-' << num[n%10];
		else
		cout << s[(n/10)-2];
	}
}