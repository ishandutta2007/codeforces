//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 
typedef pair<pii,int> Seg; 

struct cmp1 { 
	bool operator()( const Seg& a , const Seg& b ) { 
		if( a.first.first == b.first.first ) 
			return a.first.second > b.first.second;
		return a.first.first < b.first.first;
	}
};
struct cmp2 { 
	bool operator()( const Seg& a , const Seg& b ) { 
		if( a.first.second == b.first.second ) 
			return a.first.first < b.first.first;
		return a.first.second > b.first.second;
	}
};
inline void smin( int& a , int b ) { 
	a = min(a,b); 
}
inline void smax( int& a , int b ) { 
	a = max(a,b); 
}


const int maxN = 1000*100 + 100; 
int par[maxN];
inline int gg( int s ) { 
	return par[s] == -1 ? s : par[s] = gg( par[s] ); 
}

pii a[maxN];
set<Seg,cmp1> currL,currT; //Top 
set<Seg,cmp2> currR;

inline void rem( int i ) { 
	Seg s( pii( a[i].first , a[i].second ) , i ) ; 
	currL.erase( s ); 
	currR.erase( s ) ; 
	currT.erase( s ) ; 
}

inline void add( int i ) { 
	Seg s( pii( a[i].first , a[i].second ) , i ) ; 
	currL.insert( s ); 
	currR.insert( s ) ; 
	currT.insert( s ) ; 
}

inline void merge( int u , int v ) { //merge u into v
	smin( a[v].first , a[u].first ); 
	smax( a[v].second , a[u].second ); 
	par[gg(u)] = v; 
	rem( u ); 
}


int main() { 
	memset( par , -1 , sizeof par ); 
	ios::sync_with_stdio(false); cin.tie(0); 

	int n; cin >> n;  
	int cnt = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int l,r; cin >> l >> r; 
			a[cnt] = {l,r}; 
			
			Seg search( pii(l,int(1e9+100)) , -1 ) ; 
			while( 1 ) { 
				auto it = currL.lower_bound( search ); 
	//			if( it != currL.end() ) 
	//				cerr << "____ " << it->first.first << ' ' << it->first.second << endl;
				if( it == currL.end() || it->first.first >= r ) break;
				if( it->first.second <= r ) { 
					currT.erase( *it ); 
					search = Seg( pii( it->first.second , int(1e9+100) ) , -1 ); 
				} else 
					merge( it->second , cnt ); 
			}
			search = Seg( pii(int(-1e9-100),r) , -1 ) ; 
			while( 1 ) { 
				auto it = currR.lower_bound( search ); 
				if( it == currR.end() || it->first.second <= l ) break;
				if( it->first.first >= l ) 
					search = Seg( pii( int(-1e9-100) , it->first.first ) , -1 ); 
				else 
					merge( it->second , cnt ); 
			}
			auto it = currT.lower_bound( Seg(pii( l+1 , 0 ) , -1) ); 
			if( it != currT.begin() && (--it)->first.first <= l && it->first.second >= r )
				merge( it->second , cnt ); 
//			cerr << "!! " << a[cnt].first << ' ' << a[cnt].second << endl;
			add( cnt++ ) ; 
		} else { 
			int u,v; cin >> u >> v;
			u--; v--; 
			int pu = gg(u) ;
			int pv = gg(v);
			if(  pu == pv || ( a[pv].first <= a[pu].first && a[pu].second <= a[pv].second )  ) 
				cout << "YES\n"; 
			else
				cout << "NO\n"; 
		}
	//	for( auto x : currT ) 
	//		cerr << i << "!! " << x.first.first << ' ' << x.first.second << endl;
	}
}