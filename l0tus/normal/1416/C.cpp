#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 9e6+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN],L[MN],R[MN],num[MN],cnt;
ll a[MN],b[MN];

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
    	cin >> A[i];
    	int pos = 0;
    	for(int x=29; x>=0; x--){
    		if(A[i]&(1<<x)){
    			if(!R[pos]) R[pos] = ++cnt;
    			if(L[pos]) b[x] += num[L[pos]];
    			pos = R[pos];
    			num[pos]++;
    		}
    		else{
    			if(!L[pos]) L[pos] = ++cnt;
    			if(R[pos]) a[x] += num[R[pos]];
    			pos = L[pos];
    			num[pos]++;
    		}
    	}
    }
    int ans = 0;
    ll sum = 0;
    for(int x=29; x>=0; x--){
    	sum += min(a[x],b[x]);
    	if(a[x]<=b[x]) continue;
    	ans += (1<<x);
    }
    cout << sum << ' ' << ans;
}