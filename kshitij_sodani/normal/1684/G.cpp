#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)


#pragma GCC optimize("O3,unroll-loops")


using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct Kuhn {
    int N, M;
    vector<vector<int>> E;
    vector<int> matchA, matchB;
    vector<bool> vis;
    Kuhn(int N, int M) : N(N), M(M), E(N), matchA(N, -1), matchB(M, -1), vis(N) {}
    void add_edge(int u, int v) {
        E[u].push_back(v);
    }
    bool augment(int u) {
        vis[u] = true;
        for (auto v : E[u]) {
            int w = matchB[v];
            if (w == -1 || (not vis[w] && augment(w))) {
                matchA[u] = v, matchB[v] = u;
                return true;
            }
        }
        return false;
    }
    int mx = 0;
    int maximum_matching() {
        while (true) {
            bool converged = true;
            fill(all(vis), false);
            for (int u = 0; u < N; ++u) {
                if (not vis[u] && matchA[u] == -1 && augment(u)) {
                    converged = false;
                    ++mx;
                }
            }
            if (converged) break;
        }
        return mx;
    }
};
int it[1001];
vector<int> ee[1001];



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>it[i];
		if(it[i]*2>=m){
			cout<<-1<<endl;
			return 0;
		}
		for(int j=1;j*j<=it[i];j++){
			if(it[i]%j==0){
				ee[i].pb(j);
				ee[i].pb(it[i]/j);
			}
		}
	}
	vector<int> ss;
	vector<int> tt;
	for(int i=0;i<n;i++){
		if(it[i]*3>m){
			ss.pb(i);
		}
		else{
			tt.pb(i);
		}
	}
	if(ss.size()>tt.size()){
		cout<<-1<<endl;
		return 0;
	}
	set<int> cur3;
	for(int j=0;j<tt.size();j++){
		cur3.insert(j);
	}
	
	 vector<pair<int,int>> kk;
	 int ind=-1;
	for(auto i:ss){
	    ind++;
	    int ind2=-1;
		for(auto j:tt){
		    ind2++;
			if((it[i]%it[j])==0){
				if(2*it[i]+it[j]<=m){
					kk.pb({ind,ind2});
				}
			}
		}
	}
	Kuhn kuhn((int)ss.size(),(int)tt.size());
    
	 for(auto j:kk){
	 	kuhn.add_edge(j.a,j.b);
	 }
	 kuhn.maximum_matching();
	 for(int i=0;i<ss.size();i++){
	    if(kuhn.matchA[i]==-1){
	         cout<<-1<<endl;
	         return 0;
	     }
	    // cout<<i<<":"<<kuhn.matchA[i]<<endl;
	 }
	// return 0;

	cout<<tt.size()<<endl;
		  for (int i = 0; i < ss.size(); i++){
		  	llo aa3=it[ss[i]];
	  	llo bb3=it[tt[kuhn.matchA[i]]];
		  	cout<<(2*aa3+bb3)<<" "<<(aa3+bb3)<<endl;
		  	cur3.erase(kuhn.matchA[i]);
		  }
		  for(auto jj:cur3){
		  	cout<<(3*it[tt[jj]])<<" "<<(2*it[tt[jj]])<<endl;
		  }







	return 0;
}