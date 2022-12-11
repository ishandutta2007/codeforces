#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 1e7+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN],S[MN];
bool ch[MN],sel[MN];

int N;
ll sum;

void act(int x)
{
	if(sel[x]||sel[(x+N-1)%(2*N)+1]) return;
	sel[x] = 1;
	ch[A[x]] = 1;
	sum += x;
	act((S[A[x]]-x+N-1)%(2*N)+1);
}

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> N;
    if(N%2==0){
    	cout << "First\n";
    	cout.flush();
    	for(int i=1; i<=2*N; i++) cout << (i+N-1)%N+1 << ' ';
    	cout << '\n';
    	cout.flush();
    }
    else{
    	cout << "Second\n";
    	cout.flush();
    	for(int i=1; i<=2*N; i++){
    		cin >> A[i];
    		S[A[i]] += i;
    	}
    	for(int i=1; i<=N; i++){
    		act(i);
    	}
    	if(sum%(2*N)==0){
    		for(int i=1; i<=2*N; i++){
    			if(sel[i]) cout << i << ' ';
    		}
    	}
    	else{
    		for(int i=1; i<=2*N; i++){
    			if(!sel[i]) cout << i << ' ';
    		}    		
    	}
    	cout << '\n';
    	cout.flush();
    }

}