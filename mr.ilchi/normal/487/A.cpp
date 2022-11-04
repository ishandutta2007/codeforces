#include <bits/stdc++.h>
using namespace std;

int main(){
	int hy,ay,dy; cin >> hy >> ay >> dy;
	int hm,am,dm; cin >> hm >> am >> dm;
	int ans = 1<<30;
	int hc,ac,dc; cin >> hc >> ac >> dc;
	for (int a=ay; a<=200; a++)
		for (int d=dy; d<=200; d++){
			int ly = max(0,am-d);
			int lm = max(0,a-dm);
			if (lm==0) continue;
			int minh = max(hy, 1 + (hm+lm-1)/(lm)*ly);
			ans = min(ans, (minh-hy)*hc + (a-ay)*ac + (d-dy)*dc);
		}
	cout << ans << endl;
	return 0;
}