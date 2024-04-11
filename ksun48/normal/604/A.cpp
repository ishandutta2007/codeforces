#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int m[5], w[5];
	int hs, hu;
	for(int i = 0; i < 5; i++) cin >> m[i];
	for(int i = 0; i < 5; i++) cin >> w[i];
	cin >> hs >> hu;
	int score = 0;
	for(int i = 0; i < 5; i++){
		int x = i+1;
		score += max(150*x,500*x-2*m[i]*x-50*w[i]);
	}
	score += 100*hs - 50*hu;
	cout << score << endl;
}