#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#define llint long long
#define mod 998224353
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[1000005], f[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n<=2){
		cout << 1 << endl;
		return 0;
	}
	if(n==3){
		cout << 0 << endl;
		return 0;
	}
	
	llint rem = n, mul = 1;
	while(rem >= mul){
		rem -= mul;
		mul *= 2;
	}
	mul /= 2;
	
	int v = mul*2-1;
	for(int i = 1; i <= v; i++) a[i] = 1;
	for(int i = mul; i <= v; i++){
		if(i%2) a[i]++;
		else f[i]++;
	}
	
	/*cout << v << endl;
	for(int i = 1; i <= v; i++) cout<< a[i] << " ";  cout << endl;
	for(int i = 1; i <= v; i++) cout<< f[i] << " ";  cout << endl;*/
	
	for(int i = mul-1; i >= 1; i--){
		if(i > 1){
			if(i % 2 == 0){
				if(a[i*2+1] % 2){
					if(f[i*2+1] == 0){
						cout << 0 << endl;
						return 0;
					}
					else a[i]++;
				}
				f[i*2+1] = 0;
			}
			else{
				if(a[i*2] % 2 == 0){
					if(f[i*2] == 0){
						cout << 0 << endl;
						return 0;
					}
					else a[i]++;
				}
				f[i*2] = 0;
			}
		}
		f[i] += f[i*2]+f[i*2+1];
		a[i] += a[i*2]+a[i*2+1];
	}
	//cout << a[1] << " " << f[1] << endl;
	if(a[1] <= n && n <= a[1]+f[1]) cout << 1 << endl; //cout << comb(f[1], n-a[1]) << endl;
	else cout << 0 << endl;
	
	return 0;
}