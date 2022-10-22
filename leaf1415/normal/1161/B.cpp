#include <iostream>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> P;

int n, m;
set<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		a--, b--;
		S.insert(make_pair(a, b));
	}
	
	for(int i = 1; i < n; i++){
		if(n%i) continue;
		bool flag = true;
		for(auto it = S.begin(); it != S.end(); it++){
			P p = *it;
			(p.first += i) %= n;
			(p.second += i) %= n;
			if(!S.count(p) && !S.count(make_pair(p.second, p.first))){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" <<endl;
	return 0;
}