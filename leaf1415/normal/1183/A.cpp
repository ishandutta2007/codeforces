#include <iostream>

using namespace std;

int a;

int get(int x)
{
	int ret = 0;
	for(;x;x/=10) ret += x%10;
	return ret;
}

int main(void)
{
	cin >> a;
	for(int i = a; ; i++){
		if(get(i)%4 == 0){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}