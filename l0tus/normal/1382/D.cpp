#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;

vector<int> key;
bool dp[4005][2005];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	key.clear();
    	int head = 0, cur, len = 0;
    	for(int i=0; i<2*n; i++){
    		if(!head){
    			cin >> head;
    			len = 1;
    		}
    		else{
    			cin >> cur;
    			if(cur>head){
    				key.push_back(len);
    				head = cur;
    				len = 1;
    			}
    			else len++;
    		}
    	}
    	key.push_back(len);
    	//for(int x:key) cout << x << ' ';
    	dp[2*n][0] = 1;
    	for(int i=2*n-1; i>=0; i--){
    		for(int k=0; k<=n; k++){
    			if(i<key.size()&&k>=key[i])
    			 	dp[i][k] = dp[i+1][k-key[i]]|dp[i+1][k];
    			else
    				dp[i][k] = dp[i+1][k];
    		}
    	}
    	cout << (dp[0][n] ? "YES\n" : "NO\n");
    	for(int i=0; i<=2*n; i++){
    		for(int k=0; k<=n; k++){
    			dp[i][k] = 0;
    		}
    	}
    }
}