#include <bits/stdc++.h>
using namespace std;

int n;
int fen[1<<18];

void add (int x, int y){ 
	while (x <= n){ 
		fen[x]+= y; x+= x & (-x); 
	}
}

int get (int x){
	int ret = 0;
	while (x){
		ret+= fen[x];
		x-= x & (-x);
	}
	return ret;
}

vector <int> go (){
	vector <int> res(n);
	memset(fen, 0, sizeof fen);
	for (int i=0; i<n; i++){
		int x; cin >> x;
		res[n-i-1] = x - get(x);
		add(x+1, 1);
	}
	return res;
}

int main(){
	cin >> n;
	vector <int> p = go();
	vector <int> q = go();
	vector <int> t(n);
	for (int i=0; i<n; i++){
		t[i]+= p[i]+q[i];
		if (i != n-1)
			t[i+1]+= t[i]/(i+1);
		t[i]%= i+1;
	}
	memset(fen, 0, sizeof fen);
	for (int i=n-1; i>=0; i--){
		int lo = 1, hi = n, ans = -1;
		while (lo<=hi){
			int mid = (lo + hi) / 2;
			int temp = mid - get(mid) - 1;
			if (temp >= t[i]){
				hi = mid-1;
				ans= mid;
			}else
				lo = mid+1;
		}
		add(ans,1);
		cout << ans-1 << ' ';
	}
	cout << endl;
	return 0;
}