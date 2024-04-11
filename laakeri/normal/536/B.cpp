#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> zAlgo(string s) {
	int n=s.size();
	vector<int> z(n);
	int l=0;
	int r=0;
	for (int i=1;i<n;i++) {
		z[i]=max(0, min(z[i-l], r-i));
		
		while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		
		if (i+z[i]>r) {
			l=i;
			r=i+z[i];
		}
	}
	return z;
}

const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> z=zAlgo(s);
	
	vector<int> yy;
	if (m>0){
		int ey;
		cin>>ey;
		yy.push_back(ey);
		for (int i=1;i<m;i++){
			int y;
			cin>>y;
			int d=y-ey;
			if (d<(int)s.size()){
				if (z[d]<(int)s.size()-d){
					cout<<0<<endl;
					return 0;
				}
			}
			yy.push_back(y);
			ey=y;
		}
	}
	int t=0;
	int vv=0;
	for (int y:yy){
		int l=min((int)s.size(), y+(int)s.size()-1-t);
		vv+=l;
		t=y+(int)s.size()-1;
	}
	ll v=1;
	for (int i=vv;i<n;i++){
		v*=26ll;
		v%=mod;
	}
	cout<<v<<endl;
}