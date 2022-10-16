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

const int N = 1e6 + 5;

string str;
string str2;

int kmp[N];
int kmp2[N];

bool cek(string pat){
	//printf("cek %s\n",pat.c_str());
	kmp2[0] = -1;
	for(int i=0, j=-1; i < pat.size(); i++, j++){
	    while ((j >= 0) && (pat[i] != pat[j])) j = kmp2[j];
	    kmp2[i+1] = j+1;
	}
	
	int found = -1;
	for(int i=0, j=0; i < str2.size(); i++, j++){
	    while ((j >= 0) && (str2[i] != pat[j])) j = kmp2[j];
	    if (j+1 == pat.size()){
	        found = i-j;
	        break;
	    }
	}
	return found != -1;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    #define endl '\n'
    
    cin>>str;
    if(str.size() < 3){
    	cout << "Just a legend" << endl;
    	return 0;
	}
	
    str2 = str.substr(1, str.size()-2);
    
    //cout << str << " " << str2 << endl;
    
	kmp[0] = -1;
	for(int i=0, j=-1; i < str.size(); i++, j++){
	    while ((j >= 0) && (str[i] != str[j])) j = kmp[j];
	    kmp[i+1] = j+1;
	}
	
	int ans = -1;
	int now = kmp[str.size()];
	while(now > 0){
		//printf("now %d\n",now);
		if(cek(str.substr(0, now))){
			ans = now;
			break;
		}
		now = kmp[now];
	}
	
	if(ans == -1)cout << "Just a legend" << endl;
	else cout << str.substr(0, ans) << endl;
    
    return 0;
}