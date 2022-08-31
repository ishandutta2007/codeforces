#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	t1 %= 12; t2 %= 12; h %= 12;
	if(t1 > t2) swap(t1, t2);
	s /= 5;
	m /= 5;
	int ok1 = 1;
	int ok2 = 1;
	vector<int> f;
	f.push_back(h);
	f.push_back(m);
	f.push_back(s);
	for(int i = 0; i < 3; i++){
		if(t1 <= f[i] && f[i] < t2){
			ok1 = 0;
		} else {
			ok2 = 0;
		}
	}
	cout << ( (ok1 || ok2) ? "YES" : "NO") << endl;
}