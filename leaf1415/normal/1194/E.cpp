#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define llint long long
#define inf 1000000000

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> L;

struct BIT{
	int size;
	vector<int> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, int x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint sx[5005], sy[5005], tx[5005], ty[5005];
vector<llint> compX, compY;
vector<L> vec, vec2;
BIT bit(10005);
llint a[10005];

void comp(llint s[], llint t[], vector<llint> &vec)
{
	for(int i = 1; i <= n; i++){
		vec.push_back(s[i]);
		vec.push_back(t[i]);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i = 1; i <= n; i++){
		s[i] = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin() + 1;
		t[i] = lower_bound(vec.begin(), vec.end(), t[i]) - vec.begin() + 1;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
	}
	comp(sx, tx, compX);
	comp(sy, ty, compY);
	
	for(int i = 1; i <= n; i++){
		if(sy[i] == ty[i]){
			if(sx[i] > tx[i]) swap(sx[i], tx[i]);
			vec.push_back(make_pair(sy[i], make_pair(sx[i], tx[i])));
		}else{
			if(sy[i] > ty[i]) swap(sy[i], ty[i]);
			vec.push_back(make_pair(sy[i], make_pair(-inf, sx[i])));
			vec.push_back(make_pair(ty[i], make_pair(inf, sx[i])));
		}
	}
	sort(vec.begin(), vec.end());
	
	/*for(int i = 1; i <= n; i++){
		cout << sx[i] << " " << sy[i] << " " << tx[i] << " " << ty[i] << endl;
	}*/
	/*for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
	}*/
	
	llint ans = 0;
	for(int i = 0; i < vec.size(); i++){
		//cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
		if(vec[i].second.first <= -inf){
			a[vec[i].second.second] = vec[i].first;
			continue;
		}
		else if(vec[i].second.first >= inf){
			a[vec[i].second.second] = 0;
			continue;
		}
		bit.init();
		
		llint l = vec[i].second.first, r = vec[i].second.second;
		for(int j = 0; j < i; j++){
			if(vec[j].second.first <= -inf){
				if(a[vec[j].second.second] == vec[j].first){
					bit.add(vec[j].second.second, 1);
				}
			}
			else if(vec[j].second.first < inf){
				llint ll = vec[j].second.first, rr = vec[j].second.second; 
				ll = max(ll, l), rr = min(rr, r);
				if(ll > rr) continue;
				llint num = bit.query(rr) - bit.query(ll-1);
				ans += num * (num-1) /2;
			}
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
	
	return 0;
}