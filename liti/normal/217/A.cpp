#include <bits/stdc++.h>

using namespace std;

const int maxN = 100 + 10;

pair<int, int> a[maxN];
vector<int> c[maxN];
bool check[maxN];

void dfs( int node ) 
{
    check[node] = true;
    
    for(int i = 0 ; i < c[node].size() ; i++ ) 
        if( !check[ c[node][i] ] ) 
            dfs( c[node][i] ) ;
}


int main()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ;i ++ )
        cin >> a[i].first >> a[i].second ; 

    for(int i = 0 ; i < n ;i++ )
        for(int j =0 ; j < n ; j++ ) 
            if( a[i].first == a[j].first || 
                    a[i].second == a[j].second ) 
                c[i].push_back(j); 

    int ans = -1;
    for(int i =0 ;  i < n ; i++ ) 
        if( !check[i] ) 
        {
            ans++;
            dfs(i);
        }
    cout << ans << endl;
}