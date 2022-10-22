#include <iostream>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1000000000000000000

using namespace std;

string s;
llint cnt[15];
llint cost[15];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for(int i = 1; i < s.size(); i++){
		int a = s[i]-'0', b = s[i-1]-'0';
		cnt[(a-b+10)%10]++;
	}
	
	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			for(int g = 0; g < 10; g++){
				llint mn = inf;
				for(llint i = 0; i <= 10; i++){
					for(llint j = 0; j <= 10; j++){
						if(i+j == 0) continue;
						if((i*x+j*y)%10 == g) mn = min(mn, i+j);
					}
				}
				cost[g] = mn-1;
			}
			llint ans = 0;
			for(int g = 0; g < 10; g++){
				if(cnt[g] > 0 && cost[g] > inf/2){
					ans = -1;
					break;
				}
				ans += cnt[g] * cost[g];
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	
	return 0;
}