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
int a[1<<20];
vector <int> pos[1<<20];

long long go (long long tot, int val){
	vector <int> Q;
	for (int i=0; i<(int)pos[val].size(); i++){
		if (pos[val][i] != 0){
			tot-= abs(a[pos[val][i]]-a[pos[val][i]-1]); 
			Q.push_back(a[pos[val][i]-1]);
		}
		if (pos[val][i] != n-1){
			tot-= abs(a[pos[val][i]]-a[pos[val][i]+1]);
			Q.push_back(a[pos[val][i]+1]);
		}
	}
	sort(Q.begin(), Q.end());
	int pivot = Q[(int)Q.size()/2];
	for (int i=0; i<(int)Q.size(); i++)
		tot+= abs(Q[i] - pivot);
	return tot;
}

int main(){
	cin >> m >> n;	
	for (int i=0; i<n; i++){
		cin >> a[i];
		a[i]--;
		if (i!=0 && a[i]==a[i-1])
			n--, i--;
	}
	for (int i=0; i<n; i++)
		pos[a[i]].push_back(i);
	long long tot = 0;
	for (int i=0; i<n-1; i++)
		tot+= abs(a[i+1] - a[i]);
	long long ans = tot;
	for (int i=0; i<m; i++) if (!pos[i].empty() && n!=1)
		ans = min(ans, go(tot, i));
	cout << ans << endl;
	return 0;
}