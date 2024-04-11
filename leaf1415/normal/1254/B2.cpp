#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <set>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[1000005], b[1000005];
bool prime[1000005];
set<llint> S;
vector<llint> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum == 1){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 1000005; i++){
		if(!prime[i]) pvec.push_back(i);
	}
	
	llint t = sum;
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		while(t % p == 0){
			S.insert(p);
			t /= p;
		}
	}
	if(t > 1) S.insert(t);
	
	llint ans = 1e18;
	for(auto it = S.begin(); it != S.end(); it++){
		llint x = *it, cnt = 0, l = -1, r = -1, m = -1, tmp = 0;
		//cout << x << endl;
		if(x == 1) continue;
		
		for(int j = 1; j <= n; j++) b[j] = a[j] % x;
		for(int j = 1; j <= n; j++){
			cnt += b[j];
			if(l == -1 && cnt >= 1) l = j;
			if(m == -1 && cnt >= (x+1)/2) m = j;
			if(cnt >= x){
				r = j;
				//cout << l << " " << r << " " << m << endl;
				for(int k = l; k <= r; k++){
					if(k < r) tmp += b[k] * abs(k-m);
					else tmp += (b[k]-(cnt-x)) * abs(k-m);
				}
				b[j] = cnt-x;
				cnt = 0, l = r = m = -1;
				j--;
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans  << endl;
	
	return 0;
}