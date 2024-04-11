#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
bool prime[1000005];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = true;
	}
	
	llint t = n;
	for(int i = 2; i < 1000005; i++){
		if(prime[i]) continue;
		while(t % i == 0){
			S.insert(i);
			t /= i;
		}
	}
	if(t > 1) S.insert(t);
	
	if(S.size() == 1){
		if(n == *S.begin()) cout << n << endl;
		else cout << *S.begin() << endl;
	}
	else cout << 1 << endl;
	
	return 0;
}