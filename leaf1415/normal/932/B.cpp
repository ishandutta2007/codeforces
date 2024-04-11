#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Q;
int g[1000005];
vector<int> vec[10];

int calc(int n)
{
	int ret = 1;
	for(;n;n/=10) if(n % 10) ret *= n%10;
	return ret;
}

int main(void)
{
	for(int i = 1; i <= 1000005; i++){
		if(i < 10) g[i] = i;
		else g[i] = g[calc(i)];
	}
	for(int i = 1; i <= 1000005; i++){
		vec[g[i]].push_back(i);
	}
	
	cin >> Q;
	int l, r, k;
	for(int q = 0; q < Q; q++){
		cin >> l >> r >> k;
		int lb = lower_bound(vec[k].begin(), vec[k].end(), l) - vec[k].begin();
		int ub = upper_bound(vec[k].begin(), vec[k].end(), r) - vec[k].begin();
		cout << ub - lb << endl;
	}
	
	return 0;
}