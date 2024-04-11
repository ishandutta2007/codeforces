#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#define llint long long
#define eps 1e-7

using namespace std;

llint n;
double a[100005];
llint IP[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint sum = 0; double fsum = 0;
	for(int i = 0; i < n; i++){
		llint ip = floor(a[i]+eps);
		double fp = a[i] - ip;
		sum += ip;
		IP[i] = ip;
		if(fp < eps){
			used[i] = true;
			continue;
		}
		fsum += fp;
	}
	llint k = floor(fsum+eps);
	
	for(int i = 0; i < n; i++){
		if(used[i]) cout << IP[i] << "\n";
		else{
			if(k) cout << IP[i]+1 << "\n", k--;
			else cout << IP[i] << "\n";
		}
	}
	flush(cout);
	
	return 0;
}