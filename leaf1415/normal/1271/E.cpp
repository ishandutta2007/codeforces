#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	llint ans = 1, x = 0;
	for(int i = 60; i >= 0; i--){
		x <<= 1LL, x += (n >> i)&1LL;
		
		llint cnt = n % (1LL<<i) + 1;
		cnt += (1LL<<i)-1;
		if(x > 0 && cnt >= k) ans = max(ans, x);
		
		if(n & (1LL<<i)){
			cnt += (1LL<<(i+1))-1;
			if(x-1 > 0 && cnt >= k) ans = max(ans, x-1);
		}
		else{
			cnt += (1LL<<i)-1;
			if(x > 0 && cnt >= k) ans = max(ans, x);
			
			cnt = (1LL<<i)-1;
			if(x > 0 && cnt >= k) ans = max(ans, x+1);
		}
		
		if(x-1 > 0 && (n & (1LL<<i))){
			llint y = x-1;
			for(int j = i-1; j >= 0; j--){
				y <<= 1LL, y++;
				llint cnt = (1LL<<(j+1))-1;
				if(cnt >= k) ans = max(ans, y);
				if(cnt*2 >= k) ans = max(ans, y-1);
			}
		}
		if(x > 0 && (n & (1LL<<i)) == 0){
			llint y = x+1;
			for(int j = i-1; j > 0; j--){
				y <<= 1LL, y++;
				llint cnt = (1LL<<j)-1;
				if(cnt >= k) ans = max(ans, y);
				if(cnt*2 >= k) ans = max(ans, y-1);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}