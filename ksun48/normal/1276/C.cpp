#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	unordered_map<int,int> freq;
	vector<int> cnt(n+1, 0);
	for(int x : a){
		freq[x]++;
		cnt[freq[x]]++;
	}

	sort(a.begin(), a.end(), [&](int x, int y) -> bool{
		return tie(freq[x], x) > tie(freq[y], y);
	});
	int r = 0;
	int c = 0;
	int sum = 0;
	for(int f = 1; f * f <= n; f++){
		sum += cnt[f];
		if(sum >= f * f){
			int zr = f;
			int zc = sum / f;
			if(zr * zc > r * c){
				r = zr;
				c = zc;
			}
		}
	}
	assert(r <= c);
	freq = {};
	int cur = 0;
	vector<vector<int> > arr(r, vector<int>(c, 0));
	for(int i = 0; i < r; i++){
		for(int j = 0; ; j++){
			if(arr[(i+j) % r][j % c]) break;
			while(freq[a[cur]] >= r) cur++;
			freq[a[cur]]++;
			arr[(i+j) % r][j % c] = a[cur];
			cur++;
		}
	}
	assert(r && c);
	cout << r * c << '\n';
	cout << r << ' ' << c << '\n';
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}