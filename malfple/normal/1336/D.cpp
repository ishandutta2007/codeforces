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

const int N = 105;

int n;
int ans[N];

int trip[N], stra[N];

void do_straight(){
    // inserting 2, get 3 (at this point, cnt[1] is >=1)
    if(ans[3] == -1){
        int diffs = stra[2] - stra[1];
        if(diffs == 0){
            ans[3] = 0;
        }else{
            ans[3] = 1;
        }
    }
    // inserting 1 (at nth insert), get 2 (at this point, every cnt is +1)
    if(ans[2] == -1){
        int diffs = stra[n] - stra[n-1];
        if(diffs == ans[3]+1){
            ans[2] = 0;
        }else{
            ans[2] = 1;
        }
    }

    // solve for 4..n-1
    REP(i,3,n-2){
        if(ans[i+1] != -1)continue;
        int diffs = stra[i] - stra[i-1];
        diffs -= (ans[i-2]+1) * (ans[i-1]+1);
        if(diffs == 0){
            ans[i+1] = 0;
        }else{
            ans[i+1] = 1;
        }
    }

    // insert at n-1, solve for n
    if(ans[n] == -1){
        int diffs = stra[n-1] - stra[n-2];
        diffs -= (ans[n-3]+1) * (ans[n-2]+1);
        ans[n] = diffs / (ans[n-2] + 1);
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // #define endl '\n'
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(10);

    cin>>n;
    cin>>trip[0]>>stra[0];
    REP(i,1,n){
        cout << "+ " << (i==n ? 1 : i) << endl;
        cin>>trip[i]>>stra[i];
    }

    memset(ans, -1, sizeof ans);

    // answering for triplets
    REP(i,1,n-1){
        int difft = trip[i] - trip[i-1];
        if(difft > 0){
            int prevn = 2;
            while(1){
                if(prevn * (prevn-1) / 2 == difft)break;
                prevn++;
            }
            ans[i] = prevn;
        }
    }
    if(ans[1] == -1){
        int difft = trip[n] - trip[n-1];
        if(difft > 0)ans[1] = 1;
        else ans[1] = 0;
    }

    // those still -1, is either 0 or 1

    // straights!
    do_straight();

    cout << "!";
    REP(i,1,n)cout << " " << ans[i];
    cout << endl;

    return 0;
}

/*
5
1 6
2 9
2 18
5 24
5 40
8 48
*/