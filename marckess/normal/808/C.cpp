#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>

using namespace std;

int main(){
	int n, w, b, x; cin >> n >> w;
	vii a(n), axu;
	vi res(n);

	for(int i = 0; i < n; i++){
		cin >> x;
		a[i] = {x, i};
		b = x / 2;
		if ( b * 2 < x )
			b++;
		res[i] += b;
		w -= b;
	}

	if (w < 0){
		cout << -1;
		return 0;
	}

	sort(a.begin(), a.end(), greater<ii>());

	for(int i = 0; i < n; i++){
		x = min(w, a[i].first - res[a[i].second]);
		res[a[i].second] += x;
		w -= x;
	}

	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	return 0;
}