#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	vector<int> psum;
	for(char a : s){
		psum.push_back(cnt);
		if(a == '('){
			cnt++;
		} else {
			cnt--;
		}
	}
	if(cnt != 0){
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		return 0;
	}
	int curmin = 0;
	for(int x : psum) curmin = min(curmin, x);
	for(int& x : psum) x -= curmin;

	int curcnt = 0;
	for(int x : psum) if(x == 0) curcnt++;

	int best = curcnt;
	pair<int,int> which_swap = {0, 0};

	// new min = 0
	{

		int first_two = -1;
		int equals_count = 0;
		for(int i = 0; i < 2*n; i++){
			int v = psum[i % n];
			if(v <= 1){
				first_two = -1;
				equals_count = 0;
			} else if(v == 2){
				equals_count ++;
				if(psum[(i + n-1) % n] == 1){
					// up
					if(first_two == -1){
						first_two = i;
					}
				}
				if(first_two == -1){
					equals_count = 0;
				}
				if(psum[(i + 1) % n] == 1){
					if(first_two != -1){
						pair<int,int> swap_cand = {(first_two + n-1) % n, (i + n) % n};
						assert(s[swap_cand.first] == '(' && s[swap_cand.second] == ')');
						if(equals_count + curcnt > best){
							best = equals_count + curcnt;
							which_swap = swap_cand;
						}
					}
				}
			}
		}
	}
	// new min = -1
	{

		int first_two = -1;
		int equals_count = 0;
		for(int i = 0; i < 2*n; i++){
			int v = psum[i % n];
			if(v <= 0){
				first_two = -1;
				equals_count = 0;
			} else if(v == 1){
				equals_count ++;
				if(psum[(i + n-1) % n] == 0){
					// up
					if(first_two == -1){
						first_two = i;
					}
				}
				if(first_two == -1){
					equals_count = 0;
				}
				if(psum[(i + 1) % n] == 0){
					if(first_two != -1){
						pair<int,int> swap_cand = {(first_two + n-1) % n, (i + n) % n};
						assert(s[swap_cand.first] == '(' && s[swap_cand.second] == ')');
						if(equals_count > best){
							best = equals_count;
							which_swap = swap_cand;
						}
					}
				}
			}
		}
	}

	cout << best << '\n';
	cout << which_swap.first + 1 << ' ' << which_swap.second + 1 << '\n';
}