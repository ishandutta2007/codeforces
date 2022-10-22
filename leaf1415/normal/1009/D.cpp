#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
bool prime[100005];
vector<pair<int, int> > ans;
vector<int> pvec;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	/*for(int i = 2; i <= 1005; i++){
		if(!prime[i]) pvec.push_back(i);
		for(int j = 2*i; j < 100005; j += i) prime[j] = true;
	}*/
	
	cin >> n >> m;
	if(m < n-1){
		cout << "Impossible" << endl;
		return 0;
	}
	
	for(int i = 2; i <= n; i++){
		ans.push_back(make_pair(1, i));
		m--;
	}
	
	if(m <= 0) goto ok;
	for(int i = 2; i < n; i++){
		for(int j = i+1; j <= n; j++){
			if(gcd(i, j) > 1) continue;
			ans.push_back(make_pair(i, j));
			m--;
			if(m <= 0) goto ok;
		}
	}
	cout << "Impossible" << endl;
	return 0;
	
	ok:
	cout << "Possible" << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
	
}