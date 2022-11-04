/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n;
int a[100];
vector < pair<int,pii> > Q,res;

void go (int pos){
	if ((int)res.size()<=(int)Q.size())
		return;
	if (a[pos]==n){
		res = Q;
		return;
	}
	if ((int)res.size()<=(int)Q.size()+1)
		return;
	vector < pair<int,pii> > test(n+1);
	for (int i=1; i<=pos; i++){
		for (int k=2; k<=8; k<<=1) if (a[i]*k>a[pos] && a[i]*k<=n)
			test[a[i]*k] = make_pair(-1,pii(k,i));
		for (int j=1; j<=pos; j++)
			for (int k=1; k<=8; k<<=1) if (a[i]+a[j]*k>a[pos] && a[i]+a[j]*k<=n)
				test[a[i] + a[j]*k] = make_pair(i,pii(k,j));
	}
	for (int i=n; i>a[pos]; i--) if (test[i].first){
		a[pos+1] = i;	
		Q.push_back(test[i]);
		go(pos+1);
		Q.pop_back();
	}
}

int main(){
	scanf ("%d" , &n);
	a[1] = 1;
	res.resize(100);
	go(1);
	printf("%d\n" , res.size());
	for (int i=0; i<(int)res.size(); i++){
		if (res[i].first!=-1)
			printf ("lea e%cx, [e%cx + %d*e%cx]\n" , char('a'+i+1), char('a'+res[i].first-1), res[i].second.first, char('a'+res[i].second.second-1));
		else
			printf ("lea e%cx, [%d*e%cx]\n" , char('a'+i+1), res[i].second.first, char('a'+res[i].second.second-1));
	}
	return 0;
}