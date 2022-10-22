#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint n;
llint a[400005];
map<llint, llint> mp;
vector<P> vec;
BIT bit(400005);
llint amat[400005];
bool used[400005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) mp[a[i]]++;
	
	for(auto it = mp.begin(); it != mp.end(); it++){
		vec.push_back(P(it->second, it->first));
	}
	sort(vec.rbegin(), vec.rend());
	llint m = vec.size(), pos = m;
	vec.insert(vec.begin(), P(0, 0));
	
	llint ans = 0, ans_w, mx = vec[1].first;
	for(int w = 1; w <= n; w++){
		while(pos > 0 && vec[pos].first < w) pos--;
		for(int j = 1; j <= pos; j++) bit.add(j, 1);
		llint tmp = bit.query(m)/w*w, h = tmp / w;
		if(h < w) continue;
		if(ans < tmp){
			ans = tmp;
			ans_w = w;
		}
	}
	vector<llint> avec;
	/*llint cnt = 1, rem = ans;
	while(rem > 0){
		for(int i = 1; i <= m; i++){
			if(vec[i].first >= cnt) avec.push_back(vec[i].second), rem--;
			else break;
		}
		cnt++;
	}*/
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < min(vec[i].first, ans_w); j++) avec.push_back(vec[i].second);
	}
	avec.resize(ans);
	//sort(avec.begin(), avec.end());
	
	llint w = ans_w, h = ans/ans_w;
	llint x = 0, y = 0;
	for(int i = 0; i < avec.size(); i++){
		amat[y*w+x] = avec[i];
		used[y*w+x] = true;
		y = (y+1)%h, x = (x+1)%w;
		while(i < (int)avec.size()-1 && used[y*w+x]) y = (y+1)%h;
	}
	
	cout << ans << endl;
	cout << h << " " << w << endl;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cout << amat[y*w+x] << " ";
		}
		cout << endl;
	}
	
	return 0;
}