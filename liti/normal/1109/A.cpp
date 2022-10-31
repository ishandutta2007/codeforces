#include <iostream>
using namespace std;

const int maxN = 2 * 1000 * 1000 + 10; 

int cnt[2][maxN]; 

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int sum = 0;
	long long ans = 0;
	cnt[1][0] = 1;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum ^= x;
		ans += cnt[i%2][sum];
		cnt[i%2][sum]++;
	}
	cout << ans << endl;
}