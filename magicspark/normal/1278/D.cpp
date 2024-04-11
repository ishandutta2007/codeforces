#include<bits/stdc++.h>
using namespace std;
int n;
int l[500005],r[500005];
vector<int>st[1000005],ed[1000005];
int par[500005];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void add_edge(int x,int y){
//    cout<<x<<" "<<y<<endl;
    if(find(x)==find(y)){
	puts("NO");
	exit(0);
    }
    par[find(x)]=find(y);
}
int main(){
    for(int i=1;i<=500000;i++)par[i]=i;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&l[i],&r[i]);
	st[l[i]].push_back(i);
	ed[r[i]].push_back(i);
    }
    set<pair<int,int> >has;
    for(int i=1;i<=1e6;i++){
	for(int j=0;j<st[i].size();j++){
	    has.insert(make_pair(i,st[i][j]));
	}
	for(int j=0;j<ed[i].size();j++){
	    auto itr=has.find(make_pair(l[ed[i][j]],ed[i][j]));
	    has.erase(itr++);
	    while(itr!=has.end()){
		add_edge(ed[i][j],itr->second);itr++;
	    }
	}
    }
    for(int i=2;i<=n;i++)if(find(i)!=find(1)){puts("NO");return 0;}
    puts("YES");
    return 0;
}