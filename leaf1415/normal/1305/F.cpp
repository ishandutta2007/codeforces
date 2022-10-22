#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#define llint long long

using namespace std;

llint n;
llint a[200005];
bool prime[1000015];
vector<llint> pvec, fvec;

llint getrand(){
	llint ret = rand();
	ret = ret * RAND_MAX + rand();
	ret = ret * RAND_MAX + rand();
	ret = ret * RAND_MAX + rand();
	return ret;
}

void factor(llint x)
{
	for(int i = 0; i < pvec.size(); i++){
		llint p = pvec[i];
		if(p > x) return;
		while(x % p == 0){
			x /= p;
			fvec.push_back(p);
		}
	}
	if(x > 1) fvec.push_back(x);
}

llint calc(llint p)
{
	llint ret = 0;
	for(int i = 1; i <= n; i++){
		llint tmp = (a[i]+p-1)/p*p-a[i];
		if(a[i]/p) tmp = min(tmp, a[i]-a[i]/p*p);
		ret += tmp;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	for(int i = 2; i < 1015; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000015; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 1000015; i++) if(!prime[i]) pvec.push_back(i);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	fvec.push_back(2), fvec.push_back(3);
	for(int i = 0; i < 6; i++){
		llint x = getrand() % n + 1;
		for(llint j = max(1LL, a[x]-10); j <= a[x]+10; j++){
			factor(j);
		}
	}
	sort(fvec.begin(), fvec.end());
	fvec.erase(unique(fvec.begin(), fvec.end()), fvec.end());
	
	llint ans = n+1;
	for(int i = 0; i < fvec.size(); i++){
		ans = min(ans, calc(fvec[i]));
		//cout << fvec[i] << " " << ans << endl;
	}
	cout << ans << endl;

	return 0;
}