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

ll ap[100005];

int main(){FIN;
    ll n; cin>>n;
  ll a[n];
  fore(i,0,n)cin>>a[i];
  ll res=0,mini=0,maxi=0,tot=0;
  fore(i,1,n+1){
    if(!ap[a[i-1]]){
      ap[a[i-1]]=1; tot++;
      mini=1;
      if(maxi==0)maxi++;
    }else{
      ap[a[i-1]]++;
      maxi=max(maxi,ap[a[i-1]]);
      ll mint=1ll*1e18;
      fore(j,0,12){
        if(ap[j]>0)mint=min(mint,ap[j]);
      }
      mini=mint;
    }
    if(maxi-1==mini&&(i-1)%tot==0)res=i;
    if(tot==1)res=i;
    ll minim=1ll*1e18;
    ll ya=0;
    fore(j,0,12){
        //if(j==3)cout<<"ya es "<<ya;
        if(ap[j]>0&&(ya||ap[j]>1))minim=min(minim,ap[j]);
        if(ap[j]==1)ya=1;
    }
    if(tot>1&&mini==1&&((i-1)%(tot-1)==0)&&(maxi==1||minim==maxi))res=i;//cout<<minim<<"\n";
    //cout<<maxi<<" "<<mini<<"\n";
  }
  cout<<res;	

	return 0;
}