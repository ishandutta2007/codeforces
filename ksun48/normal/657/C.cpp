#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, b, c;
LL val[300000];
pair<LL,LL> zz[300000];
LL e = (1LL << 60); // answer
void solve(LL r){
	for(LL i = 0; i < n; i++){
		LL j = r-val[i];
		zz[i].first = (j/5);
		zz[i].second = j % 5;
		//cout << zz[i].first << " " << zz[i].second << endl;
	}
	//cout << endl;
	sort(zz, zz+n);
	multiset<LL> t;
	LL setsum = 0;
	LL qq = (1LL << 60);
	for(LL i = n-1; i >= 0; i--){
		t.insert(zz[i].first*b+zz[i].second*c);
		setsum += zz[i].first*b+zz[i].second*c;
		if(t.size() < k){
			continue;
		}
		if(t.size() > k){
			multiset<LL>::iterator fail = t.end();
			fail--;
			setsum -= *fail;
			t.erase(fail);
		}
		qq = min(qq,setsum - k*(zz[i].first*b));
	}
	//cout << qq << endl;
	e = min(e,qq);
}
int main(){
	cin >> n >> k >> b >> c;
	if(b > 5*c) b = 5*c;
	for(LL i = 0; i < n; i++){
		cin >> val[i];

	}
	solve(1000000000);
	solve(1000000001);
	solve(1000000002);
	solve(1000000003);
	solve(1000000004);
	cout << e << endl;
}