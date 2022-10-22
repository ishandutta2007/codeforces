#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint a, b, c;
llint cost[20005], CC[20005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> a >> b >> c;
		for(int i = 1; i <= 20000; i++){
			llint x = abs(c/i*i-c), y = abs((c+i-1)/i*i-c), tmp;
			if(x <= y) tmp = x, CC[i] = c/i*i;
			else tmp = y, CC[i] = (c+i-1)/i*i;
			cost[i] = tmp + abs(b-i);
		}
		llint ans = 1e9, A, B, C;
		for(int i = 1; i <= 10000; i++){
			for(int j = i; j <= 20000; j+=i){
				if(ans > abs(i-a)+cost[j]){
					A = i, B = j, C = CC[j];
					ans = abs(i-a) + cost[j];
				}
			}
		}
		cout << ans << "\n";
		cout << A << " " << B << " " << C << "\n";
	}
	flush(cout);
	
	return 0;
}