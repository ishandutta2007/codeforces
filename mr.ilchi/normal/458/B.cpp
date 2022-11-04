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
int a[1<<20],b[1<<20];

long long go (int *a, int *b, int n, int m){
	long long sa = 0, sb = 0;
	for (int i=0; i<m; i++)
		sb+= b[i];
	long long ret = (1LL<<60);
	for (int i=0; i<n; i++){
		if (sb <= ret/(n-i))
			ret = min(ret, sb * (n-i) + sa);
		sa+= a[i];
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i]; sort(a, a+n);
	for (int i=0; i<m; i++) cin >> b[i]; sort(b, b+m);
	cout << min(go(a,b,n,m),go(b,a,m,n)) << endl;
	return 0;
}