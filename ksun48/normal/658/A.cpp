#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, c;
	cin >> n >> c;
	int p[n+1];
	for(int i = 1; i <= n; i++) cin >> p[i];
	int t[n+1];
	for(int i = 1; i <= n; i++) cin >> t[i];
	int l = 0;
	int r = 0;
	int tt = 0;
	for(int i = 1; i <= n; i++){
		tt += t[i];
		l += max(0,p[i]-c*tt);
	}
	tt = 0;
	for(int i = n; i >= 1; i--){
		tt += t[i];
		r += max(0,p[i]-c*tt);
	}
	if(l > r){
		cout << "Limak" << endl;
	} else if(l < r){
		cout << "Radewoosh" << endl;
	} else {
		cout << "Tie" << endl;
	}
}