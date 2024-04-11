#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int,int> done;
pair<int,int> query(int a){
	cout << "? " << a << endl;
	fflush(stdout);
	int b, c;
	cin >> b >> c;
	return make_pair(b,c);
}
int main(){
	int n, start, x;
	cin >> n >> start >> x;
	srand(7756678);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator (seed);
	pair<int,int> q = query(start);
	for(int j = 0; j < min(1500,n); j++){
		int z = (generator() % n) + 1;
		if(done[z]) continue;
		done[z] = 1;
		pair<int,int> q2 = query(z);
		if(q2.first >= x) continue;
		if(q2.first > q.first) q = q2;
	}
	while(1){
		if(q.second == -1) break;
		if(q.first >= x) break;
		q = query(q.second);
	}
	cout << "! ";
	if(q.first < x){
		cout << -1 << endl;
	} else {
		cout << q.first << endl;
	}
	fflush(stdout);
	return 0;
}