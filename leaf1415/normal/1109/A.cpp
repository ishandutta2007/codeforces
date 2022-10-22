#include <iostream>
#include <map>
#define llint long long

using namespace std;

int n;
int a[300005];
int sum[300005];
map<llint, llint> omp, emp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] ^ a[i];
	for(int i = 0; i <= n; i++){
		if(i%2) omp[sum[i]]++;
		else emp[sum[i]]++;
	}
	
	llint ans = 0;
	for(auto it = emp.begin(); it != emp.end(); it++) ans += it->second * (it->second-1) / 2;
	for(auto it = omp.begin(); it != omp.end(); it++) ans += it->second * (it->second-1) / 2;
	cout << ans << endl;
	
	return 0;
}