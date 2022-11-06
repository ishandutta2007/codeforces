#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>

const int base=256*1024, N=2e5+69;
pair <int,int> tree[base*2+69];
int qwe,n,m,t,d;
pair <int,int> wynik;
vector <pair<int,int>> vek;
void tree_clear(int v) {
    //cout<<"huj"<<endl;
    if(tree[v]==make_pair(0ll,0ll)) return;
    tree[v]=make_pair(0ll,0ll);
    if(v>=base) return;
    tree_clear(v*2);
    tree_clear(v*2+1);
}
void insert(int v, int w) {
    v+=base;
    tree[v]=make_pair(1,w);
    v/=2;
    while(v) {
        tree[v].first=tree[v*2].first+tree[v*2+1].first;
        tree[v].second=tree[v*2].second+tree[v*2+1].second;
        v/=2;
    }
}
pair<int,int> query(int l,int p) {
    l+=base;
    p+=base;
    pair<int,int> re=tree[l];
    if(l!=p) re.first+=tree[p].first, re.second+=tree[p].second;
    while(l<p-1) {
        if(l%2==0) re.first+=tree[l+1].first, re.second+=tree[l+1].second;
        if(p%2==1) re.first+=tree[p-1].first, re.second+=tree[p-1].second;
        l/=2;
        p/=2;
    }
    return re;
}
void czysc() {
    tree_clear(1);
    tree_clear(2);
    tree_clear(3);
    d=0;
    wynik=make_pair(0ll,0ll);
}
int licz() {
    int l=0ll;
    int p=n;
    while(l<p) {
        int sr=(l+p+1)/2;
        if(query(0ll,sr).second*2<=t) l=sr;
        else p=sr-1;
    }
//     if (d == 4)
//     cerr << "l = " << l << endl;
    int ind=query(0,l).first;
    ind/=m;
    ind*=m;
    l=0ll;
    p=n;
    while(l<p) {
        int sr=(l+p+1)/2;
        if(query(0ll,sr).first<=ind) l=sr;
        else p=sr-1;
    }
//     if (d == 4)
//     cerr << "l = " << l << endl;
    int tymt=t-query(0ll,l).second;
    l=0ll;
    p=n;
    while(l<p) {
        int sr=(l+p+1)/2;
        if(query(0ll,sr).second<=tymt) l=sr;
        else p=sr-1;
    }
//     if (d == 4)
//     cerr << "l = " << l << endl;
    return min(query(0ll,l).first,ind+m);
}
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>qwe;
  while(qwe--) {
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        vek.push_back(make_pair(a,i));
    }
    sort(ALL(vek));
    reverse(ALL(vek));
    while(!vek.empty()) {
        d=vek.back().first;
        insert(vek.back().second,d);
        vek.pop_back();
        if(vek.empty()==true ||vek.back().first!=d) {
            int zm=licz();
            if(zm>wynik.first) wynik.first=zm, wynik.second=d;
        }
    }
    if (wynik.second == 0) {
        wynik.second = 1;
    }
    cout<<wynik.first<<" "<<wynik.second<<endl;
//     exit(0);
    czysc();
  }
}