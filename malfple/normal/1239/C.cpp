//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define YOU using
#define DONT namespace
#define SAY std
 
YOU DONT SAY;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)
 
#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)
 
#define pb push_back
#define F first
#define S second
 
const int OO = 1e9;
const ll INF = 1e18;
 
const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}
 
const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}
 
#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;
 
	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}
 
inline void ini(int& x){
	x = getnum<int>();
}
 
inline void scani(int& x){
	scanf("%d",&x);
}
 
//end of macro
 
const int N = 1e5 + 5;
 
int n;
ll p;
vector<pii> vec;
 
int bitt[N];
void updateb(int x, int v){
	REPP(i,x,n,i&-i)bitt[i] += v;
}
int queryb(int x){
	int ret = 0;
	REVV(i,x,1,i&-i)ret += bitt[i];
	return ret;
}
 
int stree[4 * N];
void updates(int idx, int left, int right, int x, int v){
	if(left == right)stree[idx] += v;
	else{
		int mid = (left+right)/2;
		if(x <= mid)updates(idx<<1, left, mid, x, v);
		else updates(idx<<1|1, mid+1, right, x, v);
		stree[idx] = stree[idx<<1] + stree[idx<<1|1];
	}
}
 
int querys(int idx, int left, int right){
	if(stree[idx] == 0)return OO;
	if(left == right)return left;
	int mid = (left+right)/2;
	if(stree[idx<<1]){
		return querys(idx<<1, left, mid);
	}else{
		return querys(idx<<1|1, mid+1, right);
	}
}
 
ll cur;
queue<int>q;
 
ll ans[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
 
    cin>>n>>p;
    REP(i,1,n){
    	int t;
    	cin>>t;
    	vec.pb({t, i});
    }
    sort(vec.begin(), vec.end());
 
    REP(i,1,n)updateb(i, 1);
 
    int pv = 0;
    cur = 0;
    while(pv < vec.size() || q.size() > 0){
    	if(q.empty()){
    		assert(stree[1] == 0);
    		cur = vec[pv].F;
    		// printf("ff %lld\n",cur);
    	}else{
    		int now = q.front();
    		q.pop();
    		cur += p;
    		ans[now] = cur;
    		// printf("%d served at %d\n",now,cur);
    		
    		while(pv < vec.size() && vec[pv].F < cur){
	    		int now = vec[pv++].S;
	    		if(queryb(now-1) == now-1){
	    			// printf("%d immediately gets up\n",now);
	    			updateb(now, -1);
	    			q.push(now);
	    		}else{
	    			// printf("%d wait\n",now);
	    			updates(1, 1, n, now, 1);
	    		}
	    	}
    		
    		updateb(now, 1);
 
    		while(pv < vec.size() && vec[pv].F <= cur){
	    		int now = vec[pv++].S;
	    		if(queryb(now-1) == now-1){
	    			// printf("%d immediately gets up\n",now);
//	    			updateb(now, -1);
//	    			q.push(now);
	    			updates(1, 1, n, now, 1);
	    		}else{
	    			// printf("%d wait\n",now);
	    			updates(1, 1, n, now, 1);
	    		}
	    	}
	    	
	    	int cek = querys(1, 1, n);
    		if(cek <= n){
	    		if(queryb(cek-1) == cek-1){
	    			// printf("%d gets up\n",cek);
	    			updates(1, 1, n, cek, -1);
	    			updateb(cek, -1);
	    			q.push(cek);
	    		}
    		}
    	}
 
    	while(pv < vec.size() && vec[pv].F <= cur){
    		int now = vec[pv++].S;
    		if(queryb(now-1) == now-1){
    			// printf("%d immediately gets up\n",now);
    			updateb(now, -1);
    			q.push(now);
    		}else{
    			// printf("%d wait\n",now);
    			updates(1, 1, n, now, 1);
    		}
    	}
    }
 
    REP(i,1,n)cout << ans[i] << " ";
    cout << endl;
 
    return 0;
}
 
/*
6 10
55 46 37 28 19 10 0
*/