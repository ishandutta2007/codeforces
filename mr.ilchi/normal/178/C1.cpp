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

const int maxN = 200 * 1000 + 10;

int h,m,n,len;
int LOW,PLA,HIG,IND,VAL;
int comp[maxN],pos[maxN];
vector <int> first[maxN];

inline int get (const int &root , const int &lo , const int &hi){

//	cout << root << ' ' << lo << ' ' << hi << ' ' << LOW << ' ' << HIG << ' ' << first[IND][root] << endl;

	if (HIG<lo || hi<LOW || first[IND][root]==len+1)
		return len + 1;

	if (LOW<=lo && hi<=HIG)
		return first[IND][root];

	int mid = (lo + hi) / 2;

	int ret = get((root<<1),lo,mid);

	if (ret!=(len+1))
		return ret;

	return get((root<<1)+1,mid+1,hi);
}

inline void go  (const int &root , const int &lo , const int &hi){

//	cout << root << ' ' << lo << ' ' << hi << ' ' << PLA << endl;

	if (lo==hi){
		if (VAL==-1)
			first[IND][root] = lo;
		else
			first[IND][root] = len+1;
		return;
	}

	int mid = (lo + hi) / 2;

	if (PLA<=mid) 
		go((root<<1),lo,mid);
	else
		go((root<<1)+1,mid+1,hi);

	first[IND][root] = min(first[IND][root<<1] , first[IND][(root<<1)+1]);
}

void build (int root, int lo, int hi){
	first[IND][root] = lo;
	if (lo==hi) return;
	int mid=  (lo+hi)/2;
	build((root<<1),lo,mid);
	build((root<<1)+1,mid+1,hi);
}

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> h >> m >> n;

	int cnt = 0;

	for (int i=0; i<h; i++) if (comp[i]==0){
		
		cnt++;

		comp[i] = cnt; pos[i]=1;

		int now = (i + m); if (now>=h) now-=h;

		int Count=1;

		while (comp[now]==0){
			Count++;
			comp[now] = cnt;
			pos [now] = Count;
			now = (now + m); if (now>=h) now-=h;
		}

		len = Count;
	}

	int x=0;

	while ((1<<x)<len) x++; x++; 

	for (int i=1; i<=cnt; i++){
		first[i].resize((1<<x)+1);
		IND = i;
		build(1,1,len);
	}

	ll ans = 0;

	map <int,pii> mp;

	for (int o=1; o<=n; o++){
		
		char ord; cin >> ord;

		int id; cin >> id;

		if (ord=='-'){
			pii tmp = mp[id]; mp.erase(id);
			IND = tmp.first;
			PLA = tmp.second;
			VAL = -1;
			go(1,1,len);
		}
		else{
			int pl; cin >> pl;
			IND = comp[pl];
			LOW = pos[pl];
			HIG = len;
		//	cout << "pos " << pl << ' ' << pos[pl] << endl;
		//	cout << "/////" << endl;
			int tmp = get(1,1,len);
			if (tmp!=(len+1)){
				ans+= tmp-pos[pl];
				PLA = tmp;
			}
			else{
				ans+= (len+1)-pos[pl];
				LOW = 1;
				HIG = pos[pl]-1;
				tmp = get(1,1,len);
				ans+= tmp-1;
				PLA = tmp;
			}
			VAL = +1;
			go(1,1,len);
			mp[id] = pii(IND,PLA);
	//		if (ans==1)
	//s			cout << o << endl;
		}
	}

	cout << ans << endl;

	return 0;
}