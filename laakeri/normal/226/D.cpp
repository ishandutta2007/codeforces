#include <bits/stdc++.h>
using namespace std;

int k[111][111];
int rs[111];
int cs[111];

set<int> rv,cv;
int n,m;

void row(int i){
	if (cv.count(i+1)) cv.erase(i+1);
	else cv.insert(i+1);
	for (int ii=0;ii<m;ii++){
		k[i][ii]=-k[i][ii];
		rs[i]+=k[i][ii]*2;
		cs[ii]+=k[i][ii]*2;
	}
}
void col(int ii){
	if (rv.count(ii+1)) rv.erase(ii+1);
	else rv.insert(ii+1);
	for (int i=0;i<n;i++){
		k[i][ii]=-k[i][ii];
		rs[i]+=k[i][ii]*2;
		cs[ii]+=k[i][ii]*2;
	}
}
int move(){
	for (int i=0;i<n;i++){
		if (rs[i]<0){
			row(i);
			return 1;
		}
	}
	for (int ii=0;ii<m;ii++){
		if (cs[ii]<0){
			col(ii);
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			cin>>k[i][ii];
			rs[i]+=k[i][ii];
			cs[ii]+=k[i][ii];
		}
	}
	while (move()){
		
	}
	cout<<cv.size()<<" ";
	for (int c:cv){
		cout<<c<<" ";
	}
	cout<<endl<<rv.size()<<" ";
	for (int r:rv){
		cout<<r<<" ";
	}
	cout<<endl;
}