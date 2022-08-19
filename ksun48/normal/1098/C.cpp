#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, s;

vector<LL> used_saved;

LL can_do(LL max_branch, bool save = false){
	LL curn = n;
	LL tsum = 0;
	LL last_used = 0;
	if(save) used_saved.resize(1, 0);
	for(LL i = 1; ; i++){
		if(curn == 0) break;
		if(i == 1){
			last_used = 1;
		} else {
			last_used *= max_branch;
		}
		last_used = min(last_used, curn);
		tsum += i * last_used;
		curn -= last_used;
		if(save) used_saved.push_back(last_used);
		if(tsum > s) return 0;
	}
	if(tsum > s) return 0;
	return 1;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	LL b1 = n*(n+1)/2;
	if(s > b1 || s < 2*(n-1) + 1){
		cout << "No" << '\n';
		return 0;
	}

	LL no = 0;
	LL yes = n;
	while(no + 1 < yes){
		LL m = (no + yes) / 2;
		if(can_do(m)){
			yes = m;
		} else {
			no = m;
		}
	}
	LL bf = yes;
	can_do(bf, true);
	LL sum = 0;
	for(int i = 1; i < used_saved.size(); i++){
		sum += i * used_saved[i];
	}
	assert(sum <= s);
	assert(used_saved[1] == 1);
	LL v = (int)used_saved.size() - 1;
	while(sum < s){
		while(v >= 0 && used_saved[v] == 1) v--;
		assert(v >= 2);
		LL inc = (int)used_saved.size() - v;
		if(sum + inc <= s){
			used_saved.push_back(1);
			used_saved[v]--;
			sum += inc;
			continue;
		}
		assert(bf != 1);
		inc = s - sum;
		LL loc = v + inc;
		used_saved[v]--;
		used_saved[loc]++;
		sum += inc;
	}
	for(int i = 1; i + 1 < used_saved.size(); i++){
		assert(used_saved[i+1] <= used_saved[i] * bf);
		assert(used_saved[i] >= 1);
		assert(used_saved[i+1] >= 1);
	}
	vector<int> csum(used_saved.size(), 0);
	for(int i = 1; i < used_saved.size(); i++){
		csum[i] = csum[i-1] + used_saved[i];
	}
	cout << "Yes" << '\n';
	for(int i = 2; i < used_saved.size(); i++){
		for(int j = 0; j < used_saved[i]; j++){
			cout << 1 + csum[i-2] + (j / bf) << " ";
		}
	}
	cout << '\n';
}