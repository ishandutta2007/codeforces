#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int u[1110101];
int us[1010101];

int cc=0;

int getu(int a){
	if (u[a]==a) return a;
	return u[a]=getu(u[a]);
}

void un(int a, int b){
	a=getu(a);
	b=getu(b);
	if (a==b) return;
	us[b]+=us[a];
	u[a]=b;
	cc--;
}

int ac[1010][1010];

int re=0;

int ud[1010][1010];

int n,m;

void dfs(int i, int ii){
	if (i<0||ii<0||i>=n||ii>=m) return;
	if (ac[i][ii]==0) return;
	if (ud[i][ii]) return;
	ud[i][ii]=1;
	for (int j=-1;j<=1;j++){
		for (int jj=-1;jj<=1;jj++){
			if ((j==0)^(jj==0)) {
				dfs(i+j, ii+jj);
			}
		}
	}
	if (re){
		ac[i][ii]=0;
		re--;
	}
}

void ok(ll v, ll nt, ll ne, int ri, int rii){
	re=nt-ne;
	dfs(ri, rii);
	cout<<"YES\n";
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (ac[i][ii]&&ud[i][ii]){
				cout<<v<<" ";
			}
			else{
				cout<<"0 ";
			}
		}
		cout<<'\n';
	}
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll k;
	cin>>n>>m>>k;
	ll su=0;
	vector<pair<ll, pair<int, int> > > t;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			u[i*m+ii]=i*m+ii;
			us[i*m+ii]=1;
			ll c;
			cin>>c;
			t.push_back({c, {i, ii}});
			su+=c;
		}
	}
	sort(t.rbegin(), t.rend());
	ll nt=0;
	for (auto tt:t){
		nt++;
		cc++;
		ac[tt.S.F][tt.S.S]=1;
		for (int i=-1;i<=1;i++){
			for (int ii=-1;ii<=1;ii++){
				if ((i==0)^(ii==0)){
					if (tt.S.F+i>=0&&tt.S.F+i<n&&tt.S.S+ii>=0&&tt.S.S+ii<m){
						if (ac[tt.S.F+i][tt.S.S+ii]){
							un(tt.S.F*m+tt.S.S, (tt.S.F+i)*m+tt.S.S+ii);
						}
					}
				}
			}
		}
		//if (cc==1) cout<<tt.F<<" "<<tt.S.F<<" "<<tt.S.S<<endl;
		if (k%tt.F==0){
			ll ne=k/tt.F;
			if ((ll)us[getu(tt.S.F*m+tt.S.S)]>=ne){
				ok(tt.F, (ll)us[getu(tt.S.F*m+tt.S.S)], ne, tt.S.F, tt.S.S);
			}
		}
	}
	cout<<"NO"<<endl;
}