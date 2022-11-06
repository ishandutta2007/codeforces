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

const int MOD=1000003;

int dp[11][1000007];
int c;

int ask(int x){
	cout<<"? "<<x<<endl;
	ll resp; cin>>resp;
	if(resp==-1)assert(0);
	return resp;
}

int f(int t, int x){
	int &r=dp[t][x];
	if(r>=0)return r;
	r=(f(t-1,x+1)-f(t-1,x)+MOD)%MOD; return r;
}

int g(int t, int x){
	int &r=dp[t][x];
	if(r>=0)return r;
	if(t==10)return c;
	r=(g(t+1,x-1)+g(t,x-1))%MOD; return r;
}

int main(){FIN;
	mset(dp,-1);
	fore(i,0,25){
		dp[0][i]=ask(i);
	}
	c=f(10,0);
	fore(i,0,MOD){
		if(g(0,i)==0){
			cout<<"! "<<i<<endl; return 0;
		}
	}
	
	cout<<"! -1"<<endl;
	return 0;
}