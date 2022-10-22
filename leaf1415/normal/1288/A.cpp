#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, d;

llint ceil(llint a, llint b)
{
	return (a+b-1)/b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> d;
		
		llint ub = n, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(mid == 0 || d*mid <= d*(mid+1) - mid*(mid+1)) lb = mid;
			else ub = mid;
		}
		llint need = lb + ceil(d, lb+1);
		if(need <= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}