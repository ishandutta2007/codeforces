#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int n, k;
int a[5005];
pair<int, int> p[5005];
int cnt[5005];
int ans[5005];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cnt[a[i]]++;
	for(int i = 1; i <= 5000; i++){
		if(cnt[i] > k){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < n; i++) p[i] = make_pair(a[i], i);
	sort(p, p+n);
	
	for(int i = 0; i < n; i++) ans[p[i].second] = i%k;
	cout << "YES" << endl;
	for(int i = 0; i < n; i++) cout << ans[i]+1 << " "; cout << endl;
	
	return 0;
}