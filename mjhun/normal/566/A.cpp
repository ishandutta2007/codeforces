#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

map<char,int> t[1<<20];
int f[1<<20];
set<int> q[1<<20][2];
string s[2][100005];
vector<pair<int,int> > sol;
stack<int> st[2];
int n,nt;

void add(string &s, int w, int j){
	int k=0;
	q[0][w].insert(j);
	fore(i,0,s.size()){
		if(!t[k][s[i]]){t[k][s[i]]=nt++;f[nt-1]=k;}
		k=t[k][s[i]];
		q[k][w].insert(j);
	}
}

int lcp(string &s1, string &s2){
	int r=0;
	fore(i,0,min(s1.size(),s2.size())){
		if(s1[i]!=s2[i])break;
		r++;
	}
	return r;
}

void dfs(int x){
	for(map<char,int>::iterator it=t[x].begin();it!=t[x].end();++it)dfs(it->snd);
	set<int>::iterator it0=q[x][0].begin(),it1=q[x][1].begin();
	int k=min(q[x][0].size(),q[x][1].size());
	fore(i,0,k){
		int j0=*it0,j1=*it1;
		int p=f[x];
		while(p>=0){
			q[p][0].erase(j0);
			q[p][1].erase(j1);
			p=f[p];
		}
		sol.pb(mp(j0,j1));
		it0++;it1++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;nt=1;f[0]=-1;
	fore(k,0,2){
		fore(i,0,n){
			cin>>s[k][i];
			add(s[k][i],k,i);
		}
	}
	dfs(0);
	assert(sol.size()==n);
	int r=0;
	fore(i,0,n){
		r+=lcp(s[0][sol[i].fst],s[1][sol[i].snd]);
	}
	printf("%d\n",r);
	fore(i,0,n)printf("%d %d\n",sol[i].fst+1,sol[i].snd+1);
	return 0;
}