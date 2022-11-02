#include <iostream>

typedef long long ll;

using namespace std;

int as[1001];

int main(){
	int n,m;
	cin>>n>>m;
	int f=0;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		int d;
		int c;
		for (int ii=0;ii<m;ii++){
			if (s[ii]=='G'){
				d=ii;
			}
			if (s[ii]=='S'){
				c=ii;
			}
		}
		if (d<c){
			if (as[c-d]==0){
				f++;
			}
			as[c-d]=1;
		}
		else{
			cout <<"-1"<<endl;
			return 0;
		}
	}
	cout <<f<<endl;
}