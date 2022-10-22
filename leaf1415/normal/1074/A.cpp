#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int n, m;
int vx[100005];
int hx1[100005], hx2[100005], hy[100005];
map<int, vector<P> > mp;
vector<int> vec;

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> vx[i];
	sort(vx, vx+n);
	vx[n] = 1000000000;
	for(int i = 0; i < m; i++) cin >> hx1[i] >> hx2[i] >> hy[i];
	
	for(int i = 0; i < m; i++){
		mp[hy[i]].push_back(make_pair(hx1[i], hx2[i]));
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		sort(it->second.begin(), it->second.end());
		int pre = 0;
		for(int i = 0; i < it->second.size(); i++){
			if(it->second[i].first > pre+1){
				vec.push_back(pre+1);
				goto end;
			}
			pre = it->second[i].second;
		}
		vec.push_back(pre+1);
		end:;
	}
	sort(vec.begin(), vec.end());
	
	int ans = n+m;
	for(int i = 0; i <= n; i++){
		ans = min(ans, (int)vec.size() - (upper_bound(vec.begin(), vec.end(), vx[i]) - vec.begin()) + i);
	}
	cout << ans << endl;
	
	return 0;
}