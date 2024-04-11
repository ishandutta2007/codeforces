#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

struct SuffixAutomaton {
	vector<map<int, int> > g;
	vector<int> link;
	vector<int> len;
	int last;
	void addC(int c) {
		int p=last;
		int t=link.size();
		link.push_back(0);
		len.push_back(len[last]+1);
		g.push_back(map<int, int>());
		while (p!=-1&&g[p].count(c)==0) {
			g[p][c]=t;
			p=link[p];
		}
		if (p!=-1) {
			int q=g[p][c];
			if (len[p]+1==len[q]) {
				link[t]=q;
			}
			else {
				int qq=link.size();
				link.push_back(link[q]);
				len.push_back(len[p]+1);
				g.push_back(g[q]);
				while (p!=-1&&g[p][c]==q) {
					g[p][c]=qq;
					p=link[p];
				}
				link[q]=qq;
				link[t]=qq;
			}
		}
		last=t;
	}
	SuffixAutomaton() : SuffixAutomaton("") {}
	SuffixAutomaton(string s) {
		last=0;
		g.push_back(map<int, int>());
		link.push_back(-1);
		len.push_back(0);
		for (int i=0;i<(int)s.size();i++) {
			addC(s[i]);
		}
	}
};

string s[3020202];
ll c[3020202];
ll dp[3020202];
vector<int> rg[3020202];
int ec[3020202];

vector<int> gg[3020202];
int ec2[3020202];

ll dp2[3020202];

int okv[3020202];

int n;

void dfs(int x, SuffixAutomaton& sa){
	if (okv[x]) return;
	okv[x]=1;
	for (auto nx:sa.g[x]){
		if (nx.F>n) dfs(nx.S, sa);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	SuffixAutomaton sa;
	for (int i=1;i<=n;i++){
		for (char cc:s[i]){
			sa.addC(n+(int)cc);
		}
		sa.addC(i);
	}
	int ss=sa.link.size();
	//cout<<ss<<endl;
	dfs(0, sa);
	for (int i=0;i<ss;i++){
		if (okv[i]){
			for (auto nx:sa.g[i]){
				if (nx.F<=n){
					dp[i]+=c[nx.F];
				}
				else{
					rg[nx.S].push_back(i);
					ec[i]++;
					
					gg[i].push_back(nx.S);
					ec2[nx.S]++;
				}
			}
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}
	queue<int> topo;
	for (int i=0;i<ss;i++){
		if (ec[i]==0){
			topo.push(i);
		}
	}
	while (!topo.empty()){
		int x=topo.front();
		topo.pop();
		//cout<<x<<" v "<<dp[x]<<endl;
		for (int nx:rg[x]){
			dp[nx]+=dp[x];
			ec[nx]--;
			if (ec[nx]==0){
				topo.push(nx);
			}
		}
	}
	topo.push(0);
	ll v=0;
	while (!topo.empty()){
		int x=topo.front();
		topo.pop();
		//cout<<x<<" x "<<dp2[x]<<endl;
		v=max(v, dp[x]*dp2[x]);
		for (int nx:gg[x]){
			dp2[nx]=max(dp2[nx], dp2[x]+1);
			ec2[nx]--;
			if (ec2[nx]==0){
				topo.push(nx);
			}
		}
	}
	cout<<v<<endl;
}