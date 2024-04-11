#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v)) 
typedef long long ll;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

char buff[100];

typedef struct Node {
	string s;
	int mask;
	int value;
	vector<int> next;
	Node(string s):s(s) { mask=value=0; next=vector<int>(); }
} Node;


bool better(int r1,int m1,int o1,int r2,int m2,int o2) {
	if(r1!=r2) return r1>r2;
	if(m1!=m2) return m1>m2;
	if(o1!=o2) return o1<o2;
	return false;
}

void run() {
	int n; scanf("%d",&n);
	vector<string> words; REP(i,n) { scanf("%s",buff); words.PB(buff); }
	
	map<string,int> s2i;
	vector<Node> nodes;
	REP(i,n) REPSZ(j,words[i]) FORSZ(k,j-1,words[i]) {
		string s=words[i].substr(j,k-j+1);
		int at;
		if(!s2i.count(s)) {
			nodes.PB(Node(s));
			at=s2i[s]=SZ(nodes)-1;
		} else {
			at=s2i[s];
		}
	}
	int start=s2i[""];
	REP(i,n) REPSZ(j,words[i]) FORSZ(k,j-1,words[i]) {
		string s=words[i].substr(j,k-j+1);
		int at=s2i[s];
		nodes[at].mask|=1<<i;
		if(j>0) {
			string s1=words[i].substr(j-1,k-j+2);
			nodes[at].next.PB(s2i[s1]);
		}
		if(k+1<SZ(words[i])) {
			string s2=words[i].substr(j,k-j+2);
			nodes[at].next.PB(s2i[s2]);
		}
	}
	REPSZ(i,nodes) {
		sort(nodes[i].next.begin(),nodes[i].next.end());
		nodes[i].next.erase(unique(nodes[i].next.begin(),nodes[i].next.end()),nodes[i].next.end());
		int sum=0,max=0;
		REPSZ(j,nodes[i].s) { int x=nodes[i].s[j]-'a'+1; sum+=x; if(x>max) max=x; }
		nodes[i].value=sum*max;
		REP(j,n) if(nodes[i].mask&(1<<j)) ++nodes[i].value;
	}
	vector<pair<int,int> > order; REPSZ(i,nodes) order.PB(MP(SZ(nodes[i].s),i)); sort(order.begin(),order.end());
	vector<int> result(SZ(nodes));
	vector<int> mypoints(SZ(nodes));
	vector<int> opppoints(SZ(nodes));
	for(int i=SZ(order)-1;i>=0;--i) {
		int at=order[i].second;
		result[at]=-1; mypoints[at]=opppoints[at]=0;
		REPSZ(j,nodes[at].next) {
			int to=nodes[at].next[j];
			int nresult=-result[to],nmypoints=opppoints[to]+nodes[to].value,nopppoints=mypoints[to];
			if(better(nresult,nmypoints,nopppoints,result[at],mypoints[at],opppoints[at])) result[at]=nresult,mypoints[at]=nmypoints,opppoints[at]=nopppoints;
		}
	}
	printf("%s\n",result[start]==+1?"First":"Second");
	printf("%d %d\n",mypoints[start],opppoints[start]);
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}