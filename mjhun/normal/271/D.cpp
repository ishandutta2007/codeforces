#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

char s[2048];
char g[256];
map<char,int> t[1<<21];
int nt,q,r;

void add(char *s){
	int k=0;
	for(int i=0;s[i];++i){
		if(t[k].find(s[i])==t[k].end())t[k][s[i]]=nt++;
		k=t[k][s[i]];
	}
}

void dfs(int x, int w){
	if(w>q)return;
	r++;
	for(map<char,int>::iterator it=t[x].begin();it!=t[x].end();++it){
		dfs(it->second,w+1-g[it->fst]);
	}
}

int main(){
	scanf("%s%s%d",s,g+'a',&q);
	fore(i,'a','z'+1)g[i]-='0';
	nt=1;
	for(int i=0;s[i];++i){
		add(s+i);
	}
	dfs(0,0);
	printf("%d\n",r-1);
	return 0;
}