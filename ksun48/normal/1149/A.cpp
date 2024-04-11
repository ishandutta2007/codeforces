#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int allsame = 1;
	vector<int> freq(3, 0);
	for(int i = 0; i + 1 < n; i++){
		if(a[i] != a[i+1]) allsame = 0;
	}
	for(int i = 0; i < n; i++) freq[a[i]]++;
	if(allsame){
		for(int i = 0; i < n; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << 2 << ' ' << 1;
		for(int i = 0; i < freq[2] - 1; i++){
			cout << ' ' << 2;
		}
		for(int i = 0; i < freq[1] - 1; i++){
			cout << ' ' << 1;
		}
		cout << '\n';
	}
}