#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
bool prime[2005];
vector<pair<llint, llint> > ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 2005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 2005; j+=i) prime[j] = true;
	}
	cin >> n;
	
	int m = n;
	for(int i = 1; i < n; i++) ans.push_back(make_pair(i, i+1));
	ans.push_back(make_pair(n, 1));
	
	int i = 1;
	while(prime[m]){
		m++;
		ans.push_back(make_pair(i, n-i));
		i++;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	flush(cout);
	
	return 0;
}