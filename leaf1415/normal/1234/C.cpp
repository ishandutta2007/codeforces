#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
llint n;
llint a[200005][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		char c;
		for(int j = 0; j < 2; j++){
			for(int i = 1; i <= n; i++){
				cin >> c;
				a[i][j] = c - '0';
				if(a[i][j] >= 3) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		
		int pos = 0;
		for(int i = 1; i <= n; i++){
			if(a[i][pos] == 0) continue;
			else{
				if(a[i][1-pos] == 0){
					cout << "NO" << "\n";
					goto end;
				}
				pos = 1-pos;
			}
			//cout << i << " " << pos << endl;
		}
		if(pos == 0) cout << "NO" << "\n";
		else cout << "YES" << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}