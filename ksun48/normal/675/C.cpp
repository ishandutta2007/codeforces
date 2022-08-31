#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	LL a = 0;
	multiset<LL> r;
	for(int i = 0; i < n; i++){
		LL c;
		scanf("%I64d", &c);
		a += c;
		r.insert(a);
	}
	int ans = 0;
	while(!r.empty()){
		ans = max(ans,int(r.count(*r.begin())));
		LL e = *r.begin();
		while(r.find(e) != r.end()){
			r.erase(r.begin());
		}
	}
	cout << n- ans << endl;
}