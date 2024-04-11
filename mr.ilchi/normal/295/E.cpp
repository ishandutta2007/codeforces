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

const int base = 400;

int n;
int x[1<<20],pos[1<<20];
pii a[1<<20];
LL sum[1<<20], func[1<<20];

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &x[i]);
		a[i] = pii(x[i], i);
	}
	sort(a, a+n);
	for (int i=0; i<n; i++)
		pos[a[i].second] = i;
	for (int i=0; i<n; i++){
		sum [i/base]+= a[i].first;
		func[i/base]+= 2LL * i * a[i].first;
	}
	int que; scanf("%d", &que);
	for (int o=0; o<que; o++){
		int t; scanf("%d", &t);
		if (t==1){
			int p,d; scanf("%d%d", &p, &d);
			p = pos[p-1];
			a[p].first+= d;
			sum[p/base]+= d;
			func[p/base]+= 2LL * d * p;
			int cur = p/base;
			while (p!=0 && a[p].first < a[p-1].first){
				int nex = (p%base ==0) ? (cur-1) : (cur);
				LL t = a[p-1].first - a[p].first;
				sum [cur]+= t;
				sum [nex]-= t;
				func[cur]+= 2LL * p * t;
				func[nex]-= 2LL * (p-1) * t;
				cur = nex;
				swap(pos[a[p].second], pos[a[p-1].second]);
				swap(a[p], a[p-1]);
				p--;
			}
			cur = p/base;
			while (p!=n-1 && a[p].first > a[p+1].first){
				p++;
				int nex = cur;
				if (p%base == 0) cur++;
				LL t = a[p-1].first - a[p].first;
				sum [cur]+= t;
				sum [nex]-= t;
				func[cur]+= 2LL * p * t;
				func[nex]-= 2LL * (p-1) * t;
				swap(pos[a[p].second], pos[a[p-1].second]);
				swap(a[p], a[p-1]);
			}
		}else{	
			int lo,hi; scanf("%d%d", &lo, &hi);
			lo = lower_bound(a, a+n, pii(lo,-1)) - a;
			hi = upper_bound(a, a+n, pii(hi+1,-1)) - a - 1;
			int temp = hi, len = hi-lo+1;
			LL f1=0, f2=0;
			while (lo%base!=0 && lo<=hi){
				f1+= a[lo].first;
				f2+= a[lo].first * 2LL * lo;
				lo++;
			}
			while (hi%base!=base-1 && lo<=hi){
				f1+= a[hi].first;
				f2+= a[hi].first * 2LL * hi;
				hi--;
			}
			while (lo<=hi){
				f1+= sum [lo/base];
				f2+= func[lo/base];
				lo+=base;
			}
			cout << f2 - f1 * (2LL * temp - (len-1)) << endl;
		}
	/*	for (int i=0; i<n; i++)
			cout << a[i].first << ' '; cout << endl;
		cout << endl;
		for (int i=1; i<n; i++) if (a[i].first < a[i-1].first)
			cout << "NOT SORT" << endl;
		for (int i=0; i<n/base; i++){
			LL S=0, T=0;
			for (int j=i*base; j<min(n, (i+1)*base); j++){
				S+= a[j].first;
				T+= a[j].first * 2LL * j;
			}
			if (S!=sum[i]){
				cout << "BAD SUM " << S << ' ' << sum[i] << ' ' << i << ' ' << a[2*i].first << ' ' << a[2*i].second << endl;
			}
			if (T!=func[i])
				cout << "BAD FUNC!" << T << ' ' << func[i] << endl;
		}*/
	}
	return 0;
}