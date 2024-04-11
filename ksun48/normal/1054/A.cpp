#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	LL x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	LL stime = t1 * abs(x-y);
	LL etime = t2 * abs(x-z) + t3 + t3 + t2 * abs(x-y) + t3;
	if(stime < etime){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}