#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 2; i < 63; i++){
		for(int j = 0; j < i-1; j++){
			LL r = (1LL << i) - 1 - (1LL << j);
			if(a <= r && r <= b){
				ans++;
			}
		}
	}
	cout << ans << endl;
}