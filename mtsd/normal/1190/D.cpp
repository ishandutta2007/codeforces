#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define int long long

template<typename T> class segtree {
private:
    int n,sz;
    vector<T > node;
public:
    segtree(vector<T>& v) : sz((int)v.size()){
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n,0);
    }
    void update(int k, T a)
    {
    	node[k+n] = a;
    	k+=n;
        while(k>>=1){
            node[k] = (node[2*k]+node[2*k+1]);
    	}
    }
    int query(int a,int b,int k=0,int l=0,int r=-1)
    {
        int res1 = 0;
        int res2 = 0;
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 += node[a++];
            if(b % 2) res2 += node[--b];
            a >>= 1, b>>= 1;
        }
        return res1+res2;
    }
    
};
#define MAP 200010
map<int,int> zip;
int unzip[MAP];

int compress(vector<int> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    for(int i = 0; i < x.size(); i++){
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int> > p(n);
    rep(i,n){
        cin >> p[i].second >> p[i].first;
        p[i].first = -p[i].first;
    }
    sort(p.begin(),p.end());
    vector<int>x(n);
    rep(i,n){
        p[i].first = -p[i].first;
        x[i] = p[i].second;
    }
    int M = compress(x);
    vector<ll> v(M);
    segtree<ll> sg(v);
    queue<ll>q;
    ll sm = 0;
    rep(i,n){
        //cerr << p[i].first << " " << p[i].second << endl;
        //cerr << i << " " << sm << endl;
        if(i!=n-1&&p[i].first==p[i+1].first){
            int k = zip[p[i].second];
            q.push(k);
            sg.update(k,1LL);
            continue;
        }
        int k = zip[p[i].second];
        sg.update(k,1LL);
        if(q.empty()){
            sm += sg.query(0,k+1)*sg.query(k,M);
            //cerr <<"test1" << endl;
        }else{
            q.push(k);
            int pre = -1;
            while(!q.empty()){
                int xxx = q.front();
                q.pop();
                sm += sg.query(pre+1,xxx+1)*sg.query(xxx,M);
                //cerr << "test2" << " " << sg.query(pre+1,xxx+1) << " " << sg.query(xxx,M)  << endl;
                pre = xxx;
            }
        }
    }
    cout << sm << endl;
    return 0;
}