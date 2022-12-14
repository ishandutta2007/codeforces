#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
typedef pair <LL, LL> pii;

vector <pii> ans;
vector <pii> :: iterator it;

int main(){
	LL i, m, x, t;
	cin >> x;
	for(i = 1LL; (t = 2LL * (x + (i - 1LL) * i * (i + 1LL) / 6LL)) >= i * i * (i + 1LL); ++ i){
		if(t % (i * (i + 1LL))) continue;
		m = t / i / (i + 1LL);
		ans.push_back(pii(i, m));
		if(i != m) ans.push_back(pii(m, i));
	} sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(it = ans.begin(); it != ans.end(); ++ it)
		cout << it -> first << ' ' << it -> second << endl;
	return 0;
}