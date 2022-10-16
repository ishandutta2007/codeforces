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

const int N = 3e5 + 5;

int n;
string str;
int pf[N];
int mn;

int memo[N][5];
int ch[N][5];
// stage 0 = still flat
// stage 1 = already changed ) to (
// stage 2 = back to flat
// stage 3 = changed ( to )
int dp(int now, int stage){
	if(now == str.size()){
		if(stage == 1 || stage == 3){
			return -OO;
		}else{
			return 0;
		}
	}
	int& ret = memo[now][stage];
	if(ret != -1)return ret;
	ch[now][stage] = 0;

	ret = -OO;
	int lift = 0;
	if(stage == 1)lift = 2;
	else if(stage == 3)lift = -2;

	if(pf[now] + lift >= mn){
		int add = 0;
		if(pf[now] + lift == mn)add++;
		ret = dp(now+1, stage) + add;
	}
	if(stage == 0){
		if(str[now] == ')'){ // stage 1
			int add = 0;
			if(pf[now] + 2 == mn)add++;
			if(pf[now] + 2 >= mn){
				int tmp = dp(now+1, 1) + add;
				if(tmp > ret){
					ret = tmp;
					ch[now][stage] = 1;
				}
			}
		}else{ // stage 3
			int add = 0;
			if(pf[now] - 2 == mn)add++;
			if(pf[now] - 2 >= mn){
				int tmp = dp(now+1, 3) + add;
				if(tmp > ret){
					ret = tmp;
					ch[now][stage] = 3;
				}
			}
		}
	}
	if(stage == 1 && str[now] == '('){
		int add = 0;
		if(pf[now] == mn)add++;
		if(pf[now] >= mn){
			int tmp = dp(now+1, 2) + add;
			if(tmp > ret){
				ret = tmp;
				ch[now][stage] = 2;
			}
		}
	}
	if(stage == 3 && str[now] == ')'){
		int add = 0;
		if(pf[now] == mn)add++;
		if(pf[now] >= mn){
			int tmp = dp(now+1, 2) + add;
			if(tmp > ret){
				ret = tmp;
				ch[now][stage] = 2;
			}
		}
	}

	return ret;
}

vector<int> bt(){
	vi vec;
	int now = 0, stage = 0;
	while(now < str.size()){
		// printf("at %d %d %d %d\n",now,stage,ch[now][stage], memo[now][stage]);
		if(ch[now][stage]){
			// printf("%d to stage %d %d\n",now,ch[now][stage],memo[now][stage]);
			stage = ch[now][stage];
			vec.pb(now+1);
		}
		now++;
	}
	assert(vec.size() == 0 || vec.size() == 2);
	return vec;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>str;
    int cur=0;
    mn = 0;
    FOR(i,str.size()){
    	if(str[i] == '('){
    		cur++;
    	}else{
    		cur--;
    	}
    	mn = min(mn, cur);
    	pf[i] = cur;
    }

    if(pf[n-1] != 0){
    	cout << "0" << endl;
    	cout << "1 1" << endl;
    	return 0;
    }

    int ans = -1;
    vi vans;
    mn -= 2;
    REP(i,-2,2){
    	memset(memo, -1, sizeof memo);
    	int tmp = dp(0, 0);
    	if(tmp > ans){
    		ans = tmp;
    		vans = bt();
    	}
    	mn++;
    }
    
    cout << ans << endl;

	if(vans.size() == 0)cout << "1 1" << endl;
	else cout << vans[0] << " " << vans[1] << endl;

    return 0;
}

/*
10
()()()(())

6
)))(((
*/