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

llint T;
llint n;
llint a[1005];
bool have[1005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		
		vec.clear();
		while(1){
			bool flag = true;
			for(int i = 0; i < n; i++) flag &= (a[i] == i);
			if(flag) break;
			
			for(int i = 0; i <= n; i++) have[i] = false;
			for(int i = 0; i < n; i++) have[a[i]] = true;
			
			llint mex = 0;
			for(int i = 0; i <= n; i++){
				if(!have[i]){
					mex = i;
					break;
				}
			}
			
			if(mex == n){
				for(int i = 0; i < n; i++){
					if(a[i] != i){
						vec.push_back(i);
						a[i] = mex;
						break;
					}
				}
			}
			else{
				vec.push_back(mex);
				a[mex] = mex;
			}
		}
		
		cout << vec.size() << endl;
		for(int i = 0; i < vec.size(); i++) cout << vec[i]+1 << " ";
		cout << endl;
	}
	
	return 0;
}