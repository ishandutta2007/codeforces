#include <iostream>

using namespace std;

int k;

int sum(int n)
{
	int ret = 0;
	for(; n; n/=10){
		ret += n % 10;
	}
	return ret;
}

int main(void)
{
	cin >> k;
	
	int i, cnt = 0;
	for(i = 1; ; i++){
		if(sum(i) == 10) cnt++;
		if(cnt == k) break;
	}
	
	cout << i << endl;
	return 0;
}