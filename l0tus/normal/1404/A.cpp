#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    int T;
    cin >> T;
    while(T--){
    	int N,K;
    	string S;
    	cin >> N >> K >> S;
    	if(K%2){
    		cout << "NO\n";
    		continue;
    	}
    	vector<int> C(K);
    	bool fail = 0;
    	for(int i=0; i<K; i++) C[i] = -1;
    	for(int i=0; i<S.size(); i++){
    		if(S[i]=='1'){
    			if(C[i%K]==0) fail = 1;
    			C[i%K] = 1;
    		}
    		if(S[i]=='0'){
    			if(C[i%K]==1) fail = 1;
    			C[i%K] = 0;
    		}
    	}
    	int a=0, b=0, c=0;
    	for(int i=0; i<K; i++){
    		if(C[i%K]==0) a++;
    		else if(C[i%K]==1) b++;
    		else c++;
    	}
    	if(abs(a-b)>c) fail = 1;
    	if(fail) cout << "NO\n";
    	else cout << "YES\n";
    }
}