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

string str = "What are you doing at the end of the world? Are you busy? Will you save us?";
string copp[] = {"What are you doing while sending \"", "\"? Are you busy? Will you send \"", "\"?"};

ll sz[N];

int t;
int n;
ll k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    sz[0] = str.size();
    REP(i,1,N-5){
    	sz[i] = copp[0].size() + sz[i-1] + copp[1].size() + sz[i-1] + copp[2].size();
    	if(sz[i] > INF)sz[i] = INF;
    }

    cin>>t;
    while(t--){
    	cin>>n>>k;
    	if(k > sz[n]){
    		cout << ".";
    	}else{
    		while(1){
    			if(n == 0){
    				cout << str[k-1];
    				break;
    			}

    			if(k <= copp[0].size()){
    				cout << copp[0][k-1];
    				break;
    			}else{
    				k -= copp[0].size();
    			}

    			if(k <= sz[n-1]){
    				n--;
    				continue;
    			}else{
    				k -= sz[n-1];
    			}

    			if(k <= copp[1].size()){
    				cout << copp[1][k-1];
    				break;
    			}else{
    				k -= copp[1].size();
    			}

    			if(k <= sz[n-1]){
    				n--;
    				continue;
    			}else{
    				k -= sz[n-1];
    			}

    			if(k <= copp[2].size()){
    				cout << copp[2][k-1];
    				break;
    			}else{
    				k -= copp[2].size();
    			}
    		}
    	}
    }
    cout << endl;

    return 0;
}