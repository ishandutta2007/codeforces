#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,m1,m2,id1[N],id2[N],c1[N],c2[N],ans;
void init(int *id) {rep(i,1,n) id[i]=i;}
int find(int *id,int i) {return i==id[i]?i:id[i]=find(id,id[i]);}
void unite(int *id,int u,int v) {id[find(id,u)]=find(id,v);}
vector<pii>vec;
vector<int>ar1,ar2;

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
	int s=rand()%n+1;
	rep(i,1,n) {
		c1[i]=(find(id1,i)==find(id1,s));
		c2[i]=(find(id2,i)==find(id2,s));
	}
	rep(i,1,n) if((find(id1,i)==find(id1,s))+(find(id2,i)==find(id2,s))==0)
		vec.push_back(pii(s,i)), unite(id1,s,i), unite(id2,s,i);
	rep(i,1,n) {
		if(find(id1,i)!=find(id1,s)) ar1.push_back(i), unite(id1,s,i);
		if(find(id2,i)!=find(id2,s)) ar2.push_back(i), unite(id2,s,i);
	}
	int sz=min(ar1.size(),ar2.size());
	rep(i,0,sz-1) {
		vec.push_back(pii(ar1[i],ar2[i]));
	}
	ans=vec.size();
	printf("%d\n",ans);
	for(auto x:vec) printf("%d %d\n",x.first,x.second);
	return 0;
}