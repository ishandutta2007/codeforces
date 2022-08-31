#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	int ans[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		ans[i] = 0;
	}
	for(int i = 0; i < n; i++){
		int count[n];
		for(int j = 0; j < n; j++){
			count[j] = 0;
		}
		int ms = 0;
		int mc = 0;
		for(int j = i; j < n; j++){
			count[a[j]]++;
			if(count[a[j]] > ms || (count[a[j]] == ms && a[j] < mc)){
				mc = a[j];
				ms = count[a[j]];
			}
			ans[mc]++;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}