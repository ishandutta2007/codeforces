#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef bitset<7100> B;

B stuff[110000];

B singles[7100];
B qq[7100];

int mu[7100];

int is_prime[7100];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string ans;

	int n, q;
	cin >> n >> q;
	for(int v = 1; v <= 7000; v++){
		mu[v] = 1;
		is_prime[v] = 1;
	}

	for(int p = 2; p <= 7000; p++){
		if(is_prime[p]){
			for(int q = p; q <= 7000; q += p){
				is_prime[q] = 0;
				mu[q] *= -1;
			}
			for(int q = p*p; q <= 7000; q += p*p){
				mu[q] = 0;
			}
		}
	}
	for(int v = 1; v <= 7000; v++){
		for(int w = v; w <= 7000; w += v){
			singles[w][v] = singles[w][v] ^ 1;
			if(mu[w/v] != 0){
				qq[v][w] = qq[v][w] ^ 1;
			}
		}
	}

	for(int i = 0; i < q; i++){
		int type;
		cin >> type;
		int x;
		cin >> x;
		if(type == 1 || type == 4){
			int v;
			cin >> v;
			if(type == 1){
				stuff[x] = singles[v];
			} else {
				B z = stuff[x] & qq[v];
				ans += ('0' + (z.count() % 2));
			}
		} else if(type == 2 || type == 3){
			int y, z;
			cin >> y >> z;
			B r;
			if(type == 2){
				r = stuff[y] ^ stuff[z];
			} else if(type == 3) {
				r = stuff[y] & stuff[z];
			}
			stuff[x] = r;
		}
	}
	cout << ans << '\n';
}