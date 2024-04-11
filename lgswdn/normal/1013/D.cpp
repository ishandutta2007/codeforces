#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=400009;
typedef pair<int,int> pii;
typedef vector<int> vi;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,m,k,id[N],ans,s[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}
void unite(int u,int v) {id[find(u)]=find(v);}

int main() {
	n=read(), m=read(), k=read();
	rep(i,1,n+m) id[i]=i;
	rep(i,1,k) {
		int x=read(), y=read();
		unite(x,y+n);
	}
	rep(i,1,n+m) if(find(i)==i) ans++;
	printf("%d\n",ans-1);
	return 0;
}