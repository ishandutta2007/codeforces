// #151025283

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itn int
//#define gcdi gcd

typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3i;
typedef tuple<int,int,int,int> t4i;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<str> vs;

typedef map<int,int> mii;
typedef map<pii,int> mi2i;
typedef map<int,pii> mii2;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef unordered_map<int,int> umii;
typedef pair<int,vi> dti;

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int K = 9;
using u64 = uint64_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void out(const vi& v, string bkr = " ") {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << bkr;
	}
}
void out(int* v, int n, string bkr = " ") {
	for (int i = 0; i < n; ++i) {
		cout << *(v + i) << bkr;
	}
}

void out(vector<t3i> t) {
    for (auto e:t) {
        cout<<"("<<get<0>(e)<<","<<get<1>(e)<<","<<get<2>(e)<<")"<<" ";
    }
}

pii tr(pii x) {
    int f = x.first>>K;
    return mp(f,(f%2?1:-1)*x.second);
}


void solve() {
    int n,m;
    cin>>n>>m;
    int bt[m];
    int tc[512][512];pii trains[n];
    memset(tc,0,sizeof(tc));
    for (int i=0;i<n;i++) {
        int x,y;cin>>x>>y;
        trains[i] = mp(x,x+y);
    }
    vii blank;vi diffarr(m+1,0);
    vii dr;
    vector<vii> dist(n,blank);
    for (int i=0;i<m;i++) {
        int opt,tn;cin>>opt>>tn;tn--;
        //cout<<opt<<" "<<tn<<endl;
        dr.pb(mp(opt,tn));
        if (opt==1) {
            dist[tn].pb(mp(i,m));
        }
        else {
            dist[tn].rbegin()->second=i;
            bt[i]=dist[tn].rbegin()->first;
        }
    }
    for (int i=0;i<n;i++) {
        int tis=trains[i].second;
        if (tis>=(1<<K)) {
            for (auto p:dist[i]) {
                int r = p.first + trains[i].first;
                while (r<p.second) {
                    diffarr[r]++;
                    diffarr[min(r+tis-trains[i].first,p.second)]--;
                    r+=tis;
                }
            }
        }
    }
    int d = 0;
    for (int i=0;i<m;i++) {
        pii dt=dr[i];
        int opt=dt.first,tn=dt.second;
        int q=trains[tn].second;
        if (q<(1<<K)) {
            int x,delta = (opt==1?1:-1);
            if (opt==1) x=i;
            else x=bt[i];
            for (int j=trains[tn].first;j<q;j++) {
                tc[q][(signed)(x+j)%(signed)q] += delta;
            }
        }
        int c = 0;
        for (int r=1;r<(1<<K);r++) {
            c += tc[r][(signed)i%(signed)r];
        }
        d+=diffarr[i];
        cout<<d+c<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cout << setprecision(10);
    //int t;cin >> t;while (t--)
    {
        solve();
    }
    return 0;
}