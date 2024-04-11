#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int ans = 0;
	int cur = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		cur++;
		if(a <= 3) cur = 0;
		if(cur == 3){
			cur = 0;
			ans++;
		}
	}
	cout << ans << endl;
}