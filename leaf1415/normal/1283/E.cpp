#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n;
llint x[200005], cnt[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) cnt[x[i]]++;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] > 0){
			cnt[i] = cnt[i+1] = cnt[i+2] = 0;
			ans++;
		}
	}
	cout << ans << " ";
	
	for(int i = 1; i <= n; i++) cnt[i] = 0;
	for(int i = 1; i <= n; i++) cnt[x[i]]++;
	ans = 0;
	
	for(int i = 0; i <= n+1; i++){
		if(i > 0 && cnt[i-1] > 0){
			ans++;
			cnt[i-1]--;
		}
		else if(cnt[i] > 0){
			ans++;
			cnt[i]--;
		}
		else if(cnt[i+1] > 0){
			ans++;
			cnt[i+1]--;
		}
	}
	cout << ans << endl;
	
	return 0;
}