#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXRES=40;
const int MAXRESLEN=20;
const int MAXLINE=40;
const int MAXLINELEN=80;
char buff[1000000];

int nres;
char res[MAXRES][MAXRESLEN+1];
int nline;
char line[MAXLINE][MAXLINELEN+3];

struct TNode { int nxt[128],id; TNode() { memset(nxt,-1,sizeof(nxt)); id=-1; } };
vector<TNode> trie; int trierootidx;
void printtrie(int at,int dep=0) { REP(x,128) { int to=trie[at].nxt[x]; if(to==-1) continue; REP(i,dep) printf(" "); printf("%c",(char)x); if(trie[to].id!=-1) printf(" = %d",trie[to].id); puts(""); printtrie(to,dep+1); } }

const int RESERVED=0;
const int NUMBER=1;
const int WORD=2;
struct Tok { int kind; string s; int id; Tok() {} Tok(int kind,string s,int id):kind(kind),s(s),id(id) {} };

vector<Tok> tokens;
vector<string> words;
map<string,int> word2idx;
vector<string> replacements;
bool iswordchar(char c) { return isalnum(c)||c=='_'||c=='$'; }
void recreplacement(int at,int rem,string s) { if(SZ(replacements)>=SZ(words)) return; if(rem==0) { if(at!=-1&&trie[at].id!=-1) return; replacements.PB(s); return; } REP(i,26) recreplacement(at==-1?-1:trie[at].nxt[(int)('a'+i)],rem-1,s+string(1,'a'+i)); }

void solve() {
	//printf("res:"); REP(i,nres) printf(" '%s'",res[i]); puts("");
	//REP(i,nline) printf("'%s' [%d]\n",line[i],strlen(line[i]));
	
	trie.clear(); trie.PB(TNode()); trierootidx=0;
	REP(i,nres) {
		int at=trierootidx,len=strlen(res[i]);
		REP(j,len) {
			int x=(int)res[i][j];
			if(trie[at].nxt[x]==-1) { trie[at].nxt[x]=SZ(trie); trie.PB(TNode()); }
			at=trie[at].nxt[x];
		}
		assert(trie[at].id==-1); trie[at].id=i;
	}
	//printtrie(trierootidx);
	
	tokens.clear();
	REP(i,nline) {
		int idx=0,linelen=strlen(line[i]);
		while(idx<linelen&&line[i][idx]!='#') {
			if(line[i][idx]==' ') { ++idx; continue; }
			int resid=-1,reslen=0; { int at=trierootidx,len=0; while(at!=-1) { if(trie[at].id!=-1) resid=trie[at].id,reslen=len; if(idx+len>=linelen) break; int x=(int)line[i][idx+len]; at=trie[at].nxt[x],++len; } }
			int numlen=0; while(idx+numlen<linelen&&isdigit(line[i][idx+numlen])) ++numlen;
			int wrdlen=0; if(numlen==0) while(idx+wrdlen<linelen&&iswordchar(line[i][idx+wrdlen])) ++wrdlen;
			//printf("line %d char %d: reslen=%d numlen=%d wrdlen=%d '%s'\n",i,idx,reslen,numlen,wrdlen,line[i]+idx);
			assert(reslen>0||numlen>0||wrdlen>0); int clen=max(reslen,max(numlen,wrdlen)); string s(line[i]+idx,line[i]+idx+clen);
			if(reslen>=max(numlen,wrdlen)) tokens.PB(Tok(RESERVED,s,resid)); else if(numlen>=wrdlen) tokens.PB(Tok(NUMBER,s,-1)); else tokens.PB(Tok(WORD,s,-1));
			idx+=clen;
		}
	}
	//REPSZ(i,tokens) printf(" %c'%s'","RNW"[tokens[i].kind],tokens[i].s.c_str()); puts("");
	
	words.clear(); word2idx.clear();
	REPSZ(i,tokens) if(tokens[i].kind==WORD) { string s=tokens[i].s; if(!word2idx.count(s)) { words.PB(s); word2idx[s]=SZ(words)-1; } tokens[i].id=word2idx[s]; }
	replacements.clear(); for(int len=1;SZ(replacements)<SZ(words);++len) recreplacement(trierootidx,len,"");
	REPSZ(i,tokens) if(tokens[i].kind==WORD) tokens[i].s=replacements[tokens[i].id];
	//REPSZ(i,tokens) printf(" %c'%s'","RNW"[tokens[i].kind],tokens[i].s.c_str()); puts("");
	
	vector<int> triepos; bool cannumber=false,canword=false;
	REPSZ(i,tokens) {
		bool ok=true; vector<int> ntriepos;
		REPSZ(j,triepos) { int at=triepos[j]; REPSZ(k,tokens[i].s) { int x=(int)tokens[i].s[k]; at=trie[at].nxt[x]; if(at==-1) break; if(trie[at].id!=-1) ok=false; } if(at!=-1) ntriepos.PB(at); }
		if(canword&&iswordchar(tokens[i].s[0])) ok=false;
		if(cannumber&&isdigit(tokens[i].s[0])) ok=false;
		if(!ok) { ntriepos.clear(); printf(" "); }
		printf("%s",tokens[i].s.c_str());
		{ int at=trierootidx; REPSZ(k,tokens[i].s) { int x=(int)tokens[i].s[k]; at=trie[at].nxt[x]; if(at==-1) break; } if(at!=-1) ntriepos.PB(at); }
		triepos=ntriepos;
		cannumber=true,canword=canword&&ok||!isdigit(tokens[i].s[0]);
		REPSZ(k,tokens[i].s) { if(!isdigit(tokens[i].s[k])) cannumber=false; if(!iswordchar(tokens[i].s[k])) canword=false; }
	}
	puts("");
}

void run() {
	gets(buff); sscanf(buff,"%d",&nres);
	gets(buff); { int offset=0; REP(i,nres) { while(buff[offset]==' ') ++offset; sscanf(buff+offset,"%s",res[i]); offset+=strlen(res[i]); } }
	gets(buff); sscanf(buff,"%d",&nline);
	REP(i,nline) gets(line[i]);
	solve();
}

int main() {
	run();
	return 0;
}