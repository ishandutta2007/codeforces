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

llint n, k;
vector<llint> vecA, vecB, vecAB, vecO;
vector<llint> sumA, sumB, sumAB, sumO;

void make(vector<llint> vec, vector<llint> &sum)
{
	sum.push_back(0);
	llint s = 0;
	for(int i = 0; i < vec.size(); i++){
		s += vec[i];
		sum.push_back(s);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint t, a, b;
	for(int i = 1; i <= n; i++){
		cin >> t >> a >> b;
		if(a == 0){
			if(b == 0) vecO.push_back(t);
			else vecB.push_back(t);
		}
		else{
			if(b == 0) vecA.push_back(t);
			else vecAB.push_back(t);
		}
	}
	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());
	sort(vecAB.begin(), vecAB.end());
	sort(vecO.begin(), vecO.end());
	
	make(vecA, sumA);
	make(vecB, sumB);
	make(vecAB, sumAB);
	make(vecO, sumO);
	
	llint ans = inf;
	for(int i = 0; i <= min(k, (llint)vecAB.size()); i++){
		llint tmp = sumAB[i];
		if(vecA.size() < k-i || vecB.size() < k-i) continue;
		tmp += sumA[k-i] + sumB[k-i];
		ans = min(ans, tmp);
	}
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}