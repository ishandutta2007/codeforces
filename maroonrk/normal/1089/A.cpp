#include <bits/stdc++.h>
using namespace std;

using ll=long long;

//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

ll read(){
	ll i;
	scanf("%lld",&i);
	return i;
}

void print(ll x){
	printf("%lld\n",x);
}

using vi=vector<int>;
using pi=pair<int,int>;
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back

const int sp[]={25,25,25,25,15};

bool Sub(int a,int b,vi wl,int di){
	int ans[5][2]{},ad[5][2]{};
	int n=wl.size();
	REP(i,n){
		REP(j,2){
			if(wl[i]!=j){
				ans[i][j]=sp[i];
			}else{
				if(di==i){
					ans[i][j]=sp[i]-2;
				}else{
					ad[i][j]=sp[i]-2;
				}
			}
		}
	}
	int arem=a,brem=b,amax=0,bmax=0;
	REP(i,n){
		arem-=ans[i][0];
		brem-=ans[i][1];
		
		amax+=ad[i][0];
		bmax+=ad[i][1];
	}
	if(arem<0||brem<0)
		return false;
	if(di!=-1){
		int p=min(arem,brem);
		ans[di][0]+=p;
		ans[di][1]+=p;
		arem-=p;
		brem-=p;
	}
	if(arem<=amax&&brem<=bmax){
		REP(i,n){
			int p=min(arem,ad[i][0]);
			ans[i][0]+=p;
			arem-=p;
			
			int q=min(brem,ad[i][1]);
			ans[i][1]+=q;
			brem-=q;
		}
		assert(arem==0);
		assert(brem==0);
		
		int aWin=0,bWin=0;
		REP(i,n)
			if(wl[i]==1)
				aWin++;
			else
				bWin++;
		
		printf("%d:%d\n",aWin,bWin);
		REP(i,n){
			printf("%d:%d",ans[i][0],ans[i][1]);
			if(i==n-1)
				printf("\n");
			else
				printf(" ");
		}
		return true;
	}else
		return false;
}

void Solve(){
	int a=read(),b=read();
	if(Sub(a,b,{1,1,1},-1))
		return;
	if(Sub(a,b,{1,1,1},0))
		return;
	if(Sub(a,b,{1,1,0,1},-1))
		return;
	if(Sub(a,b,{1,1,0,1},0))
		return;
	if(Sub(a,b,{1,1,0,1},2))
		return;
	if(Sub(a,b,{1,1,0,0,1},-1))
		return;
	if(Sub(a,b,{1,1,0,0,1},2))
		return;
	if(Sub(a,b,{1,1,0,0,1},4))
		return;
	if(Sub(a,b,{0,0,1,1,0},-1))
		return;
	if(Sub(a,b,{0,0,1,1,0},2))
		return;
	if(Sub(a,b,{0,0,1,1,0},4))
		return;
	if(Sub(a,b,{0,0,1,0},-1))
		return;
	if(Sub(a,b,{0,0,1,0},0))
		return;
	if(Sub(a,b,{0,0,1,0},2))
		return;
	if(Sub(a,b,{0,0,0},-1))
		return;
	if(Sub(a,b,{0,0,0},0))
		return;
	printf("Impossible\n");
}

signed main(){
	int t=read();
	REP(i,t)
		Solve();
}