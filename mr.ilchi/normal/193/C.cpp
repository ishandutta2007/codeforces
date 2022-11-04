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

int dif[10][10];

void BAD (bool f){
	if (f){
		cout << -1 << endl;
		exit(0);
	}
}

int main(){

	for (int i=1; i<=4; i++)
		for (int j=i+1; j<=4; j++)
			cin >> dif[i][j];

//	sec1 + sec2 = dif[1][2];
//	sec1 - sec2 = dif[2][3] - dif[1][3]
	int sec1 = (dif[1][2] + dif[2][3] - dif[1][3]); BAD(sec1%2 || sec1<0); sec1/=2;
	int sec2 = (dif[1][2] - sec1); BAD(sec2<0); 
	int sec3 = dif[1][3] - sec2; BAD(sec3<0); 

	int len=-1,c1a=0,c2a=0,c3a=0;

	for (int i=0; i<=sec3; i++) if (i<=dif[3][4] && sec3-i<=dif[1][4] && sec3-i<=dif[2][4]){
	
		int d1 = dif[1][4] - sec3 + i;
		int d2 = dif[2][4] - sec3 + i;
		int d3 = dif[3][4] - i;

//		cnta + cntb = dif[1][2]; 
//		cnta - cntb = dif[2][4] - dif[1][4];
		int cnta = dif[1][2] + dif[2][4] - dif[1][4]; BAD(cnta%2 || cnta<0); cnta/=2;
		int cntb = dif[1][2] - cnta; BAD(cntb<0);

//		cnt1a + cnt1b = sec1;
// 		cnt1a - cnt1b = d2 - d3; 
		int cnt1a = sec1 + d2 - d3; if (cnt1a<0 || cnt1a%2) continue; cnt1a/=2;
		int cnt1b = sec1 - cnt1a; if (cnt1b<0) continue;

		int cnt2a = cnta - cnt1a; if (cnt2a<0) continue;
		int cnt2b = cntb - cnt1b; if (cnt2b<0) continue;

		d1-= cntb; d2-= cnta; d3-= cnt1b + cnt2a;
		if (d1!=d2 || d1!=d3 || d1<0) 
			continue;


		if (sec1 + sec2 + sec3 + d1 < len || len == -1){
			len = sec1 + sec2 + sec3 + d1;
			c1a = cnt1a;
			c2a = cnt2a;
			c3a = i;
		}
	}

	BAD(len==-1);

	cout << len << endl;

	string s1,s2,s3,s4;

	s1 = string(len,'a');
	s2 = string(dif[1][2],'b') + string(len-dif[1][2],'a');
	s3 = string(sec1,'a') + string(sec2+sec3,'b') + string(len-sec1-sec2-sec3,'a');
	s4 = string(c1a,'a') + string(sec1-c1a,'b') +
		 string(c2a,'a') + string(sec2-c2a,'b') + 
		 string(c3a,'a') + string(sec3-c3a,'b') + 
		 string(len-sec1-sec2-sec3,'b');

	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;

	return 0;
}