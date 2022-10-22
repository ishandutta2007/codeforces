#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, a, b, k;
llint h[200005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> a >> b >> k;
	for(int i = 1; i <= n; i++) cin >> h[i];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint r = (h[i]-1) % (a+b);
		if(r < a) vec.push_back(0);
		else vec.push_back((r)/a);
	}
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	sort(vec.begin(), vec.end());
	vec.push_back(inf);
	
	llint sum = 0;
	for(int i = 0; i < vec.size(); i++){
		sum += vec[i];
		if(sum > k){
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}