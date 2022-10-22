#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n;
llint cnt[35];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 0; i < 35; i++) cnt[i] = 0;
		llint x, c;
		for(int i = 1; i <= n; i++){
			cin >> x;
			c = 0;
			for(;x;x/=2) c++;
			cnt[c-1]++;
		}
		for(int i = 0; i < 30; i++){
			cnt[i+1] += cnt[i]/2;
		}
		if(cnt[11]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}