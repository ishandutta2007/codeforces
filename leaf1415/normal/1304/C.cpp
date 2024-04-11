#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint n, m;
llint t[105], l[105], r[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++){
			cin >> t[i] >> l[i] >> r[i];
		}
		
		llint time = 0, lb = m, ub = m;
		for(int i = 1; i <= n; i++){
			ub += (t[i]-time);
			lb -= (t[i]-time);
			lb = max(lb, l[i]);
			ub = min(ub, r[i]);
			if(lb > ub){
				cout << "NO" << endl;
				goto end;
			}
			time = t[i];
		}
		cout << "YES" << endl;
		
		end:;
	}
	
	return 0;
}