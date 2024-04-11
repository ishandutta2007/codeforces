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

const int maxN= 2000 * 100 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
ll k;
int ans[maxN],nex[maxN];
string f0,f1,pat;
string s[maxN];

struct Mat{
	
	int n,m;
	int mat[4][4];

	Mat (int _n=0, int _m=0, bool H=false){
		n = _n;
		m = _m;
		memset(mat,0,sizeof mat);
		if (H){
			for (int i=0; i<n; i++)
				mat[i][i]=1;
		}
	}

	Mat operator * (const Mat & sec) const {
		
		Mat ret = Mat(n,sec.m);

		for (int i=0; i<ret.n; i++)
			for (int j=0; j<ret.m; j++)
				for (int z=0; z<m; z++)
					ret.mat[i][j] = (ret.mat[i][j] + (ll)mat[i][z] * sec.mat[z][j]) % mod;
		
		return ret;
	}
	
	Mat power (ll p){
		
		if (p==0) return Mat(n,m,true);

		if (p==1) return (*this);

		Mat tmp = power(p/2); tmp = tmp * tmp;

		if (p & 1)
			tmp = tmp * (*this);
		
		return tmp;
	}

};

int get (const string &s){

	
	int match=0 , ret=0;

	for (int i=0; i<(int)s.size(); i++){
		
		while (match!=0 && s[i]!=pat[match]) match=nex[match-1];

		if (s[i]==pat[match]) match++;

		if (match == (int)pat.size()){
			ret++;
			match = nex[match-1];
		}
	}

	return ret;
}

int go (ll rem, const string &s){

	nex[0] = 0;

	int match = 0;

	for (int i=1; i<(int)s.size(); i++){
		while (match!=0 && s[i]!=s[match]) match = nex[match-1];
		if (s[i]==s[match]) match++;
		nex[i] = match;
	}

	pat = s;

	if (rem==0)
		return get(f1);

	string ff = f1 + f0;
	int a = get(f1);
	int b = get(ff);
	int c = get(ff+f1) - a - b;
	int d = get(f1+ff) - a - b;

	Mat base = Mat(4,1); 
	base.mat[0][0] = a;
	base.mat[1][0] = b;
	base.mat[2][0] = c;
	base.mat[3][0] = d;

	Mat zarib = Mat(4,4);
	zarib.mat[0][0]=zarib.mat[0][1]=zarib.mat[0][2]=1;
	zarib.mat[1][0]=zarib.mat[1][2]=zarib.mat[1][3]=1; zarib.mat[1][1]=2;
	zarib.mat[2][2]=1;
	zarib.mat[3][3]=1;

	Mat ret = zarib.power(rem/2) * base;

	return ret.mat[rem%2][0];
}

const bool cmp (const int &a , const int &b){
	return s[a].size()<s[b].size();
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> k >> n;

	vector <int> perm;

	for (int i=1; i<=n; i++){
		cin >> s[i];
		perm.push_back(i);
	}

	if (k<3){
		for (int i=1; i<=n; i++)
			cout << ((k==1 && s[i]=="a") || (k==2 && s[i]=="b")) << endl;
		return 0;
	}

	sort(perm.begin(),perm.end(),cmp);

	f0 = "a" , f1 = "b";

	int poi = 0;

	for (int rep=3; rep<=k && poi<(int)perm.size(); rep++){

		string tmp = f1 + f0;
		f0=f1; f1=tmp;

		while (poi<(int)perm.size() && f1.size()>=s[perm[poi]].size()){
			ans[perm[poi]] = go(k-rep,s[perm[poi]]);
			poi++;
		}
	}

	for (int i=1; i<=n; i++)
		printf ("%d\n" , ans[i]);

	return 0;
}