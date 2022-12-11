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
    	int N;
    	cin >> N;
    	vector<char> A(N);
    	for(int i=0; i<N; i++){
    		cin >> A[i];
    	}
    	char head = A[0];
    	int len=0;
    	vector<int> B;
    	for(int i=0; i<N; i++){
    		if(A[i]==head) len++;
    		else{
    			B.push_back(len);
    			head = A[i];
    			len = 1;
    		}
    	}
    	int ans = 0;
    	if(B.size()==0){
    		ans = (len+2)/3;
    	}
    	else{
    		if(B.size()%2) B.push_back(len);
    		else B[0] += len;
    		for(int x:B){
    			ans += x/3;
    		}
    	}
    	cout << ans << '\n';
    }
}