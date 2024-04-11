#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int n, t;
int s[105], d[105];
vector<P> vec;

int main(void)
{
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> s[i] >> d[i];
	for(int i = 1; i <= n; i++){
		vec.push_back(make_pair(s[i], i));
		for(int j = s[i]; j <= t+d[i]; j += d[i]){
			vec.push_back(make_pair(j, i));
		}
	}
	sort(vec.begin(), vec.end());
	
	int p = lower_bound(vec.begin(), vec.end(), make_pair(t, 0)) - vec.begin();
	cout << vec[p].second << endl;
	return 0;
}