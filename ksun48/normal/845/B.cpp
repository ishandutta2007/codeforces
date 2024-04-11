#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int ans = 7;
	int f;
	cin >> f;
	for(int i = 0; i < 1000000; i++){
		vector<int> g1, g2;
		int g = i;
		int f2 = f;
		for(int j = 0; j < 6; j++){
			g1.push_back(f2%10);
			g2.push_back(g%10);
			f2/=10; g/=10;
		}
		if(g2[0] + g2[1] + g2[2] != g2[3] + g2[4] + g2[5]) continue;
		int cur = 0;
		for(int mm = 0; mm < 6; mm++){
			if(g1[mm] != g2[mm]) cur++;
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}