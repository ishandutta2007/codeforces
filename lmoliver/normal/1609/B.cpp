#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=1.1e5;
int n;
char s[N];
bool valid(int x){
	char c=s[x];
	if(c=='b'||c=='c'){
		int d=c-'a';
		if(x-d<0)return false;
		if(s[x-d]!='a')return false;
		return valid(x-d);
	}
	if(x+2>=n)return false;
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}

int main(){
	n=read();
	int q=read();
	scanf("%s",s);
	int ans=0;
	D(i,n)if(s[i]=='a')ans+=valid(i);
	D(_,q){
		int x=read();
		char tmp[10];
		scanf("%s",tmp);
		ans-=valid(x-1);
		s[x-1]=tmp[0];
		ans+=valid(x-1);
		printf("%d\n",ans);
	}
	return 0;
}