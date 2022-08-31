#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> need;
	set<int> found;
	for(int i = 0; i < n; i++){
		need.insert(i);
		found.insert(i+1);
	}
	while(need.size() >= 2){
		int x = *need.begin();
		need.erase(x);
		int y = *need.begin();
		need.erase(y);
		cout << "? " << x+1 << ' ' << y+1 << '\n';
		cout << "? " << y+1 << ' ' << x+1 << '\n';
		cout << flush;
		int a1, a2;
		cin >> a1 >> a2;
		if(a1 < a2){
			a[y] = a2;
			need.insert(x);
			found.erase(a2);
		} else {
			a[x] = a1;
			need.insert(y);
			found.erase(a1);
		}
	}
	a[*need.begin()] = *found.begin();
	cout << "!";
	for(int r : a) cout << ' ' << r;
	cout << '\n';
}