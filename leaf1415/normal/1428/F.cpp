#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
string s;
vector<llint> res, res2;
llint p[5000005], len[500005];

llint calc(string s, vector<llint> &vec, llint b)
{
	s = "#" + s;
	for(int i = 0; i <= n; i++) p[i] = 0;
	
	int cnt = 0;
	for(int i = n; i >= 0; i--){
		if(s[i] == '1') cnt++;
		else cnt = 0;
		len[i] = cnt;
	}
	
	//for(int i = 0; i <= n; i++) cout << len[i] << " "; cout << endl;
	
	llint ret = 0;
	for(int i = 1; i <= n; i++){
		if(len[i-1] == 0 && len[i] != 0){
			llint sum = 0;
			for(int j = len[i]-1; j >= 1; j--){
				sum += j * (i - p[j + b]);
			}
			ret += sum;
			vec.push_back(i - p[len[i] + b]);
		}
		p[len[i]] = i;
	}
	
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	llint ans = 0, cnt = 0;
	vector<llint> vec;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') cnt++;
		else{
			if(cnt > 0) vec.push_back(cnt);
			cnt = 0;
		}
	}
	if(cnt > 0) vec.push_back(cnt);
	
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] >= 3){
			llint l = vec[i]-2;
			ans += (l+1)*l*(l+1)/2 - l*(l+1)*(2*l+1)/6;
		}
	}
	ans += calc(s, res, 0);
	reverse(s.begin(), s.end());
	
	//cout << ans << endl;
	
	ans += calc(s, res2, 1);
	reverse(res2.begin(), res2.end());
	
	for(int i = 0; i < vec.size(); i++) ans += vec[i] * res[i] * res2[i];
	cout << ans << endl;
	
	return 0;
}