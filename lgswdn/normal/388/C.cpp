#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;
typedef pair<int,int>pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,s[N],c[N];
vector<int>v;
int ans[2];

int main() {
	n=read();
	rep(i,1,n) {
		s[i]=read();
		rep(j,1,s[i]) c[j]=read();
		int p=s[i]/2;
		rep(j,1,p) ans[0]+=c[j];
		rep(j,p+(s[i]%2)+1,s[i]) ans[1]+=c[j];
		if(s[i]%2) v.push_back(c[p+1]);
	}
	sort(v.begin(),v.end()); reverse(v.begin(),v.end());
	int d=0;
	for(auto x:v) ans[d]+=x, d^=1;
	printf("%d %d\n",ans[0],ans[1]);
	return 0;
}