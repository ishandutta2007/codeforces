#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 3005;
const int MOD = 998244353;

int D[MN][MN],ans;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    string S,T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    for(int j=0; j<N; j++){
    	for(int i=0; i+j<N; i++){
    		if(j==0){
    			if(i>=M||S[0]==T[i]) D[i][i+j] = 2;
    			continue;
    		}
    		if(i>=M||S[j]==T[i]) D[i][i+j] = (D[i][i+j]+D[i+1][i+j])%MOD;
    		if(i+j>=M||S[j]==T[i+j]) D[i][i+j] = (D[i][i+j]+D[i][i+j-1])%MOD;
    	}
    }
    for(int i=M-1; i<N; i++){
    	ans = (ans+D[0][i])%MOD;
    }
    cout << ans;
}