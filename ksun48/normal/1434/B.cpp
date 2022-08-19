#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	n *= 2;
	vector<char> f(n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++){
		cin >> f[i];
		if(f[i] == '-') cin >> a[i];
	}
	vector<int> cur;
	for(int i = 0; i < n; i++){
		if(f[i] == '+'){
			cur.push_back(i);
		} else if(f[i] == '-'){
			if(cur.empty()){
				cout << "NO" << '\n';
				exit(0);
			}
			a[cur.back()] = a[i];
			cur.pop_back();
		}
	}
	set<int> z;
	for(int i = 0; i < n; i++){
		if(f[i] == '+'){
			z.insert(a[i]);
		} else if(f[i] == '-'){
			if(*z.begin() != a[i]){
				cout << "NO" << '\n';
				exit(0);
			} else {
				z.erase(z.begin());
			}
		}
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n; i++){
		if(f[i] == '+'){
			cout << a[i] << ' ';
		}
	}
	cout << '\n';
}