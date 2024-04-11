#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint x0, y0, ax, ay, bx, by;
llint sx, sy, t;
vector<llint> vecx, vecy;
vector<P> vec;

llint make(vector<llint> &vec, llint x0, llint a, llint b)
{
	vec.push_back(x0);
	llint x = x0;
	while(1){
		x = a*x+b;
		if(x > 3e16) break;
		vec.push_back(x);
	}
}

llint dist(llint sx, llint sy, llint tx, llint ty)
{
	return abs(sx-tx) + abs(sy-ty);
}

llint calc()
{
	llint ret = 0;
	//for(int i = 0; i < vec.size(); i++)  cout << vec[i].first << " " << vec[i].second << endl;
	
	for(int k = 0; k < vec.size(); k++){
		llint d0 = dist(sx, sy, vec[k].first, vec[k].second);
		if(d0 > t) continue;
		for(int i = 0; i < vec.size(); i++){
			llint x = vec[k].first, y = vec[k].second, cnt = 1, d = d0;
			for(int j = i; j < vec.size(); j++){
				if(j == k) continue;
				d += dist(x, y, vec[j].first, vec[j].second);
				if(d > t) break;
				cnt++;
				x = vec[j].first, y = vec[j].second;
			}
			ret = max(ret, cnt);
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> sx >> sy >> t;
	
	make(vecx, x0, ax, bx);
	make(vecy, y0, ay, by);
	
	llint m = min((int)vecx.size(), (int)vecy.size());
	for(int i = 0; i < m; i++){
		vec.push_back(P(vecx[i], vecy[i]));
	}
	
	llint ans = calc();
	reverse(vec.begin(), vec.end());
	ans = max(ans, calc());
	cout << ans << endl;
	
	return 0;
}