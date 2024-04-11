#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > v(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> v[i][j];
		}
	}
	vector<pair<int,int> > op;
	if(n<=m){
		for(int i=0;i<n;i++){
			int mi=1000;
			for(int j=0;j<m;j++){
				mi = min(mi,v[i][j]);
			}
			for(int j=0;j<m;j++){
				v[i][j]-=mi;
			}
			for(int k=0;k<mi;k++){
				op.push_back(make_pair(0,i+1));
			}
		}
		for(int i=0;i<m;i++){
			int mi=1000;
			for(int j=0;j<n;j++){
				mi = min(mi,v[j][i]);
			}
			for(int j=0;j<n;j++){
				v[j][i]-=mi;
			}
			for(int k=0;k<mi;k++){
				op.push_back(make_pair(1,i+1));
			}
		}
		bool flag = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(v[i][j]!=0){
					flag = 1;
				}
			}
		}
		if(flag==1){
			cout << -1 << endl;
		}else{
			cout << op.size() << endl;
			for(int i=0;i<op.size();i++){
				if(op[i].first==0){
					cout << "row " << op[i].second << endl;
				}else{
					cout << "col " << op[i].second << endl;
				}
			}
		}
	}else{
		for(int i=0;i<m;i++){
			int mi=1000;
			for(int j=0;j<n;j++){
				mi = min(mi,v[j][i]);
			}
			for(int j=0;j<n;j++){
				v[j][i]-=mi;
			}
			for(int k=0;k<mi;k++){
				op.push_back(make_pair(1,i+1));
			}
		}
		for(int i=0;i<n;i++){
			int mi=1000;
			for(int j=0;j<m;j++){
				mi = min(mi,v[i][j]);
			}
			for(int j=0;j<m;j++){
				v[i][j]-=mi;
			}
			for(int k=0;k<mi;k++){
				op.push_back(make_pair(0,i+1));
			}
		}
		bool flag = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(v[i][j]!=0){
					flag = 1;
				}
			}
		}
		if(flag==1){
			cout << -1 << endl;
		}else{
			cout << op.size() << endl;
			for(int i=0;i<op.size();i++){
				if(op[i].first==0){
					cout << "row " << op[i].second << endl;
				}else{
					cout << "col " << op[i].second << endl;
				}
			}
		}
	}
	return 0;
}