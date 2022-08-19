#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> pref(n+1, 0);
	vector<int> suff(n+1, 0);
	for(int i = 0; i < n; i++) pref[i+1] = pref[i] | a[i];
	for(int i = n-1; i >= 0; i--) suff[i] = suff[i+1] | a[i];
	int best = -1;
	int besti = -1;
	for(int i = 0; i < n; i++){
		int y = pref[i] | suff[i+1];
		int f = (a[i] | y) ^ y;
		if(f > best){
			best = f;
			besti = i;
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[(besti + i) % n] << ' ';
	}
	cout << '\n';
}