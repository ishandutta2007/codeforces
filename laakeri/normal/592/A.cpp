#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

string k[10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i=0;i<8;i++){
		cin>>k[i];
	}
	int bm=100;
	int wm=100;
	for (int i=0;i<8;i++){
		for (int ii=0;ii<8;ii++){
			if (k[ii][i]=='B'){
				break;
			}
			if (k[ii][i]=='W'){
				wm=min(wm, ii);
			}
		}
	}
	for (int i=0;i<8;i++){
		for (int ii=7;ii>=0;ii--){
			if (k[ii][i]=='W'){
				break;
			}
 			if (k[ii][i]=='B'){
				bm=min(bm, 7-ii);
			}
		}
	}
	if (wm<=bm){
		cout<<"A"<<endl;
	}
	else{
		cout<<"B"<<endl;
	}
}