#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <set>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;

llint H = 9973, H2 = 1145143;
llint mod, mod2;
llint beki[1000005], beki2[1000005];
P hashA[1000005], hashS[1000005];

llint getrand(){
	return rand() + (llint)RAND_MAX * rand() + 
	(llint)RAND_MAX*RAND_MAX * rand() + (llint)RAND_MAX*RAND_MAX*RAND_MAX * rand();
}

void makeHash(string &s, P hash[], llint l, llint r)
{
	if(l == 0){
		hash[0] = make_pair(s[0], s[0]);
		l++;
	}
	for(int i = l; i <= r; i++){
		hash[i].first = (hash[i-1].first*H%mod+s[i]) % mod;
		hash[i].second = (hash[i-1].second*H2%mod2+s[i]) % mod2;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(time(NULL));
	while(1){
		mod = getrand() % 1000000000 + 100000000;
		mod2 = getrand() % 1000000000 + 100000000;
		if(mod % H && mod2 % H2) break;
	}
	
	beki[0] = beki2[0] = 1;
	for(int i = 1; i < 1000005; i++){
		beki[i] = (beki[i-1] * H) % mod;
		beki2[i] = (beki2[i-1] * H2) % mod2;
	}
	
	cin >> n;
	string s, ans;
	cin >> ans;
	makeHash(ans, hashA, 0, ans.size()-1);
	
	for(int i = 1; i < n; i++){
		cin >> s;
		makeHash(s, hashS, 0, s.size()-1);
		llint len = min(ans.size(), s.size());
	
		P h = make_pair(0, 0); int mx = 0;
		for(int j = 0; j < len; j++){
			h.first += ans[ans.size()-1-j] * beki[j] % mod, h.first %= mod;
			h.second += ans[ans.size()-1-j] * beki2[j] % mod2, h.second %= mod2;
			if(h == hashS[j]) mx = max(mx, j+1);
			//cout << s[j] << " " << h.first << " " << hashS[0].first << endl;
		}
		ans += s.substr(mx);
		makeHash(ans, hashA, ans.size()-(s.size()-mx), ans.size()-1);
	}
	cout << ans << endl;
	
	return 0;
}