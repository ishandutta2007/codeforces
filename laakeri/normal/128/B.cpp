#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

struct suffixAutomaton{
	vector<map<char, int> > g;
	vector<int> link;
	vector<int> len;
	int last;
	void addC(char c){
		int p=last;
		int t=link.size();
		link.push_back(0);
		len.push_back(len[last]+1);
		g.push_back(map<char, int>());
		while (p!=-1&&g[p].count(c)==0){
			g[p][c]=t;
			p=link[p];
		}
		if (p!=-1){
			int q=g[p][c];
			if (len[p]+1==len[q]){
				link[t]=q;
			}
			else{
				int qq=link.size();
				link.push_back(link[q]);
				len.push_back(len[p]+1);
				g.push_back(g[q]);
				while (p!=-1&&g[p][c]==q){
					g[p][c]=qq;
					p=link[p];
				}
				link[q]=qq;
				link[t]=qq;
			}
		}
		last=t;
	}
	suffixAutomaton() : suffixAutomaton(""){}
	suffixAutomaton(string s){
		last=0;
		g.push_back(map<char, int>());
		link.push_back(-1);
		len.push_back(0);
		for (int i=0;i<(int)s.size();i++){
			addC(s[i]);
		}
	}
};

ll dp[202020];
ll dp2[202020];
vector<int> rg[202020];
int ec[202020];

int main(){
	string s;
	ll k;
	cin>>s>>k;
	suffixAutomaton sa(s);
	for (int t=sa.last;t!=-1;t=sa.link[t]){
		dp[t]=1;
	}
	dp[0]=0;
	int as=sa.link.size();
	for (int i=0;i<as;i++){
		for (auto nx:sa.g[i]){
			rg[nx.S].push_back(i);
			ec[i]++;
		}
	}
	queue<int> topo;
	for (int i=0;i<as;i++){
		if (ec[i]==0){
			topo.push(i);
		}
	}
	while (!topo.empty()){
		int x=topo.front();
		topo.pop();
		if (x==0) dp[x]=0;
		dp2[x]+=dp[x];
		for (int nx:rg[x]){
			dp[nx]+=dp[x];
			dp2[nx]+=dp2[x];
			ec[nx]--;
			if (ec[nx]==0){
				topo.push(nx);
			}
		}
	}
	int t=0;
	string v="";
	while (1){
		k-=dp[t];
		if (k<=0){
			cout<<v<<endl;
			return 0;
		}
		int f=0;
		for (auto nx:sa.g[t]){
			if (dp2[nx.S]<k){
				k-=dp2[nx.S];
			}
			else{
				f=1;
				t=nx.S;
				v+=nx.F;
				break;
			}
		}
		if (f==0){
			cout<<"No such line."<<endl;
			return 0;
		}
	}
}