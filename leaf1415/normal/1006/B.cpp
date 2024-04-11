#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, k;
int a[2005];
bool used[2005];
vector<pair<int, int> > vec;

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) vec.push_back(make_pair(a[i], i));
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	int ans = 0;
	for(int i = 0; i < k; i++){
		ans += vec[i].first;
		used[vec[i].second] = true;
	}
	cout << ans << endl;
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt++;
		if(used[i] & k > 1){
			cout << cnt << " ";
			cnt = 0;
			k--;
		}
	}
	cout << cnt << endl;
	return 0;
}