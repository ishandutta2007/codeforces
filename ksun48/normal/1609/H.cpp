#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<ll> ipos(n);
	for(ll& x : ipos) cin >> x;
	vector<vector<int> > force(k, vector<int>(n));
	// turn bot
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			cin >> force[j][i];
		}
	}
	int Q;
	cin >> Q;
	vector<pair<int, ll> > queries(Q);
	vector<ll> answers(Q);
	for(auto& [a, t] : queries){
		cin >> a >> t;
		a--;
	}
	auto step = [&](vector<ll> pos, ll turn) -> vector<ll> {
		vector<int> f = force[turn % k];
		vector<int> fsum(n+1, 0);
		for(int i = 0; i < n; i++){
			fsum[i+1] = fsum[i] + f[i];
		}
		vector<pair<int,int> > join;
		auto combine = [&](pair<int,int> a, pair<int,int> b) -> bool {
			if(pos[a.second-1] + 1 != pos[b.first]) return false;
			if(fsum[a.second] - fsum[a.first] > 0) return true;
			if(fsum[b.second] - fsum[b.first] < 0) return true;
			return false;
		};
		for(int i = 0; i < n; i++){
			join.push_back({i, i+1});
			while(join.size() >= 2 && combine(join[join.size()-2], join[join.size()-1])){
				join[join.size()-2].second = join[join.size()-1].second;
				join.pop_back();
			}
		}
		vector<int> del(join.size(), 0);
		for(int i = 0; i < join.size(); i++){
			int nf = fsum[join[i].second] - fsum[join[i].first];
			if(nf > 0){
				del[i] = 1;
			} else if(nf < 0){
				del[i] = -1;
			} else {
				del[i] = 0;
			}
		}
		for(int i = 0; i + 1 < join.size(); i++){
			if(del[i] == 1 && del[i+1] == -1 && pos[join[i].second-1] + 2 == pos[join[i+1].first]){
				int nf = fsum[join[i+1].second] - fsum[join[i].first];
				if(nf <= 0){
					del[i] = 0;
				} else {
					del[i+1] = 0;
				}
			}
		}
		for(int i = 0; i < join.size(); i++){
			for(int x = join[i].first; x < join[i].second; x++){
				pos[x] += del[i];
			}
		}
		for(int i = 0; i + 1 < n; i++){
			assert(pos[i] < pos[i+1]);
		}
		return pos;
	};

	auto round = [&](vector<ll> pos) -> vector<ll> {
		for(int i = 0; i < k; i++){
			pos = step(pos, i);
		}
		return pos;
	};
	set<ll> has_query;
	for(auto [a, t] : queries){
		has_query.insert(t - (t % k));
	}
	ll T = 0;
	vector<ll> cpos = ipos;
	ll R = 2 * k + 1;
	while(!has_query.empty()){
		ll next_query = *has_query.begin();
		if(T == next_query){
			vector<vector<ll> > roundpos(k+1);
			roundpos[0] = cpos;
			for(int i = 0; i < k; i++){
				roundpos[i+1] = step(roundpos[i], i);
			}
			for(int q = 0; q < Q; q++){
				if(queries[q].second >= T && queries[q].second < T + k){
					answers[q] = roundpos[queries[q].second - T][queries[q].first];
				}
			}
			cpos = roundpos[k];
			T += k;
			has_query.erase(next_query);
			continue;
		} else {
			vector<ll> zpos = round(cpos);
			vector<ll> dels(n);
			for(int i = 0; i < n; i++){
				dels[i] = zpos[i] - cpos[i];
			}
			ll nrounds = (next_query - T) / k;
			for(int i = 0; i + 1 < n; i++){
				ll del_diff = dels[i] - dels[i+1];
				if(del_diff != 0 && (cpos[i+1] - cpos[i] < R)) nrounds = 0;
				if(del_diff <= 0) continue;
				nrounds = min(nrounds, (cpos[i+1] - cpos[i] - R) / del_diff);
			}
			if(nrounds <= 0) nrounds = 1;
			for(int i = 0; i < n; i++){
				cpos[i] += dels[i] * nrounds;
			}
			T += nrounds * k;
		}
	}
	for(ll a : answers){
		cout << a << '\n';
	}
}