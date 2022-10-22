#include <iostream>

using namespace std;

int N;

int main(void)
{
	cin >> N;
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = max(ans, (i+1)*(N-i));
	}
	cout << ans << endl;
	return 0;
}