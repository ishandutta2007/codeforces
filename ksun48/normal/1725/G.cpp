#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int64_t N;
	cin >> N;
	int64_t ans;
	if(N == 1){
		ans = 3;
	} else if(N % 3 == 0){
		ans = (N / 3) * 4 + 3;
	} else if(N % 3 == 1){
		ans = (N / 3) * 4 + 4;
	} else if(N % 3 == 2){
		ans = (N / 3) * 4 + 5;
	}
	cout << ans << '\n';
}