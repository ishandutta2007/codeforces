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
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

const int maxN = 200*1000 + 5;

int n;
int dp[maxN];
string a;
bool av[10][8]={{1,0,1,1,1,1,1},{0,0,0,1,1,0,0},{1,1,1,1,0,0,1},{1,1,1,1,1,0,0},{0,1,0,1,1,1,0},{1,1,1,0,1,1,0},{1,1,1,0,1,1,1},{1,0,0,1,1,0,0},{1,1,1,1,1,1,1},{1,1,1,1,1,1,0}};

int cnt(int a,int b){
	int res=0;
	for (int i=0;i<7;i++) if (av[a][i]==av[b][i] && av[a][i]==1)
		res++;
	return res;
}

inline void go (int pos , int r1){
	
	if (pos==n)
		return;

	if (pos<n/2){
		
		for (char ch = '0'; ch <= '9'; ch++){
			if (r1 + cnt(ch-'0',ch-'0') +  7 * (n/2-pos-1) > dp[n/2-1]){
				a[pos] = ch;
				break;
			}
		}

		r1+= cnt (a[pos]-'0' , a[pos]-'0');

		go (pos+1 , r1);

		return;
	}

	for (char ch='0'; ch<='9'; ch++) if ((r1-cnt(a[pos-n/2]-'0',a[pos-n/2]-'0')+cnt(ch-'0',a[pos-n/2]-'0'))>dp[n/2-1]){
	
		r1 = r1-cnt(a[pos-n/2]-'0',a[pos-n/2]-'0')+cnt(ch-'0',a[pos-n/2]-'0');

		a[pos] = ch;

		go (pos+1 , r1);

		return;
	}
}

int main(){
	
	freopen ("input.txt", "r" , stdin);
	freopen ("output.txt", "w" , stdout);

	cin >> a;

	n = (int)a.size();

	dp[0] = cnt (a[0]-'0' , a[n/2]-'0');

	for (int i=1 ; i<n/2; i++)
		dp[i] = dp[i-1] + cnt(a[i]-'0' , a[i+n/2]-'0');

	int  pos  = -1;
	char posv = -1;

	int inc = 0;

	for (int i=n-1; i>=n/2; i--){
		
		char tmp = a[i]; tmp++;

		while (tmp<='9'){
			
			if (cnt(tmp-'0',a[i-n/2]-'0') + inc> cnt(a[i]-'0',a[i-n/2]-'0')){
				pos = i;
				posv= tmp;
				break;
			}

			tmp++;
		}

		if (pos!=-1)
			break;

		inc+= cnt(a[i-n/2]-'0',a[i-n/2]-'0') - cnt(a[i]-'0',a[i-n/2]-'0');
	}

	if (pos!=-1){
		
		int r1=0;
		
		a[pos] = posv;
		
		for (int i=n/2; i<=pos; i++)
			r1+= cnt (a[i]-'0',a[i-n/2]-'0');
		for (int i=pos+1; i<n; i++)
			r1+= cnt (a[i-n/2]-'0' , a[i-n/2]-'0');

		go (pos+1,r1);
		
		cout << a << endl;
		return 0;
	}

	inc = 0;

	for (int i=0; i<n/2; i++)
		inc+= cnt(a[i]-'0',a[i]-'0');

	for (int i=n/2-1; i>=0; i--){
		
		char tmp = a[i]; tmp++;

		inc-= (cnt (a[i]-'0' , a[i]-'0'));

		while (tmp<='9'){
			
			if (inc + cnt(tmp-'0',tmp-'0') + 7 * (n/2-i-1) > dp[n/2-1]){
				pos = i;
				posv= tmp;
				break;
			}

			tmp++;
		}

		if (pos!=-1)
			break;
	}

	if (pos==-1){
		cout << -1 << endl;
		return 0;
	}

	int r1=0;

	a[pos] = posv;

	for (int i=0; i<=pos; i++)
		r1+= cnt(a[i]-'0',a[i]-'0');

	go (pos+1,r1);

	cout << a << endl;

	return 0;
}