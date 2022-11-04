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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100 * 1000 + 10;

int n;
int a[MAXN],b[MAXN];
vector <int> Q;

int main(){

	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
		Q.push_back(a[i]);
		Q.push_back(b[i]);
	}
	sort(Q.begin(),Q.end());
	int ans=-1;
	for (int i=0; i<(int)Q.size(); i++){
		int j = i;
		while (j<(int)Q.size() && Q[i]==Q[j]) 
			j++;
		if ((n+1)/2<=(j-i+1)){
			int up=0,down=0;
			for (int k=1; k<=n; k++){
				if (a[k]==Q[i])
					up++;
				else if (b[k]==Q[i])
					down++;
			}
			if ((n+1)/2<=up+down){
				int now = max(0,(n+1)/2-up);
				if (ans==-1 || now<ans)
					ans = now;
			}
		}
		i=j-1;
	}
	cout << ans << endl;
	return 0;
}