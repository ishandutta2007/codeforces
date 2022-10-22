#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
llint n;
llint a[200005];
llint ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int pos = -1;
		for(int i = 0; i < n; i++){
			if(a[i] == a[(i+1)%n]){
				pos = i;
				break;
			}
		}
		sort(a, a+n);
		
		if(a[0] == a[n-1]){
			cout << 1 << "\n";
			for(int i = 0; i < n; i++) cout << 1 << " ";
			cout << "\n";
			continue;
		}
		if(n % 2 == 0){
			cout << 2 << "\n";
			for(int i = 0; i < n; i++) cout << (i%2)+1 << " ";
			cout << "\n";
			continue;
		}
		
		if(pos != -1){
			cout << 2 << "\n";
			ans[pos] = ans[(pos+1)%n] = 2;
			for(int i = 2; i < n; i++) ans[(pos+i)%n] = (i%2)+1;
			for(int i = 0; i < n; i++) cout << ans[i] << " ";
			cout << "\n";
			continue;
		}
			
		cout << 3 << "\n";
		cout << 3 << " ";
		for(int i = 1; i < n; i++) cout << (i%2)+1 << " ";
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}