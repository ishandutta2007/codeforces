#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	vector<LL> a;
	LL q;
	scanf("%I64d", &q);
	for(LL i = 2; i < 400000; i++){
		a.push_back(i*i*i);
	}
	LL s = 0;
	LL e = 100000000000000000LL; // works
	while(s+1LL < e){
		LL r = 0;
		LL m = (s+e)/2LL;
		for(int i = 0; i < a.size(); i++){
			r += (LL)m/a[i];
		}
		if(r < q){
			s = m;
		} else {
			e = m;
		}
	}
	LL r = 0;
	for(int i = 0; i < a.size(); i++){
		r += e/a[i];
	}
	if(r == q){
		cout << e << endl;
	} else {
		cout << -1 << endl;
	}

}