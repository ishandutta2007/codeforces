#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<pair<int,LL>, int> ans;

int solve(int a, LL mask){
	if(ans.find(make_pair(a,mask)) != ans.end() ) return ans[make_pair(a,mask)];
	if(a == 0){
		ans[make_pair(a,mask)] = 0;
		return 0;
	}
	int found[50];
	for(int i = 0; i < 50; i++) found[i] = 0;
	for(int b = 1; b <= a; b++){
		if((mask & (1LL<<b)) == 0){
			int p = solve(a-b, mask + (1<<b));
			found[p] = 1;
		}
	}
	for(int i = 0; i < 50; i++){
		if(!found[i]){
			ans[make_pair(a,mask)] = i;
			return i;
		}
	}
}
int main() {
	ans[make_pair(0,0)] = 0;
	//LL derp[61];
	/*for(int i = 0; i <= 60; i++){
		derp[i] = solve(i, 0);
	}*/
	LL derp[62] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
	int n;
	scanf("%d", &n);
	int aa = 0;
	for(int i = 0; i < n; i++){
		int b;
		scanf("%d", &b);
		aa ^= derp[b];
	}
	if(aa){
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}