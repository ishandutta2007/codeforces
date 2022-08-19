#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int sx, sy;
	cin >> sx >> sy;
	int d0 = 0, d1 = 0, d2 = 0, d3 = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a < sx) d0++;
		if(a > sx) d1++;
		if(b < sy) d2++;
		if(b > sy) d3++;
	}
	int d = max(max(d0, d1), max(d2, d3));
	cout << d << '\n';
	if(d == d0){
		sx--;
	} else if(d == d1){
		sx++;
	} else if(d == d2){
		sy--;
	} else if(d == d3){
		sy++;
	} else assert(false);
	cout << sx << ' ' << sy << '\n';
}