#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cmath>
#define llint long long
#define inf 1e18
#define eps 1e-12
#define PI 3.141592653589793238462643383279550288497693993L

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
long double x[2505], y[2505];

llint calc(llint id)
{
	vector<long double> tmp;
	for(int i = 1; i <= n; i++){
		if(i == id) continue;
		tmp.push_back(atan2l(y[i]-y[id], x[i]-x[id]));
	}
	sort(tmp.begin(), tmp.end());
	vector<long double> vec = tmp;
	for(int i = 0; i < tmp.size(); i++) tmp[i] += PI * 2;
	vec.insert(vec.end(), tmp.begin(), tmp.end());
	
	llint ret = (n-1)*(n-2)*(n-3)*(n-4)/24, r = -1;
	//cout << ret << endl;
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	for(int i = 0; i < n-1; i++){
		while(r+1 < (int)vec.size() && vec[r+1] < vec[i] + PI) r++;
		llint len = r-i+1;
		if(len < 4) continue;
		ret -= (len-1)*(len-2)*(len-3)/6;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += calc(i);
	cout << ans << endl;
	
	return 0;
}