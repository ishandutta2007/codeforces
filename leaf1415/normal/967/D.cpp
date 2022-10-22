#include <iostream>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, x1, x2;
llint c[300005];
P tmp[300005];

llint use1, use2;

bool check(llint x1, llint x2)
{
	llint val;
	
	use1 = -1;
	for(int i = 0; i < n; i++){
		val = c[i] * (i+1);
		if(val >= x1){
			use1 = i;
			break;
		}
	}
	if(use1 == -1) return false;
	
	use2 = -1;
	for(int i = use1+1; i < n; i++){
		val = c[i] * (i - use1);
		if(val >= x2){
			use2 = i;
			break;
		}
	}
	if(use2 == -1) return false;
	
	return true;
}

int main(void)
{
	cin >> n >> x1 >> x2;
	for(int i = 0; i < n; i++) cin >> c[i];
	
	for(int i = 0; i < n; i++) tmp[i] = make_pair(c[i], i);
	sort(tmp, tmp+n);
	reverse(tmp, tmp+n);
	for(int i = 0; i < n; i++) c[i] = tmp[i].first;
	
	if(check(x1, x2)){
		cout << "Yes" << endl;
		cout << use1+1 << " " << use2 - use1 << endl;
		for(int i = 0; i <= use1; i++) cout << tmp[i].second+1 << " "; cout << endl;
		for(int i = use1+1; i <= use2; i++) cout << tmp[i].second+1 << " "; cout << endl;
		return 0;
	}
	
	if(check(x2, x1)){
		cout << "Yes" << endl;
		cout << use2 - use1 << " " << use1+1 << endl;
		for(int i = use1+1; i <= use2; i++) cout << tmp[i].second+1 << " "; cout << endl;
		for(int i = 0; i <= use1; i++) cout << tmp[i].second+1 << " "; cout << endl;
		return 0;
	}
	cout << "No" << endl;
	
	return 0;
}