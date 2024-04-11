#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> d2cistoohard = {
0,
0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		int a;
		cin >> a;
		int b = 1;
		while(b < a){
			b = 2 * b + 1;
		}
		if(a < b){
			cout << b << '\n';
		} else {
			cout << d2cistoohard[__builtin_popcount(b)] << '\n';
		}
	}
}