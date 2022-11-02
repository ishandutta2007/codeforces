#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 1000*1000 + 10;

vector<int> c[maxN], comp;
bool check[maxN];

int dfs( int node )
{
    if( check[node] )
        return 0;
    int val = 1;
    check[node] = 1;
    for(int i =0; i< c[node].size() ; i++ )
        val += dfs( c[node][i] ) ;
    return val;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++ )
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        c[x].push_back(y);
        c[y].push_back(x);
    }

    for(int i =0; i< n ;i++ )
        if( !check[i] )
            comp.push_back( dfs(i) ) ;
    sort( comp.begin(), comp.end() ) ;
    reverse( comp.begin(), comp.end() ) ;

    if( comp.size() == 1 )
    {
        cout << 0 << endl;
        return 0;
    }
    if( k == 1 )
    {
        cout << comp.size() - 2 << endl;
        return 0;
    }

    int counter = 1;
    int ans = 0;
    for(int i =0;i < comp.size() ; i++ )
    {
        if( comp[i] == 0 )
            continue;
        if( counter >= comp.size() )
            break;
        int v = min( k, comp[i] ) - (i!=0);
     //   cout << i << ' ' << comp[i] << ' ' << v << endl;
        counter+=v;
        if( v == 0 )
        {
            ans ++;
            comp[i] += comp[counter];
            comp[counter] = 0 ;
            counter += 1 + min( k, comp[i] ) - ( i != 0 ) ;
        }
    }
    cout << ans << endl;
}