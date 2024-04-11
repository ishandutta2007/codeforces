/* In the name of Allah */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n= 100*100*10 + 10;
typedef long long ll;

//Global
int n,L,W;
//Tree 
vector<pair<int,int> > c[max_n]; //List of neighbors


//Centroid finding
int sz[max_n]; //size of subtree
bool used[max_n]; //vert used as centroid

int set_size( int s , int par ) { 
	sz[s] = 1;
	for( auto node : c[s] ) 
		if( node.first != par && !used[node.first] ) 
			sz[s] += set_size( node.first, s ) ;
	return sz[s];
}

int find_centroid( int s ) { 
	set_size( s , -1 ) ; 

	int t_size = sz[s] ;

	while( 1 ) { 
		bool f = false;
		for( auto node : c[s] ) 
			if( !used[node.first] && sz[node.first] > t_size/2 ) {
				sz[s] = t_size - sz[node.first]; //will work or not ?! :D
				s = node.first;
				f = true;
				break;
			}
		if( !f ) 
			break;
	}
	used[s] = true;

	return s;
}

//Solving Problem
pair<int,int> dist[max_n]; // distance (weight and length) of centroid
vector< pair<int,int> > seq[max_n], tmp; // Seq of sorted vertices in subtree 

//Fenwick
int fen[max_n]; //Sum of path's (used for two pointer)

void f_add( int x , int val ) { 
	x++;
	for( ; x < max_n ; x += (-x)&x )
		fen[x] += val;
}

int f_get( int x ) { // from 1 ... x
	x++;
	int res = 0 ; 
	for( ; x > 0 ; x -= (-x)&x ) 
		res += fen[x];
	return res;
}

ll ans; //Stores double of ans

void make_list( int s , int par , int idx , int val, int h ) { 
	seq[idx].push_back( make_pair( val , h ) ) ; 

	for( auto node : c[s] ) 
		if( node.first != par && !used[node.first] ) 
			make_list( node.first, s , idx, val + node.second, h + 1 ) ; 
}

void two_pointer( const vector< pair<int,int> >& seq , int z ) {
	int l = (int)seq.size() - 1 ; 

//	cerr << "BEGIN " << endl;

	for( int i = 0 ; i < (int)seq.size() ; i++ ) {
		while( l != -1 && seq[l].first + seq[i].first <= W ) {
			f_add( seq[l].second, 1 ) ; 
			l--;
		}
		
//		cerr << seq[i].first << ' ' << seq[i].second << ' ' << f_get( L - seq[i].second ) << endl;
		ans += 1LL*z*f_get( L - seq[i].second ) ; 
	}

	for( int i = l + 1 ; i < (int)seq.size() ; i++ ) 
		f_add( seq[i].second, -1 ) ; 
	
//	cerr << "END " << endl;
}

void solve( int s ) { 
	s = find_centroid( s ) ;

	seq[s].push_back( make_pair( 0, 0 ) ) ; 
	two_pointer( seq[s] , -1 ) ;
	for( auto node : c[s] ) 
		if( !used[node.first] ) {
			make_list( node.first , s , node.first, node.second , 1  ) ; 
			sort( seq[node.first].begin() , seq[node.first].end(), greater<pair<int,int> >() ) ;
			two_pointer( seq[node.first] , -1 ) ; 

			if( seq[node.first].size() > seq[s].size() ) 
				seq[s].swap( seq[node.first] ) ; 
			seq[s].swap( tmp ) ; 
			seq[s].clear();
			merge( tmp.begin() , tmp.end() ,
					seq[node.first].begin() , seq[node.first].end(),
					back_inserter( seq[s] ), greater<pair<int,int> >() ) ;
		}
//	cerr << "SZ " << seq[s].size() << endl;
	two_pointer( seq[s] , 1 ) ; 

//	cout << "start " <<s << ' ' << ans << endl;
	
	seq[s].clear();
	for( auto node : c[s] ) 
		seq[node.first].clear();

	for( auto node : c[s] ) 
		if( !used[node.first] ) 
			solve( node.first ) ;

//	cout << "end " << s << endl;
}


int main() { 
	cin >> n >> L >> W;

	for( int i = 1 ; i < n; i++ ) { 
		int p , w;
		cin >> p >> w;
		p--;

		c[p].push_back( make_pair ( i , w ) ) ; 
		c[i].push_back( make_pair ( p , w ) ) ; 
	}

	solve( 0 ) ; 

	cout << ans/2 << endl;
}