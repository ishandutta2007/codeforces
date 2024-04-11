#include <iostream>
#include <cstdlib>
#include <vector>
#define llint long long

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
		for(int i = 1; i <= size; i++) bit[i] = 0;
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

llint n;
llint a[100005], b[100005];
llint inva[100005], invb[100005];
BIT bit(100005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++) inva[a[i]] = i;
	for(int i = 1; i <= n; i++) b[i] = inva[b[i]];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(bit.query(b[i]-1) < b[i]-1) ans++;
		bit.add(b[i], 1);
	}
	cout << ans << endl;
	
	return 0;
}