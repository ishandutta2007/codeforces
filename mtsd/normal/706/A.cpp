#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	vector <double> time;
	double a,b,n,x,y,v,t,ans;
	cin >> a >> b >> n;
	for(int i=0;i<n;i++){
		cin >> x >> y >> v;
		t = sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
		time.push_back(t);
	}
	ans = *min_element(time.begin(),time.end());
	cout << setprecision(10) << ans << endl;
	return 0;
}