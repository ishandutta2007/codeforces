#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	vector<vector<ll> > boxes(k);
	for(int i = 0; i < k; i++){
		int n;
		cin >> n;
		boxes[i].resize(n);
		for(int j = 0; j < n; j++) cin >> boxes[i][j];
		sort(boxes[i].begin(), boxes[i].end());
	}
	ll tsum = 0;
	for(int i = 0; i < k; i++){
		for(ll a : boxes[i]) tsum += a;
	}
	if(tsum % k != 0){
		cout << "No" << '\n';
		return 0;
	}
	ll need = tsum / k;

	vector<ll> diff(k);
	for(int i = 0; i < k; i++){
		ll sum = 0;
		for(ll a : boxes[i]) sum += a;
		diff[i] = sum - need;
	}

	vector<int> works(1 << k, -1); // put index here
	works[0] = 0;
	// start with largest one, only use stuff left
	vector<ll> dsums(1 << k, 0);
	for(int i = 0; i < (1 << k); i++){
		for(int a = 0; a < k; a++){
			if((i >> a) & 1) dsums[i] += diff[a];
		}	
	}
	for(int l = 0; l < k; l++){
		for(int index = 0; index < (int)boxes[l].size(); index++){
			vector<bool> ok(1 << l, false);
			ll start = boxes[l][index];
			ok[0] = true;
			for(int i = 0; i < (1 << l); i++){
				if(ok[i]){
					if(dsums[i] + diff[l] == 0){
						works[i ^ (1 << l)] = index;
					}
					for(int j = 0; j < l; j++){
						if(((i >> j) & 1)) continue;
						if(binary_search(boxes[j].begin(), boxes[j].end(), start - dsums[i ^ (1 << l)]) ){
							ok[i ^ (1 << j)] = true;
						}
					}
				}
			}
		}
	}

	vector<bool> zz(1 << k, false);
	zz[0] = true;
	for(int i = 1; i < (1 << k); i++){
		int b = i;
		while(b > 0){
			if(works[b] >= 0 && zz[i ^ b]){
				zz[i] = true;
			}
			b = (b-1) & i;
		}
	}
	if(!zz.back()){
		cout << "No" << '\n';
		return 0;
	}
	vector<ll> what(k, -1);
	vector<ll> where(k, -1);
	int cur = (1 << k) - 1;
	while(cur > 0){
		assert(zz[cur]);
		int b = cur;
		int found = -1;
		while(b > 0){
			if(works[b] >= 0 && zz[cur ^ b]){
				found = b;
			}
			b = (b - 1) & cur;
		}
		assert(found > 0);
		cur = cur ^ found;
		int index = works[found];
		int l = k-1;
		while(((found >> l) & 1) == 0) l--;

		vector<bool> ok(1 << l, false);
		vector<int> backtrack(1 << l, -1);
		ll start = boxes[l][index];
		ok[0] = true;
		for(int i = 0; i < (1 << l); i++){
			if(ok[i]){
				for(int j = 0; j < l; j++){
					if(((i >> j) & 1)) continue;
					if(binary_search(boxes[j].begin(), boxes[j].end(), start - dsums[i ^ (1 << l)]) ){
						ok[i ^ (1 << j)] = true;
						backtrack[i ^ (1 << j)] = j;
					}
				}
			}
		}
		found ^= (1 << l);
		assert(ok[found]);
		what[l] = start;
		vector<int> idxs = {l};
		while(found > 0){
			int j = backtrack[found];
			assert(found & (1 << j));
			assert(j >= 0);
			found ^= (1 << j);
			what[j] = start - dsums[found ^ (1 << l)];
			idxs.push_back(j);
			assert(ok[found]);
		}
		for(int i = 0; i < (int)idxs.size(); i++){
			where[idxs[i]] = idxs[(i+1) % idxs.size()];
		}
	}

	cout << "Yes" << '\n';
	for(int i = 0; i < k; i++){
		cout << what[i] << ' ' << where[i] + 1 << '\n';
	}
}