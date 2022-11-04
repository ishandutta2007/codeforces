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
typedef complex<int> point;
typedef long double ldb;

const int MAXN = 400000+10;

int n,que;
int x[MAXN],y[MAXN];
double val[MAXN];
point O;
vector <int> perm;
vector <point> convex,store;

ll cross (const point &A, const point &B) { return (ll)A.real()*B.imag() - (ll)A.imag()*B.real(); }

bool cmp (const int &A, const int &B){
	return val[A]<val[B];
}

bool inside (const point &A){
	if (A==O)
		return true;
	if (A.real()<O.real())
		return false;
	if (A.real()==O.real() && A.imag()<O.imag())
		return false;
	if (cross(convex[1]-O,A-O)<0)
		return false;
	if (cross(convex.back()-O,A-O)>0)
		return false;
	int lo=1,hi=(int)convex.size()-2,ans=-1;
	while (lo<=hi){
		int mid = (lo+hi)/2;
		if (cross(convex[mid]-O,A-O)>=0){
			ans = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	if (ans==-1)
		return false;
	return cross(convex[ans]-A,convex[ans+1]-A)>=0;
}

int main(){
	for (int rep=1; rep<=3; rep++){
		scanf("%d",&n);
		pii mini = pii(1<<30,1<<30);
		for (int i=0; i<n; i++){
			scanf("%d%d", &x[i], &y[i]);
			mini = min(mini,pii(x[i],y[i]));
		}
		for (int i=0; i<n; i++)
			store.push_back(point(x[(i+1)%n]-x[i],y[(i+1)%n]-y[i]));
		O.real()+= mini.first;
		O.imag()+= mini.second;
	}
	for (int i=0; i<(int)store.size(); i++){
		perm.push_back(i);
		val[i] = arg(complex<double>(store[i].real(),store[i].imag()));
		if (val[i]<0) val[i]+= 2*M_PI;
	}
	sort(perm.begin(),perm.end(),cmp);
	point cur = point(0,0);
	convex.push_back(cur);
	point cent = cur;
	for (int i=0; i<(int)perm.size(); i++){
		cur+= store[perm[i]];
		convex.push_back(cur);
		if (cur.real()<cent.real())
			cent = cur;
		else if (cur.real()==cent.real() && cur.imag()<cent.imag())
			cent = cur;
	}
	convex.pop_back();
	int posC = 0;
	for (int i=0; i<(int)convex.size(); i++){
		convex[i] = convex[i] - cent + O;
		if (convex[i]==O)
			posC = i;
	}
	for (int i=0; i<posC; i++)
		convex.push_back(convex[i]);
	for (int i=posC; i<(int)convex.size(); i++)
		swap(convex[i],convex[i-posC]);
	convex.resize((int)convex.size()-posC);
	int sz = (int)convex.size();
	while (cross(convex[sz-1]-O,convex[sz-2]-O)==0){
		sz--; 
		convex.pop_back();
	}
	scanf ("%d", &que);
	for (int o=1; o<=que; o++){
		int X,Y; scanf("%d%d", &X, &Y);
		puts(inside(3*point(X,Y)) ? "YES" : "NO");
	}
	return 0;
}