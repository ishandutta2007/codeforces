#include "bits/stdc++.h"
using namespace std;
char Str[2][1000005];
vector<int> Graph[1000005] , Path;
bool Visited[1000005];
int Record[1000005] , Max;
 
void AddEdges( int N , int m , int index ){
    int i , pre = ( index - 1 ) * m;
 
    for( i = 0 ; i < m ; ++i ){
        if( Str[index & 1][i] == '.' ){
            if( Str[(index + 1) & 1][i] == '.' ) Graph[pre + i + 1].emplace_back( pre + m + i + 1 );
            if( i < m - 1 && Str[index & 1][i + 1] == '.' ) Graph[pre + i + 1].emplace_back( pre + i + 2 );
        }
    }
 
    if( index == N - 1 ){
        pre += m;
        ++index;
 
        for( i = 0 ; i < m - 1 ; ++i ){
            if( Str[index & 1][i] == '.' && Str[index & 1][i + 1] == '.' )
                Graph[pre + i + 1].emplace_back( pre + i + 2 ); 
        }
    }
}
 
void FindPath( int root , int end ){   
    Visited[root] = true;
    Path.emplace_back( root );
    if( root == end ) return;
 
    for( int i = 0 ; i < int(Graph[root].size()) ; ++i ){
        if( Visited[Graph[root][i]] == false ){
            FindPath( Graph[root][i] , end );
            if( Visited[end] == true ) return;
        }
    }
 
    Path.pop_back();
}
 
bool IsAlternativePath( int root , int end ){
    Visited[root] = true;
 
    for( int i = 0 ; i < int(Graph[root].size()) ; ++i ){
        if( Graph[root][i] == end ) return true;
        else if( Visited[Graph[root][i]] == false ){
            if( IsAlternativePath( Graph[root][i] , end ) ) return true;
        }
    }
 
    return false;
}
 
void dfs( int root ){
    if( root != 1 ) Record[root] = -2;
 
    for( int i = 0 ; i < int(Graph[root].size()) ; ++i ){
        if( Record[Graph[root][i]] >= 0 ) Max = max( Max , Record[Graph[root][i]] );
        else if( Record[Graph[root][i]] == -1 ){
            dfs( Graph[root][i] );
        }
    }
}
 
int main(){
    int N , m , i;
    scanf( "%d%d" , &N , &m );
    scanf( "%s" , Str[1] );
 
    for( i = 2 ; i <= N ; ++i ){
        scanf( "%s" , Str[i & 1] );
        AddEdges( N , m , i - 1 ); 
    }
 
    if( N == 1 ){ 
        for( i = 0 ; i < m - 1 ; ++i ){
            if( Str[1][i] == '.' && Str[1][i + 1] == '.' ) Graph[i + 1].emplace_back( i + 2 );
        }
    }
 
    FindPath( 1 , N * m );
 
    if( Visited[N * m] == false ){
        puts( "0" );
        return 0;
    }
 
    if( N == 1 || m == 1 ){
        puts( "1" );
        return 0;
    }
 
    fill( Visited , Visited + N * m + 1 , false );
 
    for( i = 0 ; i < int(Path.size()) ; ++i )
        Visited[Path[i]] = true;
 
    if( IsAlternativePath( 1 , N * m ) ){ 
        puts( "2" );
        return 0;
    }
    
    fill( Record , Record + m * N + 1 , -1 );
 
    for( i = 0 ; i < int(Path.size()) ; ++i )
        Record[Path[i]] = i;
    
    Max = 0;
 
    for( i = 0 ; i < int(Path.size()) ; ++i ){
        if( i > 0 && Max <= i ){
            puts( "1" );
            return 0;
        }
 
        dfs( Path[i] );
    }
 
    puts( "2" );
    return 0;
}