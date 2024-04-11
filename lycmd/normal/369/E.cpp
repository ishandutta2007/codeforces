#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,tr[N],ans[N];
vector<int>t;
vector<array<int,3> >p;
void add(int x,int y=1){
	for(;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	return x?ask(x&(x-1))+tr[x]:0;
} 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1,l,r;i<=n;i++)
		cin>>l>>r,p.push_back({-l,r,0});
	for(int i=1,c;i<=m;i++){
		cin>>c,t.resize(c+2),t[0]=0,t[c+1]=N;
		for(int j=1;j<=c;j++)
			cin>>t[j];
		for(int j=1;j<=c+1;j++)
			if(t[j-1]<t[j]-1)
				p.push_back({-t[j-1]-1,t[j]-1,i});
	}
	sort(p.begin(),p.end());
	for(auto&i:p)
		if(i[2])
			ans[i[2]]+=ask(i[1]);
		else
			add(i[1]);
	for(int i=1;i<=m;i++)
		cout<<n-ans[i]<<"\n";
}