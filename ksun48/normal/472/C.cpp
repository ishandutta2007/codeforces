#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int le(string a, string b){
	int n=0;
	while(1){
		if(a.size() < n) return 1;
		if(b.size() < n) return 0;
		if(a[n] < b[n]) return 1;
		if(a[n] > b[n]) return 0;
		n++;
	}
}
int main(){
	int n;
	cin >> n;
	string a[n];
	string b[n];
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	int stuff[n];
	for(int i = 0; i < n; i++){
		cin >> stuff[i];
		stuff[i]--;
	}
	string c;
	for(int i = 0; i < n; i++){
		if(le(a[stuff[i]], b[stuff[i]])){
			//cout << 1 << endl;
		} else {
			//cout << 0 << endl;
		}
	}
	if(le(a[stuff[0]], b[stuff[0]])){
		c = a[stuff[0]];
	} else {
		c = b[stuff[0]];
	}
	for(int i = 1; i < n; i++){
		if( le(c,a[stuff[i]]) && le(c,b[stuff[i]]) ){
			if(le(a[stuff[i]], b[stuff[i]])){
				c = a[stuff[i]];
			} else {
				c = b[stuff[i]];
			}
		} else if(le(c,a[stuff[i]]) ){
			c = a[stuff[i]];
		} else if(le(c,b[stuff[i]]) ){
			c = b[stuff[i]];
		} else {
			cout << "NO" << endl;
			exit(0);
		}

	}
	cout << "YES" << endl;
	exit(0);
}