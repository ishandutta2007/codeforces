/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (((int) x.size()))
typedef long long ll;

const int maxN = 600;
int a[maxN];

string doJob( int x , string last ) { 
	int sz = x / 9 + (x%9!=0);
	string tmp = ""; for( int i = 0 ; i < x/9; i++ )  tmp += '9';
	if( x % 9 != 0 ) 
		tmp = char( x % 9 + '0' ) + tmp;
	if( sz > SZ(last) ) 
		return tmp;

	for( int i = 0 ; i < SZ(last) ; i++ ) 
		a[i] = last[i] - '0';
	a[SZ(last)] = 0;
	for( int i = SZ(last)-2 ; i>= 0 ; i-- ) 
		a[i] += a[i+1];

	int ss = a[0];
	for( int i = SZ(last) - 1 ; i >= 0 ; i-- ) {
		if( last[i] == '9' ) continue;
		int y = ss - a[i] + last[i] + 1 - '0';
		if( y <= x && (x-y) <= 9*(SZ(last) - 1 - i) + '9' - (last[i]+1) ) { 
			int plus = max(0,x-y - 9*(SZ(last) - 1 - i) );

			x -= plus;
			string ret = last.substr(0,i);
			ret += char(last[i]+1 + plus);

			int k = (x-y);
			string baghali = "";
			for( int j = 0 ; j < k/9 ; j++ ) 
				baghali += '9';
			if( k % 9 != 0 ) 
				baghali += char('0' + k % 9);
			while( SZ(baghali) != SZ(last) - 1 - i ) 
				baghali += '0';
			reverse(baghali.begin(),baghali.end());

	//		cout << ret << ' ' << baghali  << ' ' << k<< endl;
			ret += baghali;
			return ret;
		}
	}

	x--;
	tmp = "";
	if( x % 9 != 0 )
		tmp += char(x % 9 + '0');
	for( int i = 0 ; i < x/9 ; i++ ) tmp += '9';
	while( SZ(tmp) < SZ(last) ) tmp = "0" + tmp;
	tmp = "1" + tmp;
	return tmp;
}

int main() { 
	int n;
	cin >> n;
	string last = "";
	for( int i = 0 ; i < n ; i++ ) { 
		int x ; cin >> x; 
		last = doJob( x, last ) ;
		cout << last << endl;
	}
}