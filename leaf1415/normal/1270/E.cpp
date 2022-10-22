#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint x[1005], y[1005];
vector<llint> vec;

llint div(llint x)
{
	if(x >= 0) return x/2;
	else return -abs((x+1)/2);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	while(1){
		vec.clear();
		for(int i = 1; i <= n; i++){
			if(abs(x[i])%2 == abs(y[i])%2) vec.push_back(i);
		}
		if(vec.size() >= 1 && vec.size() < n) break;
		
		if(abs(x[1]) % 2 != abs(y[1]) % 2){
			for(int i = 1; i <= n; i++) x[i]++;
		}
		for(int i = 1; i <= n; i++){
			llint u = (x[i]+y[i])/2, v = (x[i]-y[i])/2;
			x[i] = u, y[i] = v;
		}
	}
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	return 0;
}