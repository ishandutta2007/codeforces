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

const int len = 102;

const int lo[] = {1, 3, 4, 5, 7, 9, 13, 15, 19, 27, 39, 40, 57, 58, 81, 85, 120, 121, 174, 179, 255, 260, 363, 382, 537, 544, 780, 805, 1146, 1169, 1632, 1718, 2415, 2447, 3507, 3622, 5154, 5260, 7341, 7730, 10866, 11011, 15780, 16298, 23190, 23669, 33033, 34784, 48894, 49549, 71007, 73340, 104352, 106510, 148647, 156527, 220020, 222970, 319530, 330029, 469581, 479294, 668910, 704371, 990087, 1003364, 1437882, 1485130, 2113113, 2156822, 3010092, 3169669, 4455390, 4515137, 6470466, 6683084, 9509007, 9705698, 13545411, 14263510, 20049252, 20318116, 29117094, 30073877, 42790530, 43675640, 60954348, 64185794, 90221631, 91431521, 131026920, 135332446, 192557382, 196540379, 274294563, 288836072, 405997338, 411441844, 589621137, 608996006, 866508216, 884431705};

const int hi[] = {2, 3, 4, 6, 8, 12, 14, 18, 26, 38, 39, 56, 57, 80, 84, 119, 120, 173, 178, 254, 259, 362, 381, 536, 543, 779, 804, 1145, 1168, 1631, 1717, 2414, 2446, 3506, 3621, 5153, 5259, 7340, 7729, 10865, 11010, 15779, 16297, 23189, 23668, 33032, 34783, 48893, 49548, 71006, 73339, 104351, 106509, 148646, 156526, 220019, 222969, 319529, 330028, 469580, 479293, 668909, 704370, 990086, 1003363, 1437881, 1485129, 2113112, 2156821, 3010091, 3169668, 4455389, 4515136, 6470465, 6683083, 9509006, 9705697, 13545410, 14263509, 20049251, 20318115, 29117093, 30073876, 42790529, 43675639, 60954347, 64185793, 90221630, 91431520, 131026919, 135332445, 192557381, 196540378, 274294562, 288836071, 405997337, 411441843, 589621136, 608996005, 866508215, 884431704, 1217992013};

const int cost[] = {0, 1, 2, 1, 2, 0, 1, 2, 0, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 1};

vector <pii> Q;
vector <int> val;

inline int get (int x){
	for (int i=(int)Q.size()-1; i>=0; i--) if (Q[i].first <= x)
		return i;
	return -1;
}

inline int func3(int x){
	return 3 * x; 
}

inline int func32 (int x){
	int t = max(x, x * 3 / 2 - 3);
	while (t - t / 3 < x) t++;
	return t;
}

inline void init(){
	Q.push_back(pii(0,2));
	val.push_back(0);
	int cur = 3;
	while (cur<=1000000000){
		int f1 = cur / 3;
		int f2 = cur - cur / 3;
		int p1 = get(f1);
		int p2 = get(f2);
		int end = min(func3(Q[p1].second+1)-1, func32(Q[p2].second+1)-1);
		int V = 0;
		f1 = val[p1]; f2=val[p2]; if (f1>f2) swap(f1,f2);
		if (f1==0 && f2==1)
			V = 2;
		else if (f1==0)
			V = 1;
		if (V == val.back()){
			Q[(int)Q.size()-1].second = end;
		}
		else{
			Q.push_back(pii(cur, end));
			val.push_back(V);
		}
		cur = end + 1;
	}
	cout << Q.size() << endl;
	for (int i=0; i<(int)Q.size(); i++)
		cout << Q[i].first << ", " ;
	cout << endl;
	for (int i=0; i<(int)Q.size(); i++)
		cout << Q[i].second << ", " ;
	cout << endl;
	for (int i=0; i<(int)val.size(); i++)
		cout << val[i] << ", ";
	cout << endl;
}	

const LL mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000+10;

int n,p;
LL way[3];
LL C[MAXN][MAXN];

inline LL sum (LL A, LL B){
	return (A+B) * (B-A+1) / 2;
}

inline LL POWER(LL base, LL p){
	base%=mod;
	LL ret = 1;
	LL cur = base;
	while (p){
		if (p & 1){
			ret = ret * cur % mod;
		}
		p>>=1;
		cur = cur * cur % mod;
	}
	return ret;
}

int main(){
//	init();
	cin >> n >> p;
	for (int i=0; i<102; i++) if (lo[i] < p){
		int f1 = lo[i];
		int f2 = min(p-1, hi[i]);
		way[cost[i]]+= sum(p-f2, p-f1);
	}
	way[0]%=mod; way[1]%=mod; way[2]%=mod;
	for (int i=0; i<MAXN; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	LL ans = POWER(way[0] + way[1] + way[2], n);
	for (int i=0; i<=n; i+=2)
		for (int j=0; j<=n; j+=2) if (i + j <= n){
			LL temp = (LL)C[n][i] * C[n-i][j] % mod;
			temp = temp * POWER(way[1], i) % mod;
			temp = temp * POWER(way[2], j) % mod;
			temp = temp * POWER(way[0], n-i-j) % mod;
			ans = (ans - temp) % mod;
		}
	if (ans < 0) ans+= mod;
	cout << ans << endl;
	return 0;
}