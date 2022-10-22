#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint d[100005];
vector<P> vec;
vector<llint> vec2[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> d[i];
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(d[i], 2*i-1));
	sort(vec.rbegin(), vec.rend());
	
	for(int i = 1; i <= n; i++){
		vec2[i].push_back(vec[i-1].second);
		if(i < n) cout << vec[i-1].second << " " << vec[i].second << endl;
	}
	for(int i = 0; i < n; i++){
		llint p = vec[i].first + i;
		cout << vec2[p][0] << " " << vec[i].second+1 << endl;
		vec2[p+1].push_back(vec[i].second+1);
	}
	
	
	return 0;
}