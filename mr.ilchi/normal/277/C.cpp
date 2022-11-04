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

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n,m,k;
vector <pii> val;
map < int , vector <pii> > vertical, horizontal;

inline int go (vector <pii> Q){
	int ret = 0;
	sort(Q.begin(),Q.end());
	for (int i=0; i<(int)Q.size(); i++){
		int j=i,maxi=Q[i].second;
		while (j<(int)Q.size() && Q[j].first<=maxi)
			maxi = max(Q[j++].second, maxi);
		ret+= maxi - Q[i].first;
		i=j-1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i=0; i<k; i++){
		int x,y,xx,yy;
		cin >> x >> y >> xx >> yy;
		if (x==xx)
			vertical[x].push_back(pii(min(y,yy),max(y,yy)));
		else
			horizontal[y].push_back(pii(min(x,xx), max(x,xx)));
	}
	for (map < int , vector <pii> > :: iterator it = vertical.begin(); it!=vertical.end(); it++)
		val.push_back(pii(it->first, m-go(it->second)));
	if (((n-1)-(int)vertical.size())%2){
		for (int i=1; i<=n-1; i++) if (vertical.find(i)==vertical.end()){
			vertical[i] = vector <pii> ();
			val.push_back(pii(i,m));
			break;
		}
	}
	for (map < int , vector <pii> > :: iterator it = horizontal.begin(); it!=horizontal.end(); it++)
		val.push_back(pii(-(it->first), n-go(it->second)));
	if (((m-1)-(int)horizontal.size())%2){
		for (int i=1; i<=m-1; i++) if (horizontal.find(i)==horizontal.end()){
			horizontal[i] = vector <pii> ();
			val.push_back(pii(-i,n));
			break;
		}
	}
	int nim=0;
	for (int i=0; i<(int)val.size(); i++)
		nim = nim ^ val[i].second;
	if (nim == 0){
		cout << "SECOND" << endl;
		return 0;
	}
	cout << "FIRST" << endl;
	int bit = -1;
	for (int i=30; i>=0; i--) if ((1<<i) & nim){
		bit = i;
		break;
	}
	for (int i=0; i<(int)val.size(); i++) if (val[i].second & (1<<bit)){
		int less = 0;
		for (int j=bit; j>=0; j--) if (nim & (1<<j)){
			if (val[i].second & (1<<j))
				less+= (1<<j);
			else
				less-= (1<<j);
		}
		vector <pii> Q = (val[i].first < 0) ? horizontal[-val[i].first] : vertical[val[i].first];
		sort(Q.begin(), Q.end());
		int sum = 0, past = 0, ans = -1;
		for (int k=0; k<(int)Q.size(); k++){
			int j=k,maxi=Q[k].second;
			while (j<(int)Q.size() && Q[j].first<=maxi)
				maxi = max(Q[j++].second, maxi);
			sum+= Q[k].first - past;
			if (sum>=less){
				ans = Q[k].first - (sum-less);
				break;
			}
			past = maxi;
			k=j-1;
		}
		if (ans == -1)
			ans = past + (less - sum);
		if (val[i].first > 0)
			cout << val[i].first << ' ' << 0 << ' ' << val[i].first << ' ' << ans << endl;
		else
			cout << 0 << ' ' << -val[i].first << ' ' << ans << ' ' << -val[i].first << endl;
		break;
	}
	return 0;
}