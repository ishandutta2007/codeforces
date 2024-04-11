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

#define mp make_pair

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

int n,m;
vi atk, def;
vi ciel;
priority_queue<int>pq, buf;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n>>m;
    REP(i,1,n){
    	string str; int x;
    	cin>>str>>x;
    	if(str[0] == 'A'){
    		atk.pb(x);
		}else{
			def.pb(x);
		}
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	REP(i,1,m){
		int x;
		cin>>x;
		ciel.pb(x);
	}
	sort(ciel.begin(), ciel.end());
	
	int ans = 0;
	
	// kill everything
	bool rekt = false;
	int pc = (int)ciel.size()-1, pd = (int)def.size()-1;
	while(pd >= 0){
		while(pc >= 0 && ciel[pc] > def[pd])pq.push(-ciel[pc--]);
		
		if(pq.empty()){
			rekt = true;
			break;
		}
		pd--;
		pq.pop();
	}
	if(!rekt){
		while(pc >= 0)buf.push(ciel[pc--]);
		while(!pq.empty())buf.push(-pq.top()), pq.pop();
		
		int pa = (int)atk.size()-1;
		while(pa >= 0){
			while(!buf.empty() && buf.top() >= atk[pa]){
				pq.push(-buf.top());
				buf.pop();
			}
			
			if(pq.empty()){
				rekt = true;
				break;
			}
			ans += -pq.top() - atk[pa];
			pa--;
			pq.pop();
		}
	}
	
	if(rekt)ans = 0;
	else{
		while(!buf.empty()){
			ans += buf.top();
			buf.pop();
		}
		while(!pq.empty()){
			ans += -pq.top();
			pq.pop();
		}
	}
	
	// only kill atk positions
	int killatk = 0;
	int pa = 0;
	pc = (int)ciel.size()-1;
	while(pa < atk.size() && pc >= 0 && ciel[pc] >= atk[pa]){
		killatk += ciel[pc--] - atk[pa++];
	}
    
    cout << max(ans, killatk) << endl;
    
    return 0;
}