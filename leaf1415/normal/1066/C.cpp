#include <iostream>
#include <vector>
#include <map>

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

int Q;
int qt[200005], qx[200005];
map<int, int> mp;
BIT lbit(200005), rbit(200005);

int main(void)
{
	cin >> Q;
	
	int num = 0;
	char c; int x;
	for(int i = 0; i < Q; i++){
		cin >> c >> x;
		if(c == 'L'){
			lbit.add(1, 1);
			lbit.add(num+1, -1);
			rbit.add(num+1, num);
			rbit.add(num+2, -num);
			mp[x] = ++num;
		}
		if(c == 'R'){
			rbit.add(1, 1);
			rbit.add(num+1, -1);
			lbit.add(num+1, num);
			lbit.add(num+2, -num);
			mp[x] = ++num;
		}
		if(c == '?'){
			int id = mp[x];
			//cout << lbit.query(id) << rbit.query(id) << endl;
			cout << min(lbit.query(id), rbit.query(id)) << endl;
		}
	}
	return 0;
}