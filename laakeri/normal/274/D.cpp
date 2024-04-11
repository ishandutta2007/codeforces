#include <bits/stdc++.h>
using namespace std;

vector<int> rn[101010];
vector<int> a[101010];

vector<int> g[505050];
int ec[505050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		a[i].resize(m);
		for (int ii=0;ii<m;ii++){
			cin>>a[i][ii];
			if (a[i][ii]!=-1) rn[i].push_back(a[i][ii]);
		}
		sort(rn[i].begin(), rn[i].end());
		rn[i].erase(unique(rn[i].begin(), rn[i].end()), rn[i].end());
		for (int ii=0;ii<m;ii++){
			if (a[i][ii]!=-1) a[i][ii]=lower_bound(rn[i].begin(), rn[i].end(), a[i][ii])-rn[i].begin();
			//cout<<a[i][ii]<<" ";
		}
		//cout<<endl;
	}
	for (int ii=0;ii<m;ii++){
		for (int i=0;i<n;i++){
			if (a[i][ii]!=-1){
				//cout<<"taa"<<endl;
				g[i*(m+1)+a[i][ii]].push_back(n*m*3+ii+10);
				ec[n*m*3+ii+10]++;
				//cout<<"e "<<i*(m+1)+a[i][ii]<<" "<<n*m*3+ii+10<<endl;
				g[n*m*3+ii+10].push_back(i*(m+1)+a[i][ii]+1);
				ec[i*(m+1)+a[i][ii]+1]++;
				//cout<<"e "<<n*m*3+ii+10<<" "<<i*(m+1)+a[i][ii]+1<<endl;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			g[i*(m+1)+ii].push_back(i*(m+1)+ii+1);
			ec[i*(m+1)+ii+1]++;
			//cout<<"e2 "<<i*(m+1)+ii<<" "<<i*(m+1)+ii+1<<endl;
		}
	}
	queue<int> topo;
	for (int i=0;i<=n*m*3+10+m;i++){
		if (ec[i]==0){
			topo.push(i);
		}
	}
	vector<int> v;
	while (!topo.empty()){
		int x=topo.front();
		topo.pop();
		//cout<<"x "<<x<<endl;
		if (x>=n*m*3+10){
			if (x-n*m*3-10+1<=m) v.push_back(x-n*m*3-10+1);
		}
		for (int nx:g[x]){
			ec[nx]--;
			if (ec[nx]==0) topo.push(nx);
		}
	}
	if ((int)v.size()<m){
		cout<<-1<<endl;
	}
	else{
		for (int vv:v){
			cout<<vv<<" ";
		}
	}
}