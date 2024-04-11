#include <bits/stdc++.h>
using namespace std;

int b3(int x){
	int r = 1;
	int ans = 0;
	while(x > 0){
		ans += r * (x % 2);
		x /= 2;
		r *= 3;
	}
	return ans;
}

const int MAX_TRITS = 12;
const int MAXV = 531441;

int freq[MAXV];
int w, n, m;
int freqa[1 << MAX_TRITS];

int base3[1 << MAX_TRITS];

void init(){
	for(int i = 0; i < (1 << MAX_TRITS); i++){
		base3[i] = b3(i);
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0);

	init();
	cin >> w >> n >> m;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		freqa[a]++;
	}
	for(int i = 0; i < (1 << w); i++){
		for(int j = 0; j < (1 << w); j++){
			freq[base3[i] + base3[j]] += freqa[i] * freqa[j];
		}
	}
	for(int r = 0; r < m; r++){
		string s;
		cin >> s;
		vector<int> nums = {0};
		for(int i = 0; i < w; i++){
			vector<int> nums2;
			for(int a : nums){
				if(!(s[i] == 'a' || s[i] == 'o' || s[i] == 'x')){
					nums2.push_back(a * 3 + 0);
				}
				if(!(s[i] == 'O' || s[i] == 'X' || s[i] == 'a')){
					nums2.push_back(a * 3 + 1);
				}
				if(!(s[i] == 'A' || s[i] == 'O' || s[i] == 'x')){
					nums2.push_back(a * 3 + 2);
				}
			}
			nums = nums2;
		}
		int ans = 0;
		for(int a : nums){
			ans += freq[a];
		}
		cout << ans << '\n';
	}
}