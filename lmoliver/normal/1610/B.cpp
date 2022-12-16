#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=2.1e5;
int a[N];

bool attempt(int l,int r,int x){
	V qaq;
	F(i,l,r)if(a[i]!=x)qaq.push_back(a[i]);
	D(i,qaq.size())if(qaq[qaq.size()-1-i]!=qaq[i])return false;
	return true;
}

void work(){
	int n=read();
	F(i,1,n)a[i]=read();
	int l=1,r=n;
	while(l+1<=r-1){
		if(a[l]!=a[r])break;
		l++;
		r--;
	}
	bool ans=attempt(l,r,a[l])||attempt(l,r,a[r]);
	if(ans)puts("YES");
	else puts("NO");
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}