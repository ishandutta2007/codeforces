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

    int N;
    cin >> N;
    ll A[26][26];
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++){
    		if(i+j==0) A[i][j] = 0;
    		else A[i][j] = (i%2==0) ? (1ll<<(i+j-1)) : 0;
    		cout << A[i][j] << ' ';
    	}
    	cout << '\n';
    	cout.flush();
    }
    int Q;
    cin >> Q;
    while(Q--){
    	ll X;
    	cin >> X;
    	cout << "1 1\n";
    	cout.flush();
    	int x=0, y=0;
    	for(int t=0; t<2*N-2; t++){
    		if(x==N-1){
    			y++;
    		}
    		else if(y==N-1){
    			x++;
    		}
    		else{
    			if(A[x+1][y]&&(A[x+1][y]&X)||A[x][y+1]&&!(A[x][y+1]&X)){
    				x++;
    			}
    			else y++;
    		}
    		cout << x+1 << ' ' << y+1 << '\n';
    		cout.flush();
    	}
    }
}