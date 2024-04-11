#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back
#define y0 aksjdnalsdma

vector<pair<ll,ll>> q;
vector<ll> g;

void ask(ll ty, ll x, ll y){
  if(ty==0){
    cout<<"SCAN ";
  }else{
    cout<<"DIG ";
  }
  q.pb({x,y});
  cout<<x+1<<" "<<y+1<<endl;
  ll res; cin>>res;
  g.pb(res);
}

ll dist(pair<ll,ll> a, pair<ll,ll> b){
  return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

bool check(pair<ll,ll> a, pair<ll,ll> b){
  fore(i,0,SZ(q)){
    if(dist(a,q[i])+dist(b,q[i])!=g[i])return 0;
  }
  return 1;
}

int main() {FIN;
  int t; cin >> t;
  while(t--) {
    ll n, m; cin >> n >> m;
    q.clear();
    g.clear();
    ask(0,0,0);
    ask(0,n-1,0);
    ll sy=(g[0]+g[1])/2-n+1;
    ll sx=g[0]-sy;
    ll lx=0,rx=n-1;
    while(lx+rx<sx)lx++;
    while(lx+rx>sx)rx--;
    ll ly=0,ry=m-1;
    while(ly+ry<sy)ly++;
    while(ly+ry>sy)ry--;
    // cout<<"s "<<sx<<" "<<sy<<"\n";
    ask(0,(lx+rx)/2,(ly+ry)/2);
    ask(0,0,(ly+ry)/2);
    ll br=0;
    fore(x0,0,n){
      if(br)break;
      fore(y0,0,m){
        if(br)break;
        fore(x1,0,n){
          if(br)break;
          fore(y1,0,m){
            if(br)break;
            if(check({x0,y0},{x1,y1})){
              //cerr<<"found "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
              ask(1,x0,y0);
              if(g[4]){
                ask(1,x1,y1);
              }else{
                ask(1,x0,y1);
                ask(1,x1,y0);
              }
              br++;
            }
          }
        }
      }
    }
    assert(br);
  }
}
/*
1
16 16
SCAN 1 1
32
SCAN 16 1
30
s 16 16
SCAN 9 9
8
SCAN 1 9
18
DIG 6 8
0
DIG 6 10
0
DIG 12 8
0
*/