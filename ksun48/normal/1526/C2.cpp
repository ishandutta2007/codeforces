#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	multiset<int> r;
	int64_t sum = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x + sum >= 0){
			r.insert(x);
			sum += x;
		} else if(!r.empty() && x >= (*r.begin())){
			sum -= (*r.begin());
			r.erase(r.begin());
			sum += x;
			r.insert(x);
		}
	}
	cout << r.size() << '\n';
}