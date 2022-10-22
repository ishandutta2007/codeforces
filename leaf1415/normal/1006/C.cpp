#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[200005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint lsum = 0, rsum = 0, lpos = -1, ans = 0;
	for(int i = n-1; i >= 0; i--){
		rsum += a[i];
		while(lsum < rsum){
			lpos++;
			if(lpos >= n) goto end;
			lsum += a[lpos];
		}
		if(lpos >= i) break;
		if(lsum == rsum) ans = max(ans, lsum);
	}
	end:;
	cout << ans << endl;
}