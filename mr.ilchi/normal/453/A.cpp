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

int n,m;
double lg[1<<20];

int main(){
	cin >> m >> n;
	double ans = 0.0;
	for (int i=1; i<=m; i++){
		if (i == 1)
			ans+= 1.0;
		else
			ans+= 1.0 - exp(n * (log(i-1.0) - log(m)));
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}