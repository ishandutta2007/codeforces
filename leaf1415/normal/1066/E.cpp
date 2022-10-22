#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define llint long long
#define mod 998244353

using namespace std;

struct BIT{
	int size;
	vector<int> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, int x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, m;
string a, b;
llint beki[200005];
BIT bit(200005);

int main(void)
{
	cin >> n >> m;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a = '#' + a;
	b = '#' + b;
	
	beki[1] = 1;
	for(int i = 2; i <= n; i++) beki[i] = beki[i-1] * 2 % mod;
	
	for(int i = 1; i <= m ; i++){
		if(b[i] == '1'){
			bit.add(1, 1);
			bit.add(i+1, -1);
		}
	}
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == '1'){
			ans += bit.query(i) * beki[i] % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}