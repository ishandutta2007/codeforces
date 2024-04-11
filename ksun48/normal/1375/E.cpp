#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ord(n);
	for(int i = 0; i < n; i++){
		ord[i] = i;
		cin >> a[i];
	}
	sort(ord.begin(), ord.end(), [&](int r, int s){
		return tie(a[r], r) < tie(a[s], s);
	});
	for(int i = 0; i < n; i++) a[ord[i]] = i;
	vector<pair<int,int> > z;
	for(int i = 0; i < n; i++){
		vector<int> bad;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[i]){
				bad.push_back(j);
			}
		}
		sort(bad.begin(), bad.end(), [&](int r, int s){
			return a[r] > a[s];
		});
		for(int b : bad){
			z.push_back({i, b});
			swap(a[i], a[b]);
		}
		assert(a[i] == i);
	}
	cout << z.size() << '\n';
	for(pair<int,int> q : z){
		cout << q.first + 1 << ' ' << q.second + 1 << '\n';
	}
}