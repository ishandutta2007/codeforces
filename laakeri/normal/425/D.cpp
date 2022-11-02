#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

set<int> xps[101010];
set<int> yps[101010];

set<pair<int, int> > xs;
set<pair<int, int> > ys;

void rm(int x, int y){
	int exc=xps[x].size();
	int eyc=yps[y].size();
	xs.erase({exc, x});
	ys.erase({eyc, y});
	xps[x].erase(y);
	yps[y].erase(x);
	if (exc>1){
		xs.insert({exc-1, x});
	}
	if (eyc>1){
		ys.insert({eyc-1, y});
	}
}

int is(int x, int y){
	return xps[x].count(y)>0;
}

int x[101010];
int y[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for (int i=0;i<n;i++){
		xps[x[i]].insert(y[i]);
		yps[y[i]].insert(x[i]);
	}
	for (int i=0;i<=n;i++){
		if ((int)xps[i].size()>0){
			xs.insert({(int)xps[i].size(), i});
		}
		if ((int)yps[i].size()>0){
			ys.insert({(int)yps[i].size(), i});
		}
	}
	int v=0;
	while ((int)xs.size()>0||(int)ys.size()>0){
		if ((int)xs.size()==0||(((int)xs.size()>0&&(int)ys.size()>0)&&(*ys.begin()).F<(*xs.begin()).F)){
			//cout<<"x"<<endl;
			vector<int> xx;
			int ty=(*ys.begin()).S;
			for (int kx:yps[ty]){
				xx.push_back(kx);
			}
			for (int i=0;i<(int)xx.size();i++){
				for (int ii=i+1;ii<(int)xx.size();ii++){
					int d=abs(xx[ii]-xx[i]);
					int ny1=ty+d;
					int ny2=ty-d;
					if (is(xx[i], ny1)&&is(xx[ii], ny1)) v++;
					if (is(xx[i], ny2)&&is(xx[ii], ny2)) v++;
				}
			}
			for (int i=0;i<(int)xx.size();i++){
				//cout<<"rm "<<xx[i]<<" "<<ty<<endl;
				rm(xx[i], ty);
			}
		}
		else{
			//cout<<"y"<<endl;
			vector<int> yy;
			int tx=(*xs.begin()).S;
			for (int ky:xps[tx]){
				yy.push_back(ky);
			}
			for (int i=0;i<(int)yy.size();i++){
				for (int ii=i+1;ii<(int)yy.size();ii++){
					int d=abs(yy[ii]-yy[i]);
					//cout<<d<<" "<<yc[yy[ii]]<<" "<<yc[yy[i]]<<" "<<xc[tx]<<endl;
					int nx1=tx+d;
					int nx2=tx-d;
					//cout<<nx1<<" nx "<<nx2<<endl;
					//cout<<nx1<<" "<<yy[ii]<<" "<<nx1<<" "<<yy[i]<<endl;
					if (is(nx1, yy[ii])&&is(nx1, yy[i])) v++;
					if (is(nx2, yy[ii])&&is(nx2, yy[i])) v++;
				}
			}
			for (int i=0;i<(int)yy.size();i++){
				rm(tx, yy[i]);
			}
		}
	}
	cout<<v<<endl;
}