#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	vector<pair<int,int> > q;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		q.push_back({-(a+b+c+d),i});
	}
	sort(q.begin(), q.end());
	for(int i = 0; i < n; i++){
		if(q[i].second == 1){
			cout << i + 1 << endl;
		}
	}
}