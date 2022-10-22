#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#define llint long long

using namespace std;

const int N = 1 << 20;
string s;
bool can[N];
llint pop[N], z[N];

void zeta_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(j&(1<<i)) a[j] = max(a[j], a[j^(1<<i)]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		int mask = 0, c;
		for(int j = 0; j < 20; j++){
			if(i+j >= (int)s.size()) break;
			c = s[i+j] - 'a';
			if(mask & (1<<c)) break;
			mask |= (1<<c);
			can[mask] = true;
		}
	}
	for(int i = 1; i < N; i++) pop[i] = pop[i&(i-1)] + 1;
	for(int i = 1; i < N; i++){
		if(!can[i]) pop[i] = 0;
		z[i] = pop[i];
	}
	
	zeta_transform(z, 20);
	
	llint ans = 0;
	for(int i = 0; i < N; i++) ans = max(ans, pop[i]);
	for(int i = 0; i < N; i++){
		ans = max(ans, pop[i] + z[N-1-i]);
	}
	cout << ans << endl;
	
	return 0;
}