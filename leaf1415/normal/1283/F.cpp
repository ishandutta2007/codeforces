#include <iostream>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
bool used[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n-1; i++) cin >> a[i];
	
	llint p = a[1], mx = n;
	used[p] = true;
	
	cout << p << endl;
	for(int i = 2; i <= n-1; i++){
		if(used[a[i]]){
			while(used[mx]) mx--;
			cout << p << " " << mx << endl;
			p = a[i];
			used[mx] = true;
		}
		else{
			cout << p << " " << a[i] << endl;
			used[a[i]] = true;
			p = a[i];
		}
	}
	while(used[mx]) mx--;
	cout << p << " " << mx << endl;
	
	return 0;
}