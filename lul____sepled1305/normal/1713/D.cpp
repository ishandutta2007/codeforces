#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		vector<int> v;
		for(int i=0;i<(1<<n);i++) {
			v.push_back(i+1);
		}
		while(v.size() > 1) {
			vector<int> nw;
			if(v.size() == 2) {
				cout<<"? "<<v[0]<<' '<<v[1]<<'\n';
				fflush(stdout);
				int a; cin>>a;
				if(a == 1) {
					nw.push_back(v[0]);
				}
				else {
					nw.push_back(v[1]);
				}
			}
			else {
				for(int k=0;k<v.size()/4;k++) {
					//Get the next four
					cout<<"? "<<v[4*k+0]<<' '<<v[4*k+2]<<'\n';
					fflush(stdout);
					int a; cin>>a;
					if(a == 1) {
						cout<<"? "<<v[4*k+0]<<' '<<v[4*k+3]<<'\n';
						fflush(stdout);
						int a; cin>>a;
						if(a == 1)
							nw.push_back(v[4*k]);
						else 
							nw.push_back(v[4*k+3]);
					}
					else if(a == 2) {
						cout<<"? "<<v[4*k+1]<<' '<<v[4*k+2]<<'\n';
						fflush(stdout);
						int a; cin>>a;
						if(a == 1)
							nw.push_back(v[4*k+1]);
						else 
							nw.push_back(v[4*k+2]);
					}
					else {
						cout<<"? "<<v[4*k+1]<<' '<<v[4*k+3]<<'\n';
						fflush(stdout);
						int a; cin>>a;
						if(a == 1)
							nw.push_back(v[4*k+1]);
						else 
							nw.push_back(v[4*k+3]);
					}
				}
			}
			v = nw;
		}
		cout<<"! "<<v[0]<<'\n';
		fflush(stdout);
	}
	return 0;
}