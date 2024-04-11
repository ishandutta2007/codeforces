#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

int h, q;
ll L, R, ans;
vector <llll> negs;
ll cL, cR;
vector <llll> mnegs;

int main()
{
	scanf("%d %d", &h, &q); cL = 1ll << ll(h - 1); cR = (1ll << ll(h)) - 1;
	while (q--) {
		int lvl; ll L, R; int ans; scanf("%d %I64d %I64d %d", &lvl, &L, &R, &ans);
		R++;
		while (lvl < h) { L *= 2; R *= 2; lvl++; }
		R--;
		if (ans == 0) negs.push_back(llll(L, R));
		else { cL = max(cL, L); cR = min(cR, R); }
	}
	if (cL > cR) { printf("Game cheated!\n"); return 0; }
	sort(negs.begin(), negs.end());
	for (int i = 0; i < negs.size(); i++)
		if (mnegs.empty() || mnegs.back().second + 1 < negs[i].first)
			mnegs.push_back(negs[i]);
		else mnegs.back().second = max(mnegs.back().second, negs[i].second);
	ll got = 0;
	for (int i = 0; i < mnegs.size(); i++) {
		ll lef = max(mnegs[i].first, cL), rig = min(mnegs[i].second, cR);
		if (lef <= rig) got += rig - lef + 1;
	}
	if (got >= cR - cL + 1) printf("Game cheated!\n");
	else if (got + 1 == cR - cL + 1) {
		ll mn = cL;
		for (int i = 0; i < mnegs.size(); i++)
			if (mnegs[i].first <= mn && mn <= mnegs[i].second)
				mn = mnegs[i].second + 1;
		printf("%I64d\n", mn);
	} else printf("Data not sufficient!\n");
	return 0;
}