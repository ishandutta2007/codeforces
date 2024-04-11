#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

struct SuffixAutomaton {
	vector<map<char, int> > g;
	vector<int> link;
	vector<int> len;
	int last;
	void addC(char c) {
		int p=last;
		int t=link.size();
		link.push_back(0);
		len.push_back(len[last]+1);
		g.push_back(map<char, int>());
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
		g.push_back(map<char, int>());
		link.push_back(-1);
		len.push_back(0);
		for (int i=0;i<(int)s.size();i++) {
			addC(s[i]);
		}
	}
	vector<int> terminals() {
		vector<int> t;
		int p=last;
		while (p>0) {
			t.push_back(p);
			p=link[p];
		}
		return t;
	}
};

int dp[2020202];
int ec[2020202];
vector<int> eg[2020202];

int ps[2020202];

const int N=1<<19;
int st[2*N];

int getmin(int a, int b){
    a+=N;
    b+=N;
    int mi=1e6;
    while (a<=b){
        if (a%2) mi=min(mi, st[a++]);
        if (!(b%2)) mi=min(mi, st[b--]);
        a/=2;
        b/=2;
    }
    return mi;
}

vector<int> h[2020202];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=1;i<=n;i++){
        ps[i]=ps[i-1];
        if (s[i-1]=='(') ps[i]++;
        else ps[i]--;

        h[ps[i]+n].push_back(i);
    }
    for (int i=0;i<=n;i++){
        st[i+N]=ps[i];
    }
    for (int i=N-1;i;i--){
        st[i]=min(st[i*2], st[i*2+1]);
    }
    SuffixAutomaton sa(s);
    int ss=sa.link.size();
    for (int i=0;i<ss;i++){
        for (auto nx:sa.g[i]){
            eg[nx.S].push_back(i);
            ec[i]++;
        }
    }
    queue<int> topo;
    for (int i=0;i<ss;i++){
        dp[i]=-2*n;
        if (ec[i]==0) topo.push(i);
    }
    vector<int> te=sa.terminals();
    for (int t:te){
        dp[t]=0;
    }
    while (!topo.empty()){
        int x=topo.front();
        topo.pop();
        for (int nx:eg[x]){
            dp[nx]=max(dp[nx], dp[x]+1);
            ec[nx]--;
            if (ec[nx]==0){
                topo.push(nx);
            }
        }
    }
    int x=0;
    int le=0;
    ll v=0;
    for (int i=0;i<n;i++){
        int f=0;
        while (dp[x]+le>n-i){
            if (i+le>=n||sa.g[x].count(s[i+le])==0){
                f=1;
                break;
            }
            else{
                x=sa.g[x][s[i+le]];
                le++;
            }
        }
        if (f) break;
        int mi=i+le;
        int ma=n;
        int ff=i+le;
        if (s[i]==')') goto loppu;
        if (getmin(i, i+le)-ps[i]<0) goto loppu;
        if ((int)h[ps[i]+n].size()==0) goto loppu;
        while (mi<=ma){
            int mid=(mi+ma)/2;
            if (getmin(i, mid)-ps[i]<0) {
                ma=mid-1;
            }
            else{
                ff=mid;
                mi=mid+1;
            }
        }
        //cout<<i<<" "<<i+le<<" "<<ff<<endl;
        v+=(ll)(upper_bound(h[ps[i]+n].begin(), h[ps[i]+n].end(), ff)-lower_bound(h[ps[i]+n].begin(), h[ps[i]+n].end(), i+le));
        loppu:;
        if (x!=0){
            if (sa.len[sa.link[x]]==le-1){
                x=sa.link[x];
            }
            le--;
        }
    }
    cout<<v<<endl;
}