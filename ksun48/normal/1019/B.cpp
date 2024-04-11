#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int ask(int x){
	x %= n;
	if(x < 0) x += n;
	cout << "? " << x + 1<< endl;
	int r;
	cin >> r;
	return r;
}
void ans(int x){
	x %= n;
	if(x < 0) x += n;
	cout << "! " << x + 1 << endl;	
}
int main(){
	cin >> n;
	if(n % 4 == 2){
		cout << "! " << -1 << endl;
		return 0;
	}
	int half = n/2;
	int s = 0;
	int e = s + half;
	int sdiff = ask(s) - ask(e);
	if(sdiff == 0){
		ans(s);
		return 0;
	}
	while(s + 1 < e){
		int m = (s + e)/2;
		if(s + 2 == e){
			ans(m);
			return 0;
		}
		int qdiff = ask(m) - ask(m + half);
		if(qdiff == 0){
			ans(m);
			return 0;
		}
		if((qdiff > 0) == (sdiff > 0)){
			sdiff = qdiff;
			s = m;
		} else {
			e = m;
		}
	}
}