#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int oo[13];

int main(){
	int t;
	cin>>t;
	for (int a=0;a<t;a++){
		string s;
		cin>>s;
		string fs="";
		int f=0;
		vector<pair<int,int> >v;
		for (int i=1;i<=12;i++){
			int t=0;
			if (12%i==0){
				for (int i=0;i<13;i++){
					oo[i]=0;
				}
				int c=12/i;
				for (int ii=0;ii<12;ii++){
					if (s[ii]=='O'){
						oo[ii%c]=1;
						//cout <<ii<<" "<<ii%c<<endl;
					}
				}
				for (int ii=0;ii<c;ii++){
					if (oo[ii]==0){
						t=1;
						//cout <<"ebin"<<ii<<endl;
					}
				}
				if (t){
					f++;
					v.push_back(make_pair(i,c));
				}
			}
		}
		cout <<f<<" ";
		for (auto asd:v){
			cout <<asd.first<<"x"<<asd.second<<" ";
		}
		cout <<endl;
	}
}