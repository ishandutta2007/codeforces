#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long 

using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(llint i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(llint i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, T;
llint a[200005];
BIT bit(200005);

llint get(llint t)
{
	llint ub = n, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(bit.query(mid) > T) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main(void)
{
	cin >> n >> T;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0, sum = 0, rem = n;
	for(int i = 1; i <= n; i++) sum += a[i];
	for(int i = 1; i <= n; i++) bit.add(i, a[i]);
	
	while(rem){
		ans += T/sum*rem;
		T %= sum;
		
		while(sum > T){
			llint p = get(T);
			bit.add(p, -a[p]);
			sum -= a[p];
			rem--;
			if(rem <= 0) break;
		}
	}
	cout << ans << endl;
	
	return 0;
}