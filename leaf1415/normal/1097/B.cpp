#include <iostream>

using namespace std;

int n;
int a[16];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int N = 1<<n, sum;
	for(int i = 0; i < N; i++){
		sum = 0;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) sum += a[j], sum %= 360;
			else sum += 360-a[j], sum %= 360;
		}
		if(sum == 0){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}