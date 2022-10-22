#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int t;
int n, k;
int x[205];

int main(void)
{
	cin >> t;
	for(int c = 0; c < t; c++){
		cin >> n >> k;
		for(int i = 0; i < k; i++) cin >> x[i];
		
		int ans = 0, tmp;
		for(int i = 1; i <= n; i++){
			tmp = 100000;
			for(int j = 0; j < k; j++){
				tmp = min(tmp, abs(i - x[j])+1);
			}
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
	
	return 0;
}