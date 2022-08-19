#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char dig(int a){
	if(a <= 9){
		return (char)(a + '0');
	}
	return (char)(a - 10 + 'a');
}
int main(){
	string r;
	cin >> r;
	LL n = r.size();
	LL num[n];
	for(int i = 0; i < n; i++){
		if(r[i] >= '0' && r[i] <= '9'){
			num[i] = r[i] - '0';
		} else {
			num[i] = r[i] - 'a' + 10;
		}
	}
	LL ans = 1e17;
	for(int c = 0; c < (1<<n); c++){
		int ok[n];
		for(int i = 0; i < n; i++){
			ok[i] = 0;
			if(c & (1 << i)) ok[i] = 1;
		}
		if(ok[0]) continue;
		int newnum[n];
		for(int i = 0; i < n; i++){
			newnum[i] = num[i];
		}
		for(int i = 1; i < n; i++){
			if(ok[i]){
				newnum[i] -= 16;
				newnum[i-1] += 1;
			}
		}
		LL numsum = 0;
		for(int i = 0; i < n; i++){
			numsum += newnum[i];
		}
		if(numsum != 0) continue;
		int bad = 0;
		for(int i = 0; i < n; i++){
			if(newnum[i] >= 16 || newnum[i] <= -16){
				bad = 1;
			}
		}
		if(bad) continue;
		reverse(newnum, newnum + n);
		/*for(int i = 0; i < n; i++){
			cout << newnum[i] << " ";
		}
		cout << endl;*/

		LL b[(1<<n)]; // best mask for
		LL sum[(1<<n)];
		for(int i = 0; i < (1<<n); i++){
			b[i] = 1e17;
			sum[i] = 0;
		}
		for(int i = 0; i < (1<<n); i++){
			if(i == 0){
				b[i] = 0;
				continue;
			}
			for(int j = 0; j < n; j++){
				int c = i ^ (1<<j);
				if(c > i) continue;
				sum[i] = newnum[j] + sum[c];
				if(sum[c] < 0 || sum[c] >= 16) continue;
				b[i] = min(b[i], b[c] + (sum[c] << (4LL*j)) );
			}
		}
		/*if(b[(1<<n)-1] != 1e17){
			cout << b[(1<<n)-1] << endl;
		}*/
		ans = min(ans, b[(1<<n)-1]);
	}
	if(ans == 1e17){
		cout << "NO" << endl;
	} else {
		string f;

		for(int i = 0; i < n; i++){
			f += dig(ans % 16);
			ans /= 16;
		}
		reverse(f.begin(), f.end());
		cout << f << endl;
	}
}