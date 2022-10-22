#include <iostream>

using namespace std;

int n;
int p[200005], q[200005];
bool used[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n-1; i++) cin >> q[i];
	
	int mn = 0;
	for(int i = 2; i <= n; i++) p[i] = p[i-1] + q[i-1], mn = min(mn, p[i]);
	for(int i = 1; i <= n; i++) p[i] += 1 - mn;
	
	for(int i = 1; i <= n; i++){
		if(p[i] < 1 || p[i] > n){
			cout << -1 << endl;
			return 0;
		}
		used[p[i]] = true;
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
	
	return 0;
}