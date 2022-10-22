#include <iostream>
#define llint long long

using namespace std;

llint n;
llint x[100005], y[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	
	if(n % 2){
		cout << "NO" << endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		llint j = (i+n/2)%n;
		llint dx = x[(i+1)%n]-x[i], dy = y[(i+1)%n]-y[i];
		llint dx2 = x[(j+1)%n]-x[j], dy2 = y[(j+1)%n]-y[j];
		if(dx*dy2-dy*dx2 != 0 || dx*dx+dy*dy != dx2*dx2+dy2*dy2){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}