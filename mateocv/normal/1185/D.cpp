#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	pair<ll,ll> a[n];
	ll lle;
	fore(i,0,n){
		cin>>lle;
		a[i]={lle,i+1};
	}
	sort(a,a+n);
	ll d[n-1];
	fore(i,0,n-1){
		d[i]=a[i+1].fst-a[i].fst;
	}
	ll dif=-1;
	fore(i,0,n-1)dif=max(dif,d[i]);
	if(n==2||n==3){
		cout<<1; return 0;
	}
	ll tot1=0,tot2=0;
	fore(i,0,n-1){
		if(i<n-2&&d[i]==d[0])tot1++;
		if(i>0&&d[i]==d[n-2])tot2++;
	}
	if(tot1==n-2){
		cout<<a[n-1].snd; return 0;
	}
	if(tot2==n-2){
		cout<<a[0].snd; return 0;
	}
	ll tot=0;
	ll b;
	fore(i,0,n-1){
		tot+=(d[i]==dif);
		if(d[i]!=dif)b=i;
	}
	if(tot==n-1){
		cout<<1; return 0;
	}
	if(tot==n-2){
		if(d[b]==0)cout<<a[b].snd;
		else cout<<-1;
		return 0;
	}
	if(tot==n-3&&b>0&&d[b]+d[b-1]==dif&&d[b-1]!=dif){
		cout<<a[b].snd;
	}else{
		cout<<-1;
	}
	
	return 0;
}