#include <iostream>
#include <algorithm>
using namespace std;

int n, load[100005];

int main(){
	int i, sum = 0, ans = 0;
	cin >> n;
	for(i = 1; i <= n; ++ i){
		cin >> load[i];
		sum += load[i];
	}
	sort(load + 1, load + 1 + n);
	for(i = n; i; -- i)
		if(n - i + 1 <= sum % n) ans += abs(load[i] - (sum / n + 1));
		else ans += abs(load[i] - sum / n);
	cout << (ans >> 1) << endl;
	return 0;
}