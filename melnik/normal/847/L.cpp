#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 3e2 + 10;

vector < set < int > > a[1050];
vector < set < int > > b[1050];
vector < set < int > > c;
set < int >::iterator it, it1, it2;
int used[1050];
set < int > cur;
vector < int > edge[1050];

void bad() {
    puts( "-1" );
    exit( 0 );
}


void dfs( int v, int anc, int num ) {
    int it = 0;
    for ( int to : edge[v] ) {
        if ( to == anc )
            continue;
        if ( anc == -1 ) {
            c[it].insert( to );
            dfs( to, v, it );
        }
        else {
            c[num].insert( to );
            dfs( to, v, num );
        }
        ++it;
    }
}

bool cmp( set < int > &x1, set < int > &x2 ) {
    return *x1.begin() < *x2.begin();
}

void correct( int n ) {
    for ( int j = 1; j <= n; j++ ) {
        c.clear();
        cur.clear();
        for ( int i = 0; i < edge[j].size(); i++ )
            c.push_back( cur );
        dfs( j, -1, -1 );

        sort( c.begin(), c.end(), cmp );
        sort( b[j].begin(), b[j].end(), cmp );

        if ( b[j].size() != c.size() )
            bad();

        int sz = c.size();
        for ( int i = 0; i < sz; i++ ) {
            if ( c[i].size() != b[j][i].size() )
                bad();
            for ( it1 = c[i].begin(), it2 = b[j][i].begin(); it1 != c[i].end(); it1++, it2++ )
                if ( *it1 != *it2 )
                    bad();
        }
    }
}

void dfs( int v, int anc ) {
    used[v] = true;
    for ( int to : edge[v] ) {
        if ( to == anc )
            continue;
        if ( used[to] )
            bad();
        dfs( to, v );
    }
}


int main() {
//    freopen( "input.txt", "r", stdin );
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n; j++ ) {
        while ( true ) {
            cur.clear();
            int cnt;
            scanf ( "%d:", &cnt );
            for ( int j = 0; j < cnt; j++ ) {
                int v;
                scanf ( "%d", &v );
                cur.insert( v );
                if ( j + 1 != cnt )
                    scanf ( "," );
            }
            a[j].push_back( cur );
            b[j].push_back( cur );
            char t;
            scanf( "%c", &t );
            if ( t != '-' )
                break;
        }
    }

//    for ( int j = 1; j <= n; j++ ) {
//        int sz = a[j].size();
//        for ( int i = 0; i < sz; i++ ) {
//            for ( it = a[j][i].begin(); it != a[j][i].end(); it++ )
//                printf( "%d ", *it );
//            printf( " | " );
//        }
//        printf( "\n" );
//    }
//    return 0;

    for ( int j = 1; j < n; j++ ) {
        int leaf = -1;
        for ( int i = 1; i <= n; i++ ) {
            if ( used[i] )
                continue;
            int sz = a[i].size();
            int sumSize = 0;
            for ( int y = 0; y < sz; y++ )
                sumSize += !a[i][y].empty();
            if ( sumSize == 1 ) {
                leaf = i;
                break;
            }
        }
//        cout << leaf << endl;

        int v = -1;
        for ( int i = 1; i <= n; i++ ) {
            if ( used[i] )
                continue;
            int sz = a[i].size();
            for ( int y = 0; y < sz; y++ )
                if ( a[i][y].size() == 1 && *a[i][y].begin() == leaf ) {
                    v = i;
                    break;
                }
            if ( v != -1 )
                break;
        }
//        cout << v << endl;

//        cout << v << ' ' << leaf << endl;
        used[leaf] = 1;

        edge[leaf].push_back( v );
        edge[v].push_back( leaf );

        for ( int i = 1; i <= n; i++ ) {
            int sz = a[i].size();
            for ( int y = 0; y < sz; y++ )
                a[i][y].erase( leaf );
        }

        if ( v == -1 || leaf == -1 )
            bad();
    }
    for ( int j = 0; j < 1050; j++ )
        used[j] = 0;
    dfs( 1, 0 );
    for ( int j = 1; j <= n; j++ )
        if ( !used[j] )
            bad();

    correct( n );

    printf( "%d\n", n - 1 );
    for ( int j = 1; j <= n; j++ )
        for ( int to : edge[j] )
            if ( to < j )
                printf( "%d %d\n", to, j );
}