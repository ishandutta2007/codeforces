#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = -a[i];
	}
	vector<int> pinc(n, 0), pdec(n, 0), sinc(n, 0), sdec(n, 0);
	vector<int> pbest(n, 0), sbest(n, 0);
	for(int i = 1; i < n; i++){
		pinc[i] = pinc[i-1]+1;
		pdec[i] = pdec[i-1]+1;
		if(a[i-1] < a[i]){
			pdec[i] = 0;
		} else {
			pinc[i] = 0;
		}
		pbest[i] = max(pbest[i-1], max(pinc[i], pdec[i]));
	}
	for(int i = n-2; i >= 0; i--){
		sinc[i] = sinc[i+1]+1;
		sdec[i] = sdec[i+1]+1;
		if(a[i] < a[i+1]){
			sdec[i] = 0;
		} else {
			sinc[i] = 0;
		}
		sbest[i] = max(sbest[i+1], max(sinc[i], sdec[i]));
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a = i - pdec[i];
		int b = i + sinc[i];
		assert(pinc[b] >= sinc[i]);
		assert(sdec[a] >= pdec[i]);
		if(abs(sinc[i] - pdec[i]) > 0) continue;
		if(pdec[i] == 0 || sinc[i] == 0) continue;
		int v = -1;
		if(a > 0) v = max(v, pbest[a-1]);
		if(b+1 < n) v = max(v, sbest[b+1]);
		if(v >= max(pdec[i], sinc[i])) continue;
		if(pinc[a] >= pdec[i] || (pdec[i] & 1)){
			continue;
		}
		if(sdec[b] >= sinc[i] || (sinc[i] & 1)){
			continue;
		}
		ans++;
	}
	cout << ans << '\n';
}