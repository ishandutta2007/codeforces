#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=5.1e5;
char s[N];
int d[N];

void work(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	d[0]=0;
	F(i,1,n)d[i]=d[i-1]+(s[i]=='1'?1:-1);
	map<int,int> cnt;
	F(i,1,n)cnt[min(d[i-1],d[i])]++;
	int cur=0;
	D(_,n){
		bool z=
			cnt[cur-1]>=2
			||cnt[cur]==0;
		cnt[cur-z]--;
		cur+=z?-1:1;
		printf("%d",(int)!z);
	}
	printf("\n");
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}