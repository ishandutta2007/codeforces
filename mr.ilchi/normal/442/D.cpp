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
int f[100];
int dp[1<<20];
vector <int> adj[1<<20];

int go (int MAX){
	for (int i=MAX; i>=0; i--){
		int max1 = -1, max2 = -1;
		for (int j=0; j<(int)adj[i].size(); j++){
			int tmp = adj[i][j];
			if (tmp <= MAX){
				if (max1 <= dp[tmp]){
					max2 = max1;
					max1 = dp[tmp];
				}else if (max2 <= dp[tmp])
					max2 = dp[tmp];
			}else
				break;
		}
		if (i == 0)
			return max1;
		if (max1 == -1)
			dp[i] = 1;
		else
			dp[i] = max(max2+1, max1);
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n; n++;
	for (int i=1; i<n; i++){
		int P; cin >> P; P--;
		adj[P].push_back(i);
	}
	for (int i=0; i<n; i++)
		sort(adj[i].begin(), adj[i].end());
	for (int i=1; true; i++){
		int lo = 1, hi = n-1, ans = -1;
		while (lo <= hi){
			int mid = (lo + hi) / 2;
			if (go(mid) >= i){
				ans = mid+1;
				hi = mid-1;
			}else
				lo = mid+1;
		}
		f[i] = ans;
		if (ans == -1)
			break;
	}
	for (int i=2; i<=n; i++){
		for (int j=1; true; j++){ 
			if (f[j]==-1 || f[j]>i){
				cout << j-1 << ' ';
				break;
			}
		}
	}
	cout << endl;
	return 0;
}