#include <iostream>
#define llint long long 

using namespace std;

llint n, q;
llint h;

int main(void)
{
	cin >> n >> q;
	h = (n*n+1) / 2;
	for(int i = 0; i < q; i++){
		llint r, c;
		cin >> r >> c;
		
		llint ans;
		if((r+c) % 2 == 0){
			ans = (r-1)/2*n;
			if(r%2 == 0) ans += (n+1)/2;
			ans += (c+1)/2;
		}
		else{
			ans = (r-1)/2*n;
			if(r%2 == 0) ans += n/2;
			ans += (c+1)/2;
			ans += h;
		}
		cout << ans << endl;
	}
	return 0;
}