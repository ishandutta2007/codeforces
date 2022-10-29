#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
#define M 300005
using namespace std;

typedef long long ll;

int s2[M+1024];

void doit(int *s, int a, int k, int t){
	s[100105+a-1]=1;
	s[100105+a]=-1;
	fore(_,0,t){
		memset(s2,0,sizeof(s2));
		int q=0;
		fore(i,1024,M){
			q+=s[i];q%=MOD;
			s2[i-k]+=q;
			s2[i-k]%=MOD;
			s2[i+k+1]+=MOD-q;
			s2[i+k+1]%=MOD;
		}
		memcpy(s,s2,sizeof(s2));
	}
}

int s0[M+1024];
int s1[M+1024];
int w[M];
int a,b,k,t;


int main(){
	scanf("%d%d%d%d",&a,&b,&k,&t);
	doit(s0,a,k,t);
	doit(s1,b,k,t);
	int q=0,s=0;
	fore(i,0,M){
		q+=s1[i];q%=MOD;
		s+=q;s%=MOD;
		w[i+1]=s;
	}
	int r=0;q=0;
	fore(i,0,M){
		q+=s0[i];q%=MOD;
		r+=(1LL*q*w[i])%MOD;
		r%=MOD;
	}
	printf("%d\n",r);
	return 0;
}