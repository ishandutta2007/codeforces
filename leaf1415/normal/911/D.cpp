#include <iostream>

using namespace std;

int n, m;
int a[1505];

int bit[1505];
void init(){
	for(int i = 1; i <= n; i++) bit[i] = 0;
}

int query(int i)
{
	int ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i & (-i);
	}
	return ret;
}

void add(int i, int val)
{
	while(i <= n){
		bit[i] += val;
		i += i & (-i);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += i - query(a[i]);
		cnt %= 2;
		add(a[i], 1);
	}
	
	cin >> m;
	int l, r;
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		cnt += (r - l + 1) / 2;
		cnt %= 2;
		if(cnt) cout << "odd" << endl;
		else cout << "even" << endl;
	}
	
	return 0;
}