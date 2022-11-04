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

const int mod = 12345;
const int maxQ= 1000+10;

bool mark[30][150];
char ch[maxQ];
int que;
int num[maxQ],mul[maxQ];
ll n;
int start = clock();

struct MAT{
	int n,m;
	vector < vector<int> > mat;
	MAT () {}
	MAT (int _n, int _m, bool h=false){
		n = _n;
		m = _m;
		mat = vector < vector<int> > (n,vector<int>(m,0));
		if (h)
			for (int i=0; i<n; i++)
				mat[i][i] = 1;
	}
	MAT operator * (const MAT &SEC) const{
		MAT ret = MAT(n,SEC.m);
		for (int i=0; i<n; i++)
			for (int j=0; j<SEC.m; j++)
				for (int k=0; k<m; k++)
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * SEC.mat[k][j]) % mod;
		return ret;
	}
	MAT POWER (ll p){
		MAT ret = MAT(n,n,true);
		MAT cur = *this;
		while (p){
			if (p & 1)
				ret = ret * cur;
			cur = cur * cur;
			p>>=1;
		}
		return ret;
	}
};

int main(){
	cin >> n >> que;
	if (n==0 || que==0){
		cout << (n==0) << endl;
		return 0;
	}
	for (int o=1; o<=que; o++){
		cin >> ch[o] >> num[o];
		if (mark[ch[o]-'A'][num[o]]){
			que--; o--;
		}
		else
			mark[ch[o]-'A'][num[o]] = true;
	}
	mul[que+1] = 1;
	for (int i=que; i>0; i--)
		mul[i] = mul[i+1] * num[i];
	MAT comb = MAT(mul[1],mul[1]);
	for (int i=0; i<mul[1]; i++){
		int cur = i;
		vector <int> Q;
		for (int j=1; j<=que; j++){
			Q.push_back(cur/mul[j+1]);
			cur-= Q.back()*mul[j+1];
		}
		for (char j='A'; j<='Z'; j++){
			int temp = i;
			bool bad = true;
			for (int k=1; k<=que; k++) if (ch[k]==j){
				bad = false;
				temp-= Q[k-1]*mul[k+1];
				temp+= ((Q[k-1]+1)%num[k])*mul[k+1];
			}
			if (!bad)
				comb.mat[temp][i]++;
		}
	}
	MAT base= MAT(mul[1],1);
	base.mat[0][0] = 1;
	MAT ans = comb.POWER(n) * base;
	int ret = 0;
	for (int i=0; i<mul[1]; i++){
		int cur = i;
		vector <int> Q;
		for (int j=1; j<=que; j++){
			Q.push_back(cur/mul[j+1]);
			cur-= Q.back()*mul[j+1];
		}
		bool bad = false;
		for (char j='A'; j<='Z'; j++){
			bool f1 = false;
			bool f2 = false;
			for (int k=1; k<=que; k++) if (ch[k]==j){
				f1 = true;
				f2|= (Q[k-1]==0);
			}
			if (f1^f2)
				bad = true;
		}
		if (!bad)
			ret = (ret + ans.mat[i][0]) % mod; 
	}
	cout << ret << endl;

	cerr << endl << endl << fixed << setprecision(3) << "TIME : " << (clock()-start+0.0)/CLOCKS_PER_SEC << endl;
	return 0;
}