#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50005;

int n, x, start, val[MAXN], nxt[MAXN], id[MAXN];

int main(){
	srand(time(NULL));
	int i, best;
	cin >> n >> start >> x;
	cout << "? " << start << endl;
	cin >> val[start] >> nxt[start];
	if(val[start] >= x){
		cout << "! " << val[start] << endl;
		return 0;
	}
	for(i = 1; i < n; ++ i) id[i] = i;
	best = start, id[start] = n;
	random_shuffle(id + 1, id + n);
	for(i = 1; i < 1000 && i < n; ++ i){
		cout << "? " << id[i] << endl;
		cin >> val[id[i]] >> nxt[id[i]];
		if(val[id[i]] > val[best] && val[id[i]] < x)
			best = id[i];
	}
	while(nxt[best] != -1){
		best = nxt[best];
		cout << "? " << best << endl;
		cin >> val[best] >> nxt[best];
		if(val[best] >= x){
			cout << "! " << val[best] << endl;
			return 0;
		}
	} cout << "! " << -1 << endl;
	return 0;
}