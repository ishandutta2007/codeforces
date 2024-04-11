#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#define llint long long

using namespace std;

int n;
int a[400005];
vector<int> vec;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	//cin >> n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	int ans = 0;
	for(int i = 0; i < 25; i++){
		llint cnt = 0;
		int R = (1<<(i+1));
		
		vec.clear();
		for(int j = 1; j <= n; j++) vec.push_back(a[j] % R);
		sort(vec.begin(), vec.end());
		
		for(int j = 1; j <= n; j++){
			int r = a[j] % R;
			if(r < (1<<i)){
				cnt += lower_bound(vec.begin(), vec.end(), R - r) - lower_bound(vec.begin(), vec.end(), (1<<i) - r);
			}
			else{
				cnt += lower_bound(vec.begin(), vec.end(), R - r) - vec.begin();
				cnt += lower_bound(vec.begin(), vec.end(), R) - lower_bound(vec.begin(), vec.end(), R - ((1<<i)-(R-r)));
			}
			if((a[j]+a[j]) & (1<<i)) cnt--;
		}
		cnt/=2;
		ans |= (cnt&1) << i;
	}
	cout << ans << endl;
	
	return 0;
}