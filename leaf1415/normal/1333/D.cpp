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

int n, k;
string s;
vector<int> vec[3000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	
	llint rem = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'L') rem += cnt;
		else cnt++;
	}
	if(rem < k){
		cout << -1 << endl;
		return 0;
	}
	
	llint K = k;
	llint id = 1;
	while(rem > k){
		if(k < 0){
			cout << -1 << endl;
			return 0;
		}
		llint cnt = 0;
		for(int i = 1; i <= n-1; i++){
			if(s[i] == 'R' && s[i+1] == 'L') cnt++;
		}
		llint dec = min(rem-k+1, cnt);
		for(int i = 1; i <= n-1; i++){
			if(dec <= 0) break;
			if(s[i] == 'R' && s[i+1] == 'L'){
				swap(s[i], s[i+1]);
				vec[id].push_back(i);
				dec--;
				rem--;
				i++;
			}
		}
		id++; k--;
	}
	
	while(rem){
		for(int i = 1; i <= n-1; i++){
			if(rem <= 0) break;
			if(s[i] == 'R' && s[i+1] == 'L'){
				swap(s[i], s[i+1]);
				vec[id++].push_back(i);
				rem--;
			}
		}
	}
	
	for(int i = 1; i <= K; i++){
		cout << vec[i].size() << " ";
		for(int j = 0; j < vec[i].size(); j++) cout<< vec[i][j] << " ";
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}