/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

int n;
double a[200];

double go (){
	double ret = 0;
	double A = 0.0, B = 1.0;
	for (int i=0; i<n; i++){
		if (abs(a[i]-1.0) < 1e-9)
			ret = a[i];
		else{
			A+= a[i] / (1-a[i]);
			B*= (1-a[i]);
			ret = max(ret, A * B);
		}
	}
	return ret;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	double ans = go(); reverse(a, a+n);
	ans = max(go(), ans);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}