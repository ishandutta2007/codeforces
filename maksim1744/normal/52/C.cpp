#include <bits/stdc++.h>
#define setIO ios::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define ar array
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int nx = 1e6;
vector<ll> tree(nx), l(nx);
ll f(int j, int nl, int nr, int ql, int qr) {
    if (l[j]!=0) {
        tree[j]+=l[j];
        if (nl!=nr) {
            l[j*2]+=l[j],l[j*2+1]+=l[j];
        }
        l[j]=0;
    }
    if (ql>nr||qr<nl) return LLONG_MAX;
    if (ql<=nl&&nr<=qr) return tree[j];
    int k = (nl+nr)/2;
    return min(f(j*2,nl,k,ql,qr),f(j*2+1,k+1,nr,ql,qr));
}
void update(int j, int nl, int nr, int ql, int qr, ll v) {
    if (l[j]!=0) {
        tree[j]+=l[j];
        if (nl!=nr) {
            l[j*2]+=l[j];
            l[j*2+1]+=l[j];
        }
        l[j]=0;
    }
    if (ql>nr||qr<nl) return;
    if (ql<=nl&&nr<=qr) {
        tree[j]+=v;
        if (nl!=nr) {
            l[j*2]+=v;
            l[j*2+1]+=v;
        }
        return;
    }
    int m = (nl+nr)/2;
    update(j*2,nl,m,ql,qr,v);
    update(j*2+1,m+1,nr,ql,qr,v);
    tree[j]=min(tree[j*2],tree[j*2+1]);
}
int main() {
    setIO
    int a; cin >> a;
    vector<ll> t(a);
    for (int i = 0; i < a; i++) cin >> t[i];
    //while (__builtin_popcount(a)!=1) a++;
    tree.resize(4*a);
    l.resize(4*a);
    for (int i = 0; i < (int)t.size(); i++) {
        update(1,0,a-1,i,i,t[i]);
    }
//    for (int i = a-1; i >= 1;  i--) {
//        tree[i] = min(tree[i*2],tree[i*2+1]);
//    }
    int b; cin >> b;
    cin.ignore();
    while (b--) {
        string s; getline(cin, s);
        stringstream ss(s);
        vector<int> tmp;
        int cur = 0;
        while (ss>>cur) {
            tmp.push_back(cur);
        }
        int l = tmp[0], r = tmp[1];
        if ((int)tmp.size()==3) {
            ll v = tmp[2];
            if (l<=r) {
                update(1,0,a-1,l,r,v);
            }
            else {
                update(1,0,a-1,l,a-1,v);
                update(1,0,a-1,0,r,v);
            }
        }
        else {
            if (l<=r) {
                cout<<f(1,0,a-1,l,r) << '\n';
            }
            else {
                cout<<min(f(1,0,a-1,l,a-1),f(1,0,a-1,0,r)) << '\n';
            }
        }
    }
}