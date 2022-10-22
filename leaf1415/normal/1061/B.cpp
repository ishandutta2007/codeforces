#include <iostream>
#include <algorithm>
#include <map>
#define llint long long

using namespace std;

llint n, m;
llint a[100005];
map<llint, llint> mp;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	llint sum = 0, need = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			need++;
			if(a[i+1] == 0) break;
			else a[i+1] = 1;
			continue;
		}
		else if(a[i] == 0) break;
		if(a[i+1] >= a[i]-1){
			need++;
			a[i+1] = a[i]-1;
		}
		else need += a[i] - a[i+1];
	}
	cout << sum - need << endl;
	
	return 0;
}