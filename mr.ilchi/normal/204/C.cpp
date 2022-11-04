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

#define double long double

const int MAXA = 26 + 5;
const int MAXN = 100 * 1000 + 10;

int len;
int del[MAXA][MAXN];
int cnt[2][MAXA][MAXN];
string A,B;
vector <int> q1[MAXA],q2[MAXA];

int main(){
	cin >> len;
	cin >> A >> B;
	for (int i=0; i<len; i++) q1[A[i]-'A'].push_back(i);
	for (int i=0; i<len; i++) q2[B[i]-'A'].push_back(i);
	double ans = 0;
	for (int i=0; i<26; i++){
		ll poi = 0, sum1=0, sum2=0;
		for (int j=0; j<(int)q2[i].size(); j++)
			sum2+= len-q2[i][j];
		for (int j=0; j<(int)q1[i].size(); j++){
			while (poi<(int)q2[i].size() && q2[i][poi]<=q1[i][j]){
				sum2-=(len-q2[i][poi]);
				sum1+=q2[i][poi]+1;
				poi++;
			}
			ans+= (double)(len-q1[i][j]) * sum1 + (double)(q1[i][j]+1) * sum2;
		}
	}
	double sum = 0;
	for (int i=1; i<=len; i++)
		sum+= (double)(len-i+1) * (len-i+1);
	cout << fixed << setprecision(10) << ans/sum << endl;
	return 0;
}