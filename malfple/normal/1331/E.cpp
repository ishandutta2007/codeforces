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


string str[64] = {
    "XXXXXXXXXXXXXXXXXXXXXXXXXX X X      X XXXXXXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXX X   X X X XX X     XXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXX   X XXX XXX  X XXXX XX XXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXX    X X X     XXXX    X X   X XXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXX  XXXXXX X XXXXX    XXXX X X X  XXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXX XX  X     X   X   X XX X  XXX XX X XXXXXXXXXXXXXX",
    "XXXXXXXXXXXXX   XX XX XXXXXX X XXX    XX  X  X  X  XXXXXXXXXXXXX",
    "XXXXXXXXXXX      X  X  X   X   X   XXXX  XX XX XXX   XXXXXXXXXXX",
    "XXXXXXXXXX            XXXX XXXXX XXX X  XX  X  X XX   XXXXXXXXXX",
    "XXXXXXXXX                    X       XX    XX          XXXXXXXXX",
    "XXXXXXXX                                                XXXXXXXX",
    "XXXXXXX                                                  XXXXXXX",
    "XXXXXXX                                                  XXXXXXX",
    "XXXXXX                                                    XXXXXX",
    "XXXXX                                                      XXXXX",
    "XXXXX                                                      XXXXX",
    "XXXX                                                        XXXX",
    "XXX                                                          XXX",
    "XXXXX                                                        XXX",
    "XXXXXXX            XXX XX              XXX X X             XXXXX",
    "XX  XXXXX         XX XXX               X XXXXXXX        XXXXXXXX",
    "XX    XXXXX     XXX  X XXX               X  X  XX X  XXXXXXX  XX",
    "X       XXXXX XXX   XX   XX           X XX XXX  XXXXXXXXX      X",
    "X         XXXXX XX XX  X  XXX         X  X     XX XXXX         X",
    "X            X  X   XXXXX   XX       XXX XX XXXX   X           X",
    "X         XXXXX XXX   X   XXX        X X     X XXX XX X        X",
    "            X   X XX XX XXX XX      XX XX XXXX  X   XXX         ",
    "           XXX XX X  X   X   X    X X   X    XX   XXX X         ",
    "           X      X    XXXX XX X XXXX X XX X    XXX   X         ",
    "           XXXXX XX XX   X   XXX X X  X  X XX XXX XX XX         ",
    "            X  X    X  X   XXX X   XXXXX    X X      X          ",
    "           XXX   XX XX XXX   X XX   X    XX X   XXX XXX         ",
    "             XXXXX  X   X  X   X  XXXXX XX  X  XX XXX X         ",
    "              X  X XXXX X XXXX X XX X X  X XXX  X  X            ",
    "            XXXX    X X X X X    X  X XX X   XX   XXX           ",
    "             X XX XXX   XXX    XXX XX  XXXX XX  XXX             ",
    "                XXX   XXX X  X  X  X  XX X   X XX XX            ",
    "                  XXX X      XXXXX       XXX XXX                ",
    "X                XX XXXX     X X           XXX XX              X",
    "X                              XXXX                            X",
    "X                           X XX X                             X",
    "X                         X XXX                                X",
    "XX                        XXX XXX                             XX",
    "XX       XX                   X                               XX",
    "XXX       X X                XXX                     X       XXX",
    "XXX       XXX XXX           XX X           X     X XXXX      XXX",
    "XXX       X X X XX X XXX  X X  XX X XX X  XXX  XXXXX X       XXX",
    "XXXX        XXX  XXXXX XXXXXXX  XXX  XXXXXX X XX   X        XXXX",
    "XXXXX       X XX    X    X   XX   XXXX   X     X X         XXXXX",
    "XXXXX          X XX XX XXX X    X   X  X XXXXX XXX         XXXXX",
    "XXXXXX        XXXX  X  X XXXX XXX X XXXX   X XXX          XXXXXX",
    "XXXXXXX         X  XXX     X  X X XXX X  XXX             XXXXXXX",
    "XXXXXXX         XX   XX X XXX   XXX X   XX XXX           XXXXXXX",
    "XXXXXXXX         XXX    XXX   X  X    X    X            XXXXXXXX",
    "XXXXXXXXX         X  XXXX X XXXXXX XXXX X              XXXXXXXXX",
    "XXXXXXXXXX            X X    X  X  X X  XX            XXXXXXXXXX",
    "XXXXXXXXXXX             XXXX    XXXX XXXX            XXXXXXXXXXX",
    "XXXXXXXXXXXXX                    X                 XXXXXXXXXXXXX",
    "XXXXXXXXXXXXXX                                    XXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXX                                XXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXX                              XXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXX                        XXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXX                    XXXXXXXXXXXXXXXXXXXXXX",
    "XXXXXXXXXXXXXXXXXXXXXXXXXX            XXXXXXXXXXXXXXXXXXXXXXXXXX",
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    int x,y;
    cin>>x>>y;
    if(str[x][y] == 'X'){
        cout << "OUT" << endl;
    }else{
        cout << "IN" << endl;
    }

    return 0;
}