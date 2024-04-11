#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	multiset<LL> dog;
	for(int i = 0; i < n; i++){
		LL a;
		cin >> a;
		dog.insert(a);
	}
	pair<LL,LL> z[m];
	for(int i = 0; i < m; i++){
		LL u, t;
		cin >> u >> t;
		LL a = u-t;
		LL b = u+t;
		z[i].first = b;
		z[i].second = -a;
	}
	sort(z, z+m);
	for(int i = 0; i < m; i++){
		z[i].second = -z[i].second;
		swap(z[i].second, z[i].first);
	}
	LL ans = 0;
	for(int i = 0; i < m; i++){
		LL a = z[i].first;
		if(dog.lower_bound(a) != dog.end()){
			LL d = *dog.lower_bound(a);
			if(d <= z[i].second){
				ans++;
				dog.erase(dog.lower_bound(a));
			}
		}
	}
	cout << ans << endl;
}