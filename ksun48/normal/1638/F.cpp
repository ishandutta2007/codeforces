#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> a(n+2, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	set<int> idx_seen;
	idx_seen.insert(0);
	idx_seen.insert(n+1);
	vector<int> aord(n);
	for(int i = 1; i <= n; i++) aord[i-1] = i;
	sort(aord.begin(), aord.end(), [&](int x, int y) { return a[x] < a[y]; });

	ll best = 0;
	vector<ll> lbest(n+2, 0);
	vector<ll> rbest(n+2, 0);

	vector<pair<ll, ll> > lrect(n+2), rrect(n+2);
	for(int idx : aord){
		int en = *(idx_seen.lower_bound(idx));
		int st = *prev(idx_seen.lower_bound(idx));
		idx_seen.insert(idx);
		// st+1, en-1

		ll A = a[idx];
		ll mid_len = (en - st - 1);
		lbest[en-1] = max(lbest[en-1], A * mid_len);
		rbest[st+1] = max(rbest[st+1], A * mid_len);
		{
			// x + y < A
			vector<pair<ll, ll> > rscore, lscore;
			{
				ll cmin = A;
				for(int v = en; v <= n+1; v++){
					cmin = min(cmin, a[v]);
					ll cscore = (mid_len + (v - en + 1)) * cmin;
					while(!rscore.empty() && cscore >= rscore.back().second){
						rscore.pop_back();
					}
					rscore.push_back({cmin, cscore});
				}
			}
			{
				ll cmin = A;
				for(int v = st; v >= 0; v--){
					cmin = min(cmin, a[v]);
					ll cscore = (mid_len + (st - v + 1)) * cmin;
					while(!lscore.empty() && cscore >= lscore.back().second){
						lscore.pop_back();
					}
					lscore.push_back({cmin, cscore});
				}
			}
			int ridx = 0;
			ll tarea = 0;
			for(int lidx = (int)lscore.size() - 1; lidx >= 0; lidx--){
				while(rscore[ridx].first + lscore[lidx].first > A) ridx++;
				tarea = max(tarea, lscore[lidx].second + rscore[ridx].second);
			}
			best = max(best, tarea);
		}
		// x + y = A
		{
			ll cmin = A;
			for(int v = st; v >= 0; v--){
				cmin = min(cmin, a[v]);
				lrect[v] = {cmin, cmin * (st - v + 1)};
			}
			int ridx = en;
			for(int l = 0; l <= st; l++){
				while(a[ridx] > A - lrect[l].first) ridx++;
				best = max(best, A * mid_len + lrect[l].second + (A - lrect[l].first) * (ridx - en));
			}
		}
		{
			ll cmin = A;
			for(int v = en; v <= n+1; v++){
				cmin = min(cmin, a[v]);
				rrect[v] = {cmin, cmin * (v - en + 1)};
			}
			int lidx = st;
			for(int r = n+1; r >= en; r--){
				while(a[lidx] > A - rrect[r].first) lidx--;
				best = max(best, A * mid_len + rrect[r].second + (A - rrect[r].first) * (st - lidx));
			}
		}
		// x = y < A
		{
			int l = st;
			int r = en;
			ll cmin = min(a[st], a[en]);
			while(true){
				if(cmin == 0) break;
				while(a[l] >= cmin) l--;
				while(a[r] >= cmin) r++;
				best = max(best, (r-l-1) * cmin + (A - cmin) * mid_len);
				if(a[l] < a[r]){
					cmin = min(cmin, a[r]);
					r++;
				} else {
					cmin = min(cmin, a[l]);
					l--;
				}
			}
		}
	}
	for(int i = 1; i <= n+1; i++){
		best = max(best, lbest[i-1] + rbest[i]);
		lbest[i] = max(lbest[i], lbest[i-1]);
	}
	cout << best << '\n';
}