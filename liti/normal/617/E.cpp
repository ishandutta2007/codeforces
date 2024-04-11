#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 100;
const int S = 317;

#define int long long
int a[MAXN] , ans , px[MAXN] , res[MAXN] , k , mp[MAXN] ;

struct Q{ int r , l ; } ;	
pair< Q , int > p[MAXN];

bool cmp(pair< Q , int > A , pair< Q , int > B){
	if(A . first . l / S != B . first . l / S)
		return A . first . l < B . first . l ;
	return A . first . r > B . first . r;
}

void ins(int n){ ans += mp[n ^ k] ; mp[n] ++ ;}
void del(int n){ mp[n] -- ; ans -= mp[n ^ k] ;}

int32_t main(){
	int n , m ;	cin >> n >> m >> k ;
	for(int i = 0 ; i < n ; i ++ )cin >> a[i] ;
	for(int i = 0 ; i < n ; i ++ )px[i + 1] = px[i] ^ a[i] ;
	for(int i = 0 ; i < m ;i ++){
		cin >> p[i] . first . l >> p[i] . first . r ;
		p[i] . second = i ;	p[i] . first . l -- ;
	}
	sort(p , p + m , cmp) ;	
	int l = 0 , r = 0 ;
	for(int i = 0 ; i < m ; i ++ ){
		int ql = p[i] . first . l ;
		int qr = p[i] . first . r + 1 ;
		while(l > ql)	ins(px[-- l]) ;
		while(r < qr)	ins(px[r ++]) ;
		while(l < ql)	del(px[l ++]) ;
		while(r > qr)	del(px[-- r]) ;
		res[p[i] . second] = ans ;
	}
	for(int i = 0 ; i < m ; i ++ )cout << res[i] << '\n' ;
}