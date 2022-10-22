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

llint n;
vector<llint> vec;
llint res[13], ans[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	llint M = 1<<13;
	for(int i = 0; i < M; i++){
		llint cnt = 0;
		for(int j = 0; j < 13; j++){
			if(i & (1<<j)) cnt++;
		}
		if(cnt == 6) vec.push_back(i);
	}
	vec.resize(n);
	
	for(int i = 0; i < 13; i++){
		vector<llint> tmp;
		for(int j = 0; j < vec.size(); j++){
			if(vec[j]&(1<<i)) tmp.push_back(j);
		}
		if(tmp.size() == 0) continue;
		cout << "? " << tmp.size() << " ";
		for(int j = 0; j < tmp.size(); j++) cout << tmp[j]+1 << " ";
		cout << endl;
		
		cin >> res[i];
	}
	
	for(int i = 0; i < n; i++){
		llint sum = 0, x = vec[i];
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			llint y = vec[j];
			for(int k = 0; k < 13; k++){
				if(!(x&(1<<k)) && (y&(1<<k))){
					sum |= res[k];
					break;
				}
			}
		}
		ans[i] = sum;
	}
	
	cout << "! ";
	for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}