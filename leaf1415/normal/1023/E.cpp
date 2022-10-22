#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n;
string ans, ans2;
int di[] = {1, 0}, dj[] = {0, 1};

int dist(int x, int y, int x2, int y2){
	return abs(x-x2) + abs(y-y2);
}

int main(void)
{
	cin >> n;
	
	int pi = 1, pj = 1;
	string res;
	while(1){
		//cout << pi << " " << pj << endl;
		int ni, nj;
		for(int i = 0; i < 2; i++){
			ni = pi + di[i], nj = pj + dj[i];
			if(ni > n || nj > n) continue;
			if(dist(ni, nj, n, n) >= n-1){
				cout << "? " << ni << " " << nj << " " << n << " " << n << " " << endl;
				cin >> res;
			}
			else goto end;
			if(res == "BAD") return 0;
			if(res == "YES"){
				pi = ni, pj = nj;
				if(i == 0) ans += "D";
				else ans += "R";
				break;
			}
		}
	}
	end:;
	
	int xi = pi, xj = pj;
	pi = n, pj = n;
	while(1){
		int ni, nj;
		for(int i = 1; i >= 0; i--){
			ni = pi - di[i], nj = pj - dj[i];
			if(ni <= 0 || nj <= 0) continue;
			if(dist(ni, nj, 1, 1) >= n-1){
				cout << "? " << 1 << " " << 1 << " " << ni << " " << nj << " " << endl;
				cin >> res;
			}
			if(res == "BAD") return 0;
			if(res == "YES"){
				pi = ni, pj = nj;
				if(i == 0) ans2 += "D";
				else ans2 += "R";
				break;
			}
		}
		if(pi == xi && pj == xj) break;
	}
	
	reverse(ans2.begin(), ans2.end());
	cout << "! " << ans+ans2 << endl;
	return 0;
}