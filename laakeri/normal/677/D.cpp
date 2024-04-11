#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[333][333];
int a[333][333];
int fq[333*333];
vector<pair<int, int> > pos[333*333];

ll dt[333][333];

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			cin>>a[i][ii];
			fq[a[i][ii]]++;
			pos[a[i][ii]].push_back({i, ii});
			
			if (a[i][ii]==1){
				dp[i][ii]=i+ii;
			}
			else{
				dp[i][ii]=1e18;
			}
		}
	}
	for (int k=1;k<p;k++){
		if ((ll)fq[k]*(ll)fq[k+1]>(ll)n*(ll)m*(ll)10){
			priority_queue<pair<ll, pair<int, int> > > dij;
			for (int i=0;i<n;i++){
				for (int ii=0;ii<m;ii++){
					dt[i][ii]=1e18;
				}
			}
			
			for (auto t:pos[k]){
				dij.push({-dp[t.F][t.S], {t.F, t.S}});
			}
			while (!dij.empty()){
				auto x=dij.top();
				dij.pop();
				ll d=-x.F;
				if (dt[x.S.F][x.S.S]<=d) continue;
				dt[x.S.F][x.S.S]=d;
				for (int i=-1;i<=1;i++){
					for (int ii=-1;ii<=1;ii++){
						if ((i==0)^(ii==0)){
							int ny=x.S.F+i;
							int nx=x.S.S+ii;
							if (ny<0||ny>=n||nx<0||nx>=m) continue;
							if (dt[ny][nx]<=d+1) continue;
							dij.push({-d-1, {ny, nx}});
						}
					}
				}
			}
			for (auto t:pos[k+1]){
				dp[t.F][t.S]=dt[t.F][t.S];
			}
		}
		else{
			for (auto t:pos[k]){
				for (auto tt:pos[k+1]){
					dp[tt.F][tt.S]=min(dp[tt.F][tt.S], dp[t.F][t.S]+(ll)(abs(t.F-tt.F)+abs(t.S-tt.S)));
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (a[i][ii]==p){
				cout<<dp[i][ii]<<endl;
				return 0;
			}
		}
	}
}