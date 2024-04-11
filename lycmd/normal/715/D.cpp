#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x=2;
vector<array<int,4> >ans,t;
void ins(int ax,int ay,int bx,int by){
	t.push_back({ax,ay,bx,by}); 
}
void solve(int n){
	if(!n)return;
	solve(n/6);
	int i=n%6;
    ins(x-2,x+3,x-1,x+3);
    ins(x-1,x+1,x,x+1);
    ins(x,x+2,x,x+3);
    ins(x,x+4,x+1,x+4);
    ins(x+1,x+2,x+1,x+3);
    ins(x+2,x,x+3,x);
    ins(x+2,x+1,x+3,x+1);
    ins(x+3,x-2,x+3,x-1);
    ins(x+4,x,x+4,x+1);
    if(i%3<1)ins(x-1,x+2,x,x+2);
    if(i<3)ins(x+1,x-1,x+1,x);
    if(i%3<2)ins(x+2,x-1,x+2,x);
	x+=2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,ins(1,2,2,2),ins(2,1,2,2);
	solve(n);
	for(int i=0;i<t.size();i++)
		if(t[i][0]>=1&&t[i][1]>=1&&t[i][2]<=x&&t[i][3]<=x)
			ans.push_back(t[i]);
	cout<<x<<" "<<x<<"\n"<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++,cout<<"\n")
		for(int j=0;j<4;j++)
			cout<<ans[i][j]<<" ";
}