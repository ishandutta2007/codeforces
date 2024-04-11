#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MAXK 33
#define endl '\n'
using namespace std;

typedef long long ll;

ll fs[MAXK+1][100005];
ll fm[MAXK+1][100005];
int ff[MAXK+1][100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;ll t;
	cin>>n>>t;
	fore(i,0,n)cin>>ff[0][i];
	fore(i,0,n)cin>>fs[0][i],fm[0][i]=fs[0][i];
	fore(k,1,MAXK+1)fore(i,0,n){
		ff[k][i]=ff[k-1][ff[k-1][i]];
		fs[k][i]=fs[k-1][i]+fs[k-1][ff[k-1][i]];
		fm[k][i]=min(fm[k-1][i],fm[k-1][ff[k-1][i]]);
	}
	fore(i,0,n){
		ll rs=0,rm=1LL<<60;
		int x=i;ll l=t;
		for(int k=MAXK;k>=0;--k){
			if((1LL<<k)<=l){
				l-=1LL<<k;
				rs+=fs[k][x];
				rm=min(rm,fm[k][x]);
				x=ff[k][x];
			}
		}
		assert(!l);
		cout<<rs<<' '<<rm<<endl;
	}
	return 0;
}