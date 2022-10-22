#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[100005];
llint l[100005], r[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) l[i] = l[i-1] | a[i];
	for(int i = n; i >= 1; i--) r[i] = r[i+1] | a[i];
	
	llint ans = -1, ans_i;
	for(int i = 1; i <= n; i++){
		llint x = a[i] & ~(l[i-1]|r[i+1]);
		if(x > ans){
			ans = x;
			ans_i = i;
		}
	}
	
	cout << a[ans_i] << " ";
	for(int i = 1; i <= n; i++){
		if(i != ans_i) cout << a[i] << " ";
	}
	cout << endl;
	
	return 0;
}