#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
	cout<<"NOT MAGIC\n";
	exit(0);
}

int u[3030];
int us[3030];
int ues[3030];

int ok;

int getu(int x){
	if (u[x]==x) return x;
	return u[x]=getu(u[x]);
}

void adde(int x){
	ues[x]++;
	if (ues[x]==(us[x]*(us[x]-1))/2) ok+=us[x];
}

void un(int a, int b){
	a=getu(a);
	b=getu(b);
	
	if (ues[a]==(us[a]*(us[a]-1))/2) ok-=us[a];
	if (ues[b]==(us[b]*(us[b]-1))/2) ok-=us[b];
	
	u[b]=a;
	us[a]+=us[b];
	ues[a]+=ues[b];
	
	adde(a);
}

int a[3030][3030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ok=n;
	for (int i=1;i<=n;i++){
		for (int ii=1;ii<=n;ii++){
			cin>>a[i][ii];
		}
	}
	vector<pair<int, pair<int, int> > > es;
	for (int i=1;i<=n;i++){
		for (int ii=1;ii<=n;ii++){
			if (a[i][ii]!=a[ii][i]) nie();
			if (i==ii&&a[i][ii]!=0) nie();
			if (ii>i){
				es.push_back({a[i][ii], {i, ii}});
			}
		}
	}
	sort(es.begin(), es.end());
	for (int i=1;i<=n;i++){
		u[i]=i;
		us[i]=1;
	}
	for (int i=0;i<(int)es.size();){
		int t=es[i].F;
		while (es[i].F==t){
			if (getu(es[i].S.F)==getu(es[i].S.S)){
				adde(getu(es[i].S.F));
			}
			else{
				un(es[i].S.F, es[i].S.S);
			}
			i++;
			if (i==(int)es.size()) break;
		}
		if (ok<n){
			nie();
		}
	}
	cout<<"MAGIC\n";
}