//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 200*10000; 
int isp[maxN];
int val[maxN];

inline bool ispal( int i ) { 
	int num = i; 
	int b = 0;
	for( ; i ; i /= 10 ) 
		b = b * 10 + i % 10; 
	return num == b;
}

int main() { 
	isp[1] = 1;
	for( int i = 2 ; i < maxN ; i++ ) if( !isp[i] ) 
		for( int j = min(1ll*maxN,ll(i)*i) ; j < maxN ; j += i ) isp[j] = 1; 
	for( int i = 1 ; i < maxN ; i++ ) 
		isp[i] = 1-isp[i] + isp[i-1];
	for( int i = 1 ; i < maxN ; i++ ) 
		val[i] = val[i-1] + ispal(i);
	int p,q; cin >> p >> q;
	int mx = 0;
	for( int i = 1 ; i < maxN ; i++ ) 
		if( q * isp[i] <= p * val[i] ) mx = i;
	if( mx == maxN - 1 ) cout << "Palindromic tree is better than splay tree" << endl;
	else cout << mx << endl;
}