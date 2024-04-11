//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld;
typedef pair<int,int> Que;

const ld eps = 1e-9;
const int maxN = 1000*100 + 100; 
const int maxQ = 5000 +10;
int a[maxN]; 
int mx[4*maxN];
int n;
void make_tree( int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) {
		mx[ind] = a[xl];
		return;
	}
	int xm = (xl+xr)>>1;
	make_tree(xl,xm,ind*2);
	make_tree(xm,xr,ind*2+1);
	mx[ind] = max(mx[ind*2],mx[ind*2+1]);
}
int get(int ql, int qr, int xl = 0 , int xr = n , int ind = 1 ) {
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) return mx[ind];
	int xm = (xl+xr)>>1;
	return max(get(ql,qr,xl,xm,ind*2),get(ql,qr,xm,xr,ind*2+1));
}

ld p[maxQ];
Que que[maxQ];
int mm[maxQ];
ld val[maxQ][maxQ];
int ord[maxQ];

inline bool cmp(int a, int b) {
	if( que[a].second == que[b].second ) 
		return que[a].first > que[b].first;
	return que[a].second < que[b].second;
}

int m;
int gg(int i ,int j , int k ){ 
	int diff = mm[i]-mm[j];
	assert( diff >= 0 ) ; 
	return min( k + diff , m ) ;
}

int main() { 
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++) {
		cin >> que[i].first >> que[i].second >> p[i];
		que[i].first--;
		ord[i] = i;
	}
	make_tree();
	ord[m] = m;
	que[m++] = {0,n};
	sort(ord,ord+m-1,cmp);	
	vector<int> curr;
	for( int i = 0 ; i < m ; i++ ) {
		int x = ord[i];
		mm[x] = get(que[x].first,que[x].second);
		vector<int> childs;
		while(curr.size()&&que[curr.back()].first >= que[x].first) {
			childs.push_back(curr.back());
			curr.pop_back();
		}
		for( int k = 0 ; k <= m ; k++ ) {
			ld tmp = (1-p[x]);
			for( int j = 0 ; j < __sz(childs) ; j++ ) 
				tmp *= val[childs[j]][gg(x,childs[j],k)];
			val[x][k] += tmp;
			if( k == 0 ) continue;
			tmp = p[x];
			for( int j = 0 ; j < __sz(childs) ; j++ ) 
				tmp *= val[childs[j]][gg(x,childs[j],k-1)];
			val[x][k] += tmp;
		}
		curr.push_back(x);
	}
	m--;
	ld ans = mm[m] * val[m][0];
	for( int i = 1 ;i <= m ; i++ ) 
		ans += ( val[m][i] - val[m][i-1] ) * ( mm[m] + i ) ; 
	cout << fixed << setprecision(9) << ans << endl;
}