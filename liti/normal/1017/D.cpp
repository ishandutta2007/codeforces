//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii;

const int maxN = 12; 
const int maxM = 5000 * 100 + 100;
const int maxS = (1<<maxN);

int cnt[maxS];

int diff[maxS]; 

int w[maxN];

vector<pii> a[maxS];

int ans[maxM];

int buck[105];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int n, m, q;
    cin >> n >> m >> q; 

    for(int i = 0; i < n; i++)
        cin >> w[i];

    for(int mask = 0; mask < (1<<n); mask++) 
        for(int j = 0; j < n; j++) 
            if( ( (mask>>j) & 1 ) == 0 ) 
                diff[mask] += w[j]; 

    for(int i = 0; i < m; i++) { 
        string s;
        cin >> s;
        int x = 0;
        for(int j =0 ; j < n; j++) 
            if( s[j] == '1' ) 
                x |= (1<<j);
        cnt[x]++;
    }
    
    for(int i = 0; i < q; i++) { 
        string s; 
        int k;
        cin >> s >> k;
        int x = 0;
        for(int j =0 ; j < n; j++) 
            if( s[j] == '1' ) 
                x |= (1<<j);
        a[x].push_back({k,i});
    }

    for(int mask = 0; mask < (1<<n); mask++) 
        if( a[mask].size() ) { 
            sort( a[mask].begin(), a[mask].end() ); 

            for(int i = 0; i < 105; i++)
                buck[i] = 0; 

            for(int x = 0; x < (1<<n); x++) 
                if( cnt[x] && diff[x^mask] < 105 )
                    buck[ diff[x^mask] ] += cnt[x];

            int i = 0; 
            int sum = 0;
            for(int j = 0; j < int(a[mask].size()); j++) { 
                while( i <= a[mask][j].first ) {
                    sum += buck[i];
                    i++;
                }
                ans[ a[mask][j].second ] = sum;
            }
        }


    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}