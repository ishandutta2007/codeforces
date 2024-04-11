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

int mode = 1;
/*
1 = divide by 3, m1, m2, x = throw away right, y = throw away middle, go to mode 2
2 = divide left by 2, right just leave,
*/

int hi;
int rlo, rhi;

int A;
int askcnt;

inline bool ask(int x, int y){
	cout << "? " << x << " " << y << endl;
	//cout << "? " << x%3 << " " << y%3 << endl;
	char c;
	cin>>c;
//	if(x%A >= y%A)c = 'x';
//	else c = 'y';
//	askcnt++;
	
	if(c == 'x')return true;
	return false;
}
inline bool answer(int x){
	cout << "! " << x << endl;
	//cout << "real anser: " << A << " " << "done in " << askcnt << " iterations" << endl;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    #define endl '\n'
//    cout.setf(ios::fixed);
//    cout.setf(ios::showpoint);
//    cout.precision(10);
    
    while(1){
    	string command;
    	cin>>command;
    	if(command[0] != 's'){
    		break;
		}
		
		//A = irand(1,100);
		//askcnt = 0;
		
		mode = 1;
		hi = 1e9;
		rlo = -1, rhi = -1;
		while(hi > 2){
			//printf("mode %d, hi=%d\n",mode,hi);
			int mid = (1+hi)/2;
			if(mode == 1){
				int midl = mid/2;
				if(ask(midl, mid)){
					hi = mid;
				}else{
					mode = 2;
					rlo = mid+1;
					rhi = hi;
					hi = midl;
				}
			}else if(mode == 2){
				if(ask(mid, hi)){
					rlo = rhi = -1;
					mode = 1;
				}else{
					hi = mid;
				}
			}
		}
		
		if(ask(2,1)){
			if(rlo == -1){
				answer(1);
			}else{
				while(rlo < rhi){
					int mid = (rlo + rhi)/2;
					if(ask(rlo-1, mid)){
						rhi = mid;
					}else{
						rlo = mid+1;
					}
				}
				if(ask(rlo, rlo+1)){
					answer(1);
				}else{
					answer(rlo);
				}
			}
		}else{
			answer(2);
		}
	}
    
    return 0;
}