#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const ll Z = 1e18;
	const ll B = 1e7;
	int n, m;
	cin >> n >> m;
	multiset<ll> best3;
	vector<set<pair<ll, int> > > weights(n);
	for(int i = 0; i < n; i++){
		weights[i].insert({Z, -1});
		weights[i].insert({Z, -2});
		weights[i].insert({Z, -3});
		best3.insert(Z + Z + Z);
	}
	auto get_best = [&](int u) -> ll {
		auto f = weights[u].begin();
		ll sum = (*f).first;
		f = next(f);
		sum += (*f).first;
		f = next(f);
		sum += (*f).first;
		return sum;
	};

	multiset<pair<ll, pair<int,int> > > all_edges_weights;
	all_edges_weights.insert({Z, {-1, -1}});

	auto is_front = [&](int u, int v) -> bool{
		auto f = weights[u].begin();
		if((*f).second == v) return true;
		f = next(f);
		if((*f).second == v) return true;
		f = next(f);
		if((*f).second == v) return true;
		return false;
	};

	vector<set<pair<ll, int> > > index(n);
	auto kill = [&](int u){
		while(!index[u].empty()){
			auto [w, v] = *index[u].begin();
			all_edges_weights.erase({w, {u, v}});
			all_edges_weights.erase({w, {v, u}});
			index[u].erase({w, v});
			index[v].erase({w, u});
		}
	};

	auto recalc = [&](int u, int v, ll w){
		if(u < 0 || v < 0) return;
		if(is_front(u, v) && is_front(v, u)){
			all_edges_weights.insert({w, {u, v}});
			all_edges_weights.insert({w, {v, u}});
			index[u].insert({w, v});
			index[v].insert({w, u});
		}
	};
	auto recalc_all = [&](int u){
		kill(u);
		auto f = weights[u].begin();
		recalc(u, (*f).second, (*f).first);
		f = next(f);
		recalc(u, (*f).second, (*f).first);
		f = next(f);
		recalc(u, (*f).second, (*f).first);
	};

	auto ins = [&](int u, int v, ll w){
		best3.erase(best3.find(get_best(u)));
		best3.erase(best3.find(get_best(v)));
		weights[u].insert({w, v});
		weights[v].insert({w, u});
		recalc_all(u);
		recalc_all(v);
		best3.insert(get_best(u));
		best3.insert(get_best(v));
	};
	auto del = [&](int u, int v, ll w){
		best3.erase(best3.find(get_best(u)));
		best3.erase(best3.find(get_best(v)));
		weights[u].erase({w, v});
		weights[v].erase({w, u});
		recalc_all(u);
		recalc_all(v);
		best3.insert(get_best(u));
		best3.insert(get_best(v));
	};
	map<pair<int,int>, ll> wgt;
	int idx = 0;
	for(int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		w = w * B + idx;
		ins(u, v, w);
		wgt[{u, v}] = wgt[{v, u}] = w;
		idx += 1;
	}
	int q;
	cin >> q;
	for(int _ = 0; _ <= q; _++){
		{
			ll ans = *best3.begin();
			auto [w, zz] = *all_edges_weights.begin();
			auto [u, v] = zz;
			kill(u);
			kill(v);
			ans = min(ans, w + (*all_edges_weights.begin()).first);
			recalc_all(u);
			recalc_all(v);
			vector<pair<ll, int> > uc, vc;
			{
				auto f = weights[u].begin();
				assert((*f).second == v);
				f = next(f);
				uc.push_back((*f));
				f = next(f);
				uc.push_back((*f));
			}
			{
				auto f = weights[v].begin();
				assert((*f).second == u);
				f = next(f);
				vc.push_back((*f));
				f = next(f);
				vc.push_back((*f));
			}
			for(auto [uw, ux] : uc){
				for(auto [vw, vx] : vc){
					if(ux != vx){
						ans = min(ans, uw + vw);
					}
				}
			}
			cout << (ans / B) << '\n';
		}
		if(_ == q) break;
		int type;
		cin >> type;
		int u, v;
		cin >> u >> v;
		u--; v--;
		ll w;
		if(type == 0){
			w = wgt[{u, v}];
			del(u, v, w);
		} else {
			cin >> w;
			w = w * B + idx;
			ins(u, v, w);
			wgt[{u, v}] = wgt[{v, u}] = w;
			idx += 1;
		}
	}
}