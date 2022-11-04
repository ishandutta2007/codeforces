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

const int MAXP = 100+10;
const int MAXN = 100000+10;
const LL  inf  = (1LL<<60);

int n,m,p;
LL d [MAXN], sum[MAXN];
LL dp[MAXN][MAXP];

struct segment{
	LL A,B,lo,hi;
	segment(){}
	segment(LL A, LL B, LL lo, LL hi) : A(A), B(B), lo(lo), hi(hi) {}
	inline LL eval (int x){
		return A*x + B;
	}
}Q[MAXN];

int main(){
	cin >> n >> m >> p;
	for (int i=1; i<n; i++){
		cin >> d[i]; 
		d[i]+= d[i-1]; 
	}
	vector <LL> store;
	for (int i=0; i<m; i++){
		int pos,t; cin >> pos >> t; pos--;
		store.push_back(t-d[pos]);
	}	
	sort(store.begin(), store.end());
	for (int i=0; i<m; i++)
		sum[i] = sum[max(0, i-1)] + store[i];
	for (int rep=0; rep<=p; rep++){
		int head = 0, tail = 0;
		for (int i=m; i>=0; i--){
			if (rep == 0){
				dp[i][rep] = (i==m) ? (0) : (inf);
			}else{
				while (head!=tail && Q[head].lo > i) head++;
				dp[i][rep] = (i==m) ? (0) : (Q[head].eval(i) + ((i!=0) ? (sum[i-1]) : (0)));
				if (i!=0 && dp[i][rep-1]!=inf){
					segment temp(-store[i-1], dp[i][rep-1] + store[i-1] * i - sum[i-1], -m, m);
					while (tail!=head && temp.eval(Q[tail-1].hi) <= Q[tail-1].eval(Q[tail-1].hi))
						tail--;
					if (head != tail && Q[tail-1].A!=temp.A){
						temp.hi = (Q[tail-1].B - temp.B) / (temp.A - Q[tail-1].A);
						while (temp.eval(temp.hi) > Q[tail-1].eval(temp.hi)) temp.hi--;
						Q[tail-1].lo = temp.hi + 1;
					}
					if (head==tail || Q[tail-1].A!=temp.A)
						Q[tail++] = temp;
				}
			}
		}
	}
	cout << dp[0][p] << endl;
	return 0;
}