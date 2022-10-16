    
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

string add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ret;
    int rem = 0;
    int i=0;
    for(; i<a.size() && i<b.size(); i++){
        rem += a[i]-'0';
        rem += b[i]-'0';
        ret += rem%10 + '0';
        rem /= 10;
    }
    for(; i<a.size(); i++){
        rem += a[i]-'0';
        ret += rem%10 + '0';
        rem /= 10;
    }
    for(; i<b.size(); i++){
        rem += b[i]-'0';
        ret += rem%10 + '0';
        rem /= 10;
    }
    while(rem){
        ret += rem%10 + '0';
        rem /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool lt(const string& a, const string& b){
    if(a.size() < b.size())return true;
    if(a.size() > b.size())return false;
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    int n;
    string str, ans;
    
    cin>>n>>str;
    ans = str;
    
    int mid = n/2;
    
    if(str[mid] != '0'){
        string tmp = add(str.substr(0, mid), str.substr(mid));
//        printf("cut %d -> %s\n",mid,tmp.c_str());
        if(lt(tmp, ans)){
            ans = tmp;
        }
    }
    
    int i = max(0, mid-1);
    while(str[i] == '0')i--;
    {
        string tmp = add(str.substr(0, i), str.substr(i));
//        printf("cut %d -> %s\n",i,tmp.c_str());
        if(lt(tmp, ans)){
            ans = tmp;
        }
    }
    
    i = min(mid+1, (int)str.size()-1);
    while(str[i] == '0')i++;
    {
        string tmp = add(str.substr(0, i), str.substr(i));
//        printf("cut %d -> %s\n",i,tmp.c_str());
        if(lt(tmp, ans)){
            ans = tmp;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}