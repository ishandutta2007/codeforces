#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a,a+n);
	int r1 = -1000;
	int r2 = -1000;
	int ok = 1;
	for(int i = 0; i < n; i++){
		if(r1 > r2) swap(r1, r2);
		if(a[i].first > r2){
			r2 = a[i].second;
		} else if(a[i].first > r1){
			r1 = a[i].second;
		} else {
			ok = 0;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}