#include <iostream>
#define inf 1000000000

using namespace std;

int n;
int p[100005];
int max1[100005], max2[100005];
int cnt[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	if(n <= 2){
		cout << p[1] << endl;
		return 0;
	}
	
	for(int i = 0; i <= n; i++){
		max1[i] = max2[i] = -1;
	}
	
	int max_i = inf;
	for(int i = 1; i <= n; i++){
		if(max1[i-1] <= p[i]){
			max2[i] = max1[i-1];
			max1[i] = p[i];
		}
		else if(max2[i-1] <= p[i]){
			max1[i] = max1[i-1];
			max2[i] = p[i];
		}
		else{
			max1[i] = max1[i-1];
			max2[i] = max2[i-1];
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(max1[i-1] >= p[i] && max2[i-1] < p[i]){
			cnt[max1[i-1]]++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(max1[i-1] < p[i]){
			cnt[p[i]]--;
		}
	}
	
	int max_v = -inf, ans;
	for(int i = 1; i <= n; i++){
		if(max_v < cnt[i]){
			max_v = cnt[i];
			ans = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}