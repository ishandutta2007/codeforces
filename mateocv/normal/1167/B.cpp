#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll resp[4];

void ask(ll i){
  cout<<"? "<<i+1<<" "<<i+2<<endl;
  cin>>resp[i];
  assert(resp[i]!=0);
}

pair<ll,ll> des(ll x){
  if(x%23==0)return {23,x/23};
  if(x%42==0)return {42,x/42};
  if(x%15==0)return {15,x/15};
  if(x==8*16)return {8,16};
  if(x==4*16)return {4,16};
  if(x==4*8)return {4,8};
}

int main(){FIN; //4, 8, 15, 16, 23, 42
	fore(i,0,4)ask(i);
  pair<ll,ll> p[2];
  p[0]=des(resp[0]);
  p[1]=des(resp[1]);
  ll res[6];
  if(p[0].fst==p[1].fst)res[0]=p[0].snd;
  if(p[0].fst==p[1].snd)res[0]=p[0].snd;
  if(p[0].snd==p[1].fst)res[0]=p[0].fst;
  if(p[0].snd==p[1].snd)res[0]=p[0].fst;
  fore(i,1,6){
    res[i]=resp[i-1]/res[i-1];
  }
  res[5]=4+8+15+16+23+42;
  fore(i,0,5){
    res[5]-=res[i];
  }
  cout<<"! ";
  fore(i,0,6)cout<<res[i]<<" ";
	return 0;
}