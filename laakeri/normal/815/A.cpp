#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
	cout<<-1<<endl;
	exit(0);
}

int d[111];

int a[111][111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int mi=1e9;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			cin>>a[i][ii];
			mi=min(mi, a[i][ii]);
		}
	}
	vector<pair<int, int> > ans;
	for (int i=0;i<mi;i++){
		if (n<m){
			for (int j=0;j<n;j++){
				ans.push_back({0, j});
			}
		}
		else{
			for (int j=0;j<m;j++){
				ans.push_back({1, j});
			}
		}
	}
	int zr=-1;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			a[i][ii]-=mi;
			if (a[i][ii]==0){
				zr=ii;
			}
		}
	}
	assert(zr>=0);
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (a[i][ii]-a[i][0]!=a[0][ii]-a[0][0]){
				nie();
			}
		}
	}
	for (int ii=0;ii<m;ii++){
		int ch=a[0][ii]-a[0][zr];
		if (ch<0) nie();
		for (int j=0;j<ch;j++) ans.push_back({1, ii});
		for (int i=0;i<n;i++){
			a[i][ii]-=ch;
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=1;ii<m;ii++){
			if (a[i][ii]!=a[i][ii-1]) nie();
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<a[i][0];j++) ans.push_back({0, i});
	}
	cout<<ans.size()<<endl;
	for (auto t:ans){
		if (t.F==0) cout<<"row "<<t.S+1<<'\n';
		else cout<<"col "<<t.S+1<<endl;
	}
}