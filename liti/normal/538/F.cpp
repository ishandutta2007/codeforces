//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define SZ(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2*1000*100 + 100; 

int a[maxN];
int main() { 
    int n;
    scanf( "%d" , &n ) ;
    int tmp = 0;
    for( int i = 1 ; i <= n ; i++ ) 
	scanf("%d" , a + i );

    int ans = 0 ; 
    for( int i = 2 ; i <= n ; i++ ) 
	if( a[i-1] > a[i] ) 
	    ans++;
    printf("%d " ,ans ) ;
    for( int k = 2 ; k < n ; k++ ) { 
	int t = 0;
	for( int i = 0 ; i <= n - 2 ; i += k - 1 ) {
	    int st = i , en = min(i + k - 1 , n - 1) ; 
	    en = min( en , t * k ) ; 
	    for( int j = st ; j < en ; j++ ) {
		int id = j + 2; 
		int x=  j / (k-1);
		int y = j / k;
	//	cout << endl << id << ' ' << x + 1 << ' ' << y + 1  << endl;
		if( a[x+1] > a[id] ) ans--;
		if( a[y+1] > a[id] ) ans++;
	    }
	    t++;
	}
	printf("%d " , ans);
    }
}