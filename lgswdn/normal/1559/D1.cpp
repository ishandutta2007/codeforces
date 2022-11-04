#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,m1,m2,id1[N],id2[N],ans;
void init(int *id) {rep(i,1,n) id[i]=i;}
int find(int *id,int i) {return i==id[i]?i:id[i]=find(id,id[i]);}
void unite(int *id,int u,int v) {id[find(id,u)]=find(id,v);}
vector<pii>vec;

int main() {
	n=read(), m1=read(), m2=read();
	init(id1), init(id2);
	rep(i,1,m1) {
		int u=read(), v=read();
		unite(id1,u,v);
	}
	rep(i,1,m2) {
		int u=read(), v=read();
		unite(id2,u,v);
	}
	rep(i,1,n) rep(j,1,n) {
		if(find(id1,i)!=find(id1,j)&&find(id2,i)!=find(id2,j)) {
			ans++;
			unite(id1,i,j), unite(id2,i,j);
			vec.push_back(pii(i,j));
		}
	}
	printf("%d\n",ans);
	for(auto x:vec) printf("%d %d\n",x.first,x.second);
	return 0;
}