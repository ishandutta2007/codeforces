#include <iostream>

using namespace std;

int n;
int fib[105];
bool used[1005];

int main(void)
{
	cin >> n;
	
	fib[0] = fib[1] = 1;
	for(int i = 2; i < 105; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	for(int i = 0; i < 105; i++){
		if(fib[i] >= 1005) break;
		used[ fib[i] ] = true;
	}
	
	for(int i = 1; i <= n; i++){
		if(used[i]) cout << "O";
		else cout << "o";
	}
	cout << endl;
	return 0;
}