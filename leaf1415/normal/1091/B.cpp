#include <iostream>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> P;

int n;
int x[1005], y[1005];
int a[1005], b[1005];
set<P> s;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	
	if(n == 1){
		cout << x[1]+a[1] << " " << y[1]+b[1] << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		int tx = x[1]+a[i], ty = y[1]+b[i];
		s.clear();
		for(int j = 1; j <= n; j++){
			if(i != j) s.insert(make_pair(a[j], b[j]));
		}
		for(int j = 2; j <= n; j++){
			P p = make_pair(tx-x[j], ty-y[j]);
			if(s.count(p)) s.erase(p);
			else goto end;
		}
		cout << tx << " " << ty << endl;
		return 0;
		end:;
	}
	
	return 0;
}