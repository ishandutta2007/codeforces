#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,c,q,x,y,f[N];
char op;
set<int>s[N];
map<int,vector<int> >e[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return;
	if(s[fx].size()>s[fy].size())
		swap(fx,fy);
	f[fx]=fy;
	for(int i:s[fx])
		s[fy].insert(i);
	s[fx].clear();
}
void add(int x,int y,int c){
	int fx=find(x),fy=find(y);
	s[fx].insert(y),s[fy].insert(x);
	if(e[x][c].size())
		merge(fy,e[x][c][0]);
	if(e[y][c].size())
		merge(fx,e[y][c][0]);
	e[x][c].push_back(y);
	e[y][c].push_back(x);
}
int ask(int x,int y){
	int fx=find(x),fy=find(y);
	return fx==fy||s[fx].count(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>c>>q;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(m--)
		cin>>x>>y>>c,add(x,y,c);
	while(q--)
		cin>>op>>x>>y,op=='+'?cin>>c,add(x,y,c):
		void(cout<<(ask(x,y)?"Yes\n":"No\n"));
}