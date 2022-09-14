#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<double,double> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const ll mod=1e9 + 7;
const ll LINF=1ll<<60;
const int INF=1<<30;
//int dx[]={0,1,0,-1,0,1,-1,1,-1};
//int dy[]={0,0,1,0,-1,1,-1,-1,1};
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

const int MN = 6 * 1e5;
const int M = 3 * 1e5;

struct SegmentTree{
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v){
        int sz = v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2*n-1,-INF);
        for (int i = 0; i < sz; i++) node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--) node[i] = max(node[2*i+1],node[2*i+2]);
    }

    void update(int x,int val){
        x += n-1;
        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1],node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        if (r < 0) r = n;
        if(r <= a || b <= l) return -INF;
        if(a <= l && r <= b) return node[k];
        int vl = getmax(a, b, 2*k+1, l , (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2,r);
        return max(vl, vr);
    }
};





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin >> n;
    vector<P> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fs;
        a[i].sc = -i - 1;
    }
    sort(ALL(a));
   SegmentTree seg(vector<int> (MN, -INF));
   seg.update(M, 0);
   for (int i = 0; i < n; i++) {
       int A = a[i].fs;
       int P = seg.getmax(M + A + a[i].sc, MN);
       if(P >= 0){
           seg.update(M + A + a[i].sc, P + 1);
       }
   }
   cout << seg.getmax(0, MN) << endl;
   return 0;
}