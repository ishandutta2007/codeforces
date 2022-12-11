#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int dx[4] = { 0, 0, 1,-1 };
int dy[4] = { 1,-1, 0, 0 };
int n, m;
vector< char > ac;
vector< pair< int, int > > av;
bool used[ 505 ][ 505 ];
char st[ 505 ][ 505 ];

void add( char c, int a, int b )
{
     ac.push_back( c );
     av.push_back( make_pair( a + 1, b + 1 ) );
}

void dfs( int i, int j, int fl )
{
     used[i][j] = true;
     add( 'B', i, j );
     for ( int k = 0; k < 4; k++ )
     {
         int ii = i + dx[k];
         int jj = j + dy[k];
         if ( ii < 0 || ii >= n ) continue;
         if ( jj < 0 || jj >= m ) continue;
         if ( st[ii][jj] == '#' || used[ii][jj] ) continue;
         dfs( ii, jj, 1 );
     }
     if ( fl == 1 )
     {
          add( 'D', i, j );
          add( 'R', i, j );     
     }
}

int main()
{
    scanf("%d%d\n", &n, &m);
    for ( int i = 0; i < n; i++ ) gets( st[i] );
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
        {
            if ( st[i][j] == '#' ) continue;
            if ( used[i][j] ) continue;
            dfs( i, j, 0 );
        }
    cout << ac.size() << endl;
    for ( int i = 0; i < ac.size(); i++ ) printf("%c %d %d\n", ac[i], av[i].first, av[i].second);
    return 0;
}