#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
struct state{
	int x,h1,h2,h3,add;
	state(int _x=0,int _h1=0,int _h2=0,int _h3=0){
		x=_x;h1=_h1;h2=_h2;h3=_h3;
	}
	void operator=(pair<int,int>_x){
		add=_x.second;
		h3=_x.first%20;_x.first/=20;
		h2=_x.first%20;_x.first/=20;
		h1=_x.first%20;_x.first/=20;
		x=_x.first;
	}
}pre[15][20][20][20];
bool Pre(state &x){
	state tmp=pre[x.x][x.h1][x.h2][x.h3];
	for(int i=1;i<=x.add;i++)cout<<x.x<<" ";
	x=tmp;if(tmp.x<2)return false;
	return true;
}
int dp[15][20][20][20]; 
int n,a,b;
int h[15];
inline void upd(int *x,int *y,int add){
	if(*y+add>=*x)return;
	int _=x-&dp[0][0][0][0];
	state *st=(&pre[0][0][0][0]+(_));
	*x=*y+add;
	*st=make_pair(y-&dp[0][0][0][0],add);
}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>h[i],h[i]++;
	memset(dp,inf,sizeof dp);
	dp[2][h[1]][h[2]][h[3]]=0;
	for(int i=2;i<n;i++){
		for(int h1=0;h1<=16;h1++){
			for(int h2=0;h2<=16;h2++){
				for(int h3=0;h3<=16;h3++){
					if(dp[i][h1][h2][h3]==inf)continue;
					for(int time=0;time<=16;time++){
						if(b*time<h1)continue;
						upd(&dp[i+1][max(0,h2-a*time)][max(0,h3-b*time)][h[i+2]],&dp[i][h1][h2][h3],time);
					}
				}
			}
		}
	}
	cout<<dp[n][0][0][0]<<endl;
	state st=pre[n][0][0][0];
	while(Pre(st));
	return 0;
}