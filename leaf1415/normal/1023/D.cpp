#include <iostream>
#include <set>

using namespace std;

int n, q;
int a[200005];
int A[200005];
set<int> s1, s2;

int main(void)
{
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) A[i] = a[i];
	
	bool ans = true;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) continue;
		if(s2.count(a[i])){
			ans = false;
			break;
		}
		auto pos = s1.upper_bound(a[i]);
		for(auto it = pos; it != s1.end(); it++) s2.insert(*it);
		s1.erase(pos, s1.end());
		s1.insert(a[i]);
	}
	
	if(!ans){
		cout << "NO" << endl;
		return 0;
	}
	
	bool zero = true;
	for(int i = 1; i <= n; i++){
		if(a[i]) zero = false;
	}
	if(zero){
		for(int i = 1; i <= n; i++) a[i] = q;
	}
	
	int pre = -1;
	for(int i = 1; i <= n; i++){
		if(a[i]) pre = a[i];
		else{
			if(pre != -1) a[i] = pre;
		}
	}
	pre = -1;
	for(int i = n; i >= 1; i--){
		if(a[i]) pre = a[i];
		else{
			if(pre != -1) a[i] = pre;
		}
	}
	
	bool mx = false;
	for(int i = 1; i <= n; i++){
		if(a[i] == q) mx = true;
	}
	
	for(int i = 1; i <= n; i++){
		if(!mx && A[i] == 0) a[i] = q, mx = true;
	}
	if(!mx){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}