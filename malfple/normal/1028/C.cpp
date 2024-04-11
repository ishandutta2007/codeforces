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

const int N = 132674;

int n;
vector<pair<pii, pii> >vec;

map<int,int>codex;
vi revex;

pii tree[8*N + 5];
int pend[8*N + 5];

void init(int idx, int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        init(idx<<1, left, mid);
        init(idx<<1|1, mid+1, right);
        tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
    }else{
        tree[idx] = mp(0, left);
    }
}

int apply(int idx, int v){
    tree[idx].F += v;
    pend[idx] += v;
}

int pushdown(int idx){
    if(pend[idx]){
        apply(idx<<1, pend[idx]);
        apply(idx<<1|1, pend[idx]);
        pend[idx] = 0;
    }
}

int update(int idx, int left, int right, int l, int r, int v){
    if(left >= l && right <= r){
        apply(idx, v);
    }else if(right < l || left > r){
        // do nothing
    }else{
        int mid = (left+right)/2;
        pushdown(idx);
        update(idx<<1, left, mid, l, r, v);
        update(idx<<1|1, mid+1, right, l, r, v);
        tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'

    cin>>n;
    REP(i,1,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        codex[y1] = 0;
        codex[y2] = 0;
        vec.pb(mp(mp(x1, -1), mp(y1, y2))); // add
        vec.pb(mp(mp(x2, 1), mp(y1, y2))); // sub
    }

    int id = 0; revex.pb(-1);
    for(map<int,int>::iterator it = codex.begin(); it != codex.end(); it++){
        it->S = ++id;
        revex.pb(it->F);
    }

    FOR(i,vec.size()){
        vec[i].S.F = codex[vec[i].S.F];
        vec[i].S.S = codex[vec[i].S.S];
    }
    sort(vec.begin(), vec.end());

    init(1, 1, id);
    FOR(i,vec.size()){
        update(1, 1, id, vec[i].S.F, vec[i].S.S, -vec[i].F.S);

        if(tree[1].F >= n-1){
            //cout << tree[1].S << endl;
            cout << vec[i].F.F << " " << revex[tree[1].S] << endl;
            break;
        }
    }

    return 0;
}