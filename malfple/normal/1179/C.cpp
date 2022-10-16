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

const int N = 1e6;

struct node{
    int dish, pupil;
    node(){
        dish = pupil = 0;
    }
}tree[4*N+5];

node combine(const node& a, const node& b){
    node ret;
    int buy = min(b.pupil, a.dish);
    ret.dish = a.dish - buy + b.dish;
    ret.pupil = a.pupil + b.pupil - buy;
    return ret;
}

// v positive = add dish/remove pupil
// v negative = remove dish/ add pupil
void update(int idx, int left, int right, int x, int v){ 
    if(left == right){
        tree[idx].dish += v;
        if(tree[idx].dish < 0){
            tree[idx].pupil -= tree[idx].dish;
            tree[idx].dish = 0;
        }else{
            int sub = min(tree[idx].dish, tree[idx].pupil);
            tree[idx].dish -= sub;
            tree[idx].pupil -= sub;
        }
    }else{
        int mid = (left+right)/2;
        if(x <= mid)
            update(idx<<1, left, mid, x, v);
        else
            update(idx<<1|1, mid+1, right, x, v);

        tree[idx] = combine(tree[idx<<1], tree[idx<<1|1]);
    }
}

int getUntaken(int idx, int left, int right, int excessPupil){
    // printf("getUntaken, at %d-%d, data %d %d, excess %d\n",
    //     left,right,tree[idx].dish, tree[idx].pupil, excessPupil);
    if(tree[idx].dish <= excessPupil)return -1;
    if(left == right)return left;

    int mid = (left+right)/2;
    if(tree[idx<<1|1].dish > excessPupil)
        return getUntaken(idx<<1|1, mid+1, right, excessPupil);
    else
        return getUntaken(idx<<1, left, mid,
            excessPupil - tree[idx<<1|1].dish + tree[idx<<1|1].pupil);
}

int n,m;
int dish[N];
int pupil[N];
int q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m;
    REP(i,1,n){ // dish
        cin>>dish[i];
        update(1, 1, N, dish[i], 1);
    }
    REP(i,1,m){ // pupil
        cin>>pupil[i];
        update(1, 1, N, pupil[i], -1);
    }

    cin>>q;
    while(q--){
        int op, x, v;
        cin>>op>>x>>v;
        if(op == 1){
            update(1, 1, N, dish[x], -1);
            dish[x] = v;
            update(1, 1, N, dish[x], 1);
        }else{
            update(1, 1, N, pupil[x], 1);
            pupil[x] = v;
            update(1, 1, N, pupil[x], -1);
        }
        // printf("query %d\n",q);
        cout << getUntaken(1, 1, N, 0) << endl;
    }

    return 0;
}