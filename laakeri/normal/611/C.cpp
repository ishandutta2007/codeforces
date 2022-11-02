#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int st[555][555][2];
string s[555];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h,w;
	cin>>h>>w;
	for (int i=1;i<=h;i++){
		cin>>s[i];
		for (int ii=1;ii<=w;ii++){
			for (int k=0;k<2;k++){
				st[i][ii][k]=st[i][ii-1][k]+st[i-1][ii][k]-st[i-1][ii-1][k];
			}
			if (s[i][ii-1]=='.'){
				if (i>1){
					if (s[i-1][ii-1]=='.') st[i][ii][0]++;
				}
				if (ii>1){
					if (s[i][ii-2]=='.') st[i][ii][1]++;
				}
			}
		}
	}
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		//cout<<st[r2][c2]<<endl;
		int v=st[r2][c2][0]-st[r2][c1-1][0]-st[r1][c2][0]+st[r1][c1-1][0];
		v+=st[r2][c2][1]-st[r2][c1][1]-st[r1-1][c2][1]+st[r1-1][c1][1];
		cout<<v<<'\n';
	}
}