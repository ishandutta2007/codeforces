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

const string col = "RGBYW";

int n;
string s[200];

int main(){
	int ans = -1;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int mask = 0; mask < (1<<10); mask++){
		bool bad = false;
		for (int i=0; i<n && !bad; i++)
			for (int j=i+1; j<n && !bad; j++) if (s[i] != s[j]){
				bool f = false;
				for (int k=0; k<10; k++) if (mask & (1<<k)){
					if (s[i][0]!=s[j][0] && (k==col.find(s[i][0]) || k==col.find(s[j][0])))
						f = true;
					else if (s[i][1]!=s[j][1] && (k-4 == s[i][1]-'0' || k-4 == s[j][1]-'0'))
						f = true;
				}
				if (!f)
					bad = true;
			}
		if (bad == false){
			if (ans == -1)
				ans = __builtin_popcount(mask);
			else
				ans = min(ans, __builtin_popcount(mask));
		}
	}
	cout << ans << endl;
	return 0;
}