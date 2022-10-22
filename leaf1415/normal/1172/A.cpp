#include <iostream>
#include <deque>
#include <set>

using namespace std;

int n;
int a[200005];
int b[200005];
set<int> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i]) S.insert(a[i]);
	}
	int find = -1;
	for(int i = 1; i <= n; i++){
		if(b[i] == 1) find = i;
	}
	if(find != -1){
		bool flag = true;
		for(int j = find; j <= n; j++){
			if(b[j] != j-find+1) flag = false;
		}
		int k = b[n];
		if(flag){
			bool flag = true; int p = 1;
			for(int j = k+1; j <= n; j++){
				if(S.count(j) == 0){
					flag = false;
					break;
				}
				S.erase(j);
				if(b[p]) S.insert(b[p]);
				p++;
			}
			if(flag){
				cout << n-k << endl;
				return 0;
			}
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i]) ans = max(ans, n-a[i]+1);
	}
	for(int i = 1; i <= n; i++){
		if(b[i]) ans = max(ans, n-b[i]+1+i);
	}
	cout << ans << endl;
	
	return 0;
}