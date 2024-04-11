#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c = 3000000007;
int main(){
	LL n;
	cin >> n;
	multiset<LL> s1;
	multiset<LL> s2;
	multiset<LL> s3;
	for(LL i = 0; i < n; i++){
		LL a;
		LL b;
		cin >> a >> b;
		s1.insert(a);
		s2.insert(b);
		s3.insert(a*c+b);
	}
	LL ans = 0;
	while(!s1.empty()){
		LL r = *s1.begin();
		LL z = 0;
		while(*s1.begin() == r){
			z++;
			s1.erase(s1.begin());
		}
		ans += z*(z-1)/2;
	}
	while(!s2.empty()){
		LL r = *s2.begin();
		LL z = 0;
		while(*s2.begin() == r){
			z++;
			s2.erase(s2.begin());
		}
		ans += z*(z-1)/2;
	}
	while(!s3.empty()){
		LL r = *s3.begin();
		LL z = 0;
		while(*s3.begin() == r){
			z++;
			s3.erase(s3.begin());
		}
		ans -= z*(z-1)/2;
	}
	cout << ans << endl;
}