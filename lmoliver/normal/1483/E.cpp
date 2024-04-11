#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

LL b;
int cnt;
// LL m;
bool query(LL x){
	if(x>(LL)1e14)return false;
	// cerr<<"#"<<++cnt<<endl;

	printf("? %lld\n",x);
	fflush(stdout);
	char tmp[20];
	scanf("%s",tmp);

	// tmp[1]=x<=m?'u':b>=x?'r':'i';
	// cerr<<tmp[1]<<endl;

	if(tmp[1]=='u'){
		b+=x;
		return true;
	}
	else if(tmp[1]=='r'){
		b-=x;
		return false;
	}
	else if(tmp[1]=='i'){
		cerr<<"Oh no!"<<endl;
		exit(0);
	}
	else abort();
}

const int K=53;
LL dp[K][2*K];

void work(){
	// cin>>m;
	b=1;
	cnt=0;
	LL x=b;
	while(query(b))x=b;
	LL l=x/2,r=min(x-1,(LL)1e14);
	while(l<r){
		while(b<r)query(l);
		LL c=b/r;
		// cerr<<c<<endl;
		F(i,1,K-1)if(dp[i][c]>=r-l+1){
			LL mid=min(l+dp[i-1][c-1],r);
			assert(mid>l);
			assert(mid<=r);
			if(query(mid))l=mid;
			else r=mid-1;
			break;
		}
		else if(i==K-1)abort();
	}
	printf("! %lld\n",l);
}

int main(){
	D(i,2*K)dp[0][i]=1;
	F(i,1,K-1)D(j,2*K-1){
		if(j)dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
		else dp[i][j]=dp[i-1][j+1];
	}
	// cerr<<dp[K-1][0]<<endl;
	// cerr<<dp[K-1][1]<<endl;
	// cerr<<dp[K-1][K-1]<<endl;

	int t=read();
	D(_,t)work();
	return 0;
}