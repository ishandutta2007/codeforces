#include<bits/stdc++.h>
#define x second
#define y first
using namespace std;
int n;
pair<int,int>p[3];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n;n--;){
		for(int i=0;i<3;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+3);
		cout<<(p[1].y==p[2].y?abs(p[1].x-p[2].x):0)<<"\n";
	}
}