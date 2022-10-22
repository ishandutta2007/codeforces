#include <iostream>

using namespace std;

int a, b, c;
bool used[100005];

int main(void)
{
	cin >> a >> b >> c;
	a %= b;
	
	int ans = 0;
	while(1){
		if(used[a]){
			ans = -1;
			break;
		}
		used[a] = true;
		ans++;
		a *= 10;
		if(a / b == c) break;
		a %= b;
	}
	
	cout << ans << endl;
	return 0;
}