#include <iostream>
#define llint long long

using namespace std;

llint a, b, c;
llint f[] = {0, 1, 2, 0, 2, 1, 0};

bool check(llint d, llint x)
{
	llint A = x/7*3, B = x/7*2, C = x/7*2;
	for(int i = 0; i < x%7; i++){
		int D = (d+i)%7;
		if(f[D] == 0) A++;
		if(f[D] == 1) B++;
		if(f[D] == 2) C++;
	}
	return A<=a && B<=b && C<=c;
}

int main(void)
{
	cin >> a >> b >> c;
	
	llint ans = 0;
	for(int i = 0; i < 7; i++){
		llint ub = 1e12, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(i, mid)) lb = mid;
			else ub = mid;
		}
		ans = max(ans, lb);
	}
	cout << ans << endl;
	return 0;
}