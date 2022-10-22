#include <iostream>
#define llint long long

using namespace std;

llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint xmax = 0, ymax = 0;
	for(int i = 0; i < n; i++){
		llint x, y; char c;
		cin >> c >> x >> y;
		
		if(c == '+'){
			if(x > y) swap(x, y);
			xmax = max(xmax, x);
			ymax = max(ymax, y);
		}
		else{
			if(x > y) swap(x, y);
			if(xmax <= x && ymax <= y) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
	flush(cout);
	return 0;
}