#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	int _,A,B,C,D,n;
	for(scanf("%d",&_); _--;){
		scanf("%d",&n);
		mp.clear();
		for(int i=0; i<n; i++){
			scanf("%d%d%d%d",&A,&B,&C,&D);
			C -= A;
			D -= B;
			A = gcd(labs(C),labs(D));
			mp[make_pair(C/A,D/A)]++;
		}
		long long int res = 0;
		for(auto P : mp){
			auto P2 = make_pair(-P.first.first, -P.first.second);
			if(mp.count(P2))
				res += (long long int)P.second * mp[P2];
		}
		cout << res / 2<< endl;
	}
	return 0;
}