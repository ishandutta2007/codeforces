#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

const int N=55;
LL dp[N][N][N];
LL t[5],su[2];
bool like[55];
LL w[55];

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=MAX){
	//p_a^p_n mod p_p
	long long int p_b=1,p_t=1;
	for(;p_b<=p_n;p_b<<=1);
	for(p_b>>=1;p_b>0;p_b>>=1){
		p_t*=p_t;
		if(p_t>=p_p)p_t%=p_p;
		if(p_n&p_b)p_t*=p_a;
		if(p_t>=p_p)p_t%=p_p;
	}
	return p_t;
}

LL divi(LL a,LL b){
	a*=pow_mod(b,MAX-2);
	if(a>=MAX)a%=MAX;
	return a;
}

int main(){
	LL n,m;
	LL i,j,k;
	int p,q;
	LL a,b,c;
	LL s=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		if(a==1)like[i]=true;
	}
	for(i=0;i<n;i++){
		cin>>w[i];
		if(like[i])su[0]+=w[i];
		else su[1]+=w[i];
	}
	for(p=0;p<n;p++){
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		t[0]=w[p],t[1]=su[0],t[2]=su[1];
		if(like[p])t[1]-=w[p],t[3]=1;
		else t[2]-=w[p],t[3]=-1;
		s=0;
		for(i=0;i<=m;i++){
			for(j=0;j<=m;j++){
				for(k=0;k<=m;k++){
					if(i+j+k>m)break;
					if(i+j+k==m){
						s+=dp[i][j][k]*(t[0]+t[3]*i);
						if(s>=MAX)s%=MAX;
						break;
					}
					a=t[0]+t[3]*i+t[1]+j+t[2]-k;
					dp[i+1][j][k]+=dp[i][j][k]*divi(t[0]+t[3]*i,a);
					dp[i][j+1][k]+=dp[i][j][k]*divi(t[1]+j,a);
					dp[i][j][k+1]+=dp[i][j][k]*divi(t[2]-k,a);
					if(dp[i+1][j][k]>=MAX)dp[i+1][j][k]%=MAX;
					if(dp[i][j+1][k]>=MAX)dp[i][j+1][k]%=MAX;
					if(dp[i][j][k+1]>=MAX)dp[i][j][k+1]%=MAX;
				}
			}
		}
		cout<<s<<endl;
	}
}