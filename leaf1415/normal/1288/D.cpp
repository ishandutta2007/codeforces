#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, m;
llint a[300005][10];
llint b[1<<8];
llint mask[300005];

void zeta_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(!(j&(1<<i))) a[j] += a[j^(1<<i)];
		}
	}
}

bool check(llint x)
{
	for(int i = 0; i < (1<<m); i++) b[i] = 0;
	for(int i = 1; i <= n; i++){
		mask[i] = 0;
		for(int j = 0; j < m; j++){
			if(a[i][j] >= x) mask[i] |= 1<<j;
		}
		b[mask[i]]++;
	}
	zeta_transform(b, m);
	
	for(int i = 1; i <= n; i++){
		if(b[(1<<m)-1 - mask[i]] > 0) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	llint ub = 1e9+7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	
	for(int i = 0; i < (1<<m); i++) b[i] = 0;
	for(int i = 1; i <= n; i++){
		mask[i] = 0;
		for(int j = 0; j < m; j++){
			if(a[i][j] >= lb) mask[i] |= 1<<j;
		}
		b[mask[i]]++;
	}
	zeta_transform(b, m);
	
	for(int i = 1; i <= n; i++){
		if(b[(1<<m)-1 - mask[i]] > 0){
			cout << i << " ";
			for(int j = 1; j <= n; j++){
				if((mask[i] | mask[j]) == (1<<m)-1){
					cout << j << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}