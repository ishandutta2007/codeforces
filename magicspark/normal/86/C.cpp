#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000009;
typedef long long ll;
struct AhoCorasick {
	static const int UNDEF = 0;
	static const int MAXN = 128;
	static const int CHARSET = 4;

	int end;
	int tag[MAXN];
	int fail[MAXN];
	int trie[MAXN][CHARSET];

	void init() {
		tag[0] = UNDEF;
		fill(trie[0], trie[0] + CHARSET, -1);
		end = 1;
	}

	void add(int m, const int* s, int t) {
		int p = 0;
		for (int i = 0; i < m; ++i) {
			if (trie[p][*s] == -1) {
				tag[end] = UNDEF;
				fill(trie[end], trie[end] + CHARSET, -1);
				trie[p][*s] = end++;
			}
			p = trie[p][*s];
			++s;
		}
		tag[p] = t;
	}

	void build() {
		queue<int> bfs;
		fail[0] = 0;
		for (int i = 0; i < CHARSET; ++i) {
			if (trie[0][i] != -1) {
				fail[trie[0][i]] = 0;
				bfs.push(trie[0][i]);
			} else {
				trie[0][i] = 0;
			}
		}
		while (!bfs.empty()) {
			int p = bfs.front();
		//	tag[p] |= tag[fail[p]];	//
			tag[p] = max(tag[p], tag[fail[p]]);
			bfs.pop();
			for (int i = 0; i < CHARSET; ++i) {
				if (trie[p][i] != -1) {
					fail[trie[p][i]] = trie[fail[p]][i];
					bfs.push(trie[p][i]);
				} else {
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}
}ac;
int n;
ll dp[1024][128][12];
int main(){
	int n,m,l;
	int a[80];
	char buf[80];
	ll ans=0;
	const char pat[]="ATCG";
	scanf("%d%d",&n,&m);
	ac.init();
	for(int i=0;i<m;i++){
		scanf("%s",buf);
		l=strlen(buf);
		for(int i=0;i<l;i++)a[i]=strchr(pat,buf[i])-pat;
		ac.add(l,a,l);
	}
	ac.build();
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<ac.end;j++){
			for(int k=0;k<12;k++){
				if(dp[i][j][k]){
					for(int t=0;t<4;t++){
						int jj=ac.trie[j][t];
						if(ac.tag[jj]>k){
							dp[i+1][jj][0]+=dp[i][j][k];
							dp[i+1][jj][0]%=mod;
						}else if(k+1<12){
							dp[i+1][jj][k+1]+=dp[i][j][k];
							dp[i+1][jj][k+1]%=mod;
						}
					}
				}
			}
		}
	}
	for(int j=0;j<ac.end;j++)ans+=dp[n][j][0];
	printf("%d\n",ans%mod);
	return 0;
}