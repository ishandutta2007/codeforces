#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
int add(int a,int b){
	return (a+b)%MOD;
}
void dadd(int &a,int b){
	a=add(a,b);
}
int sub(int a,int b){
	return (a-b+MOD)%MOD;
}
int mul(int a,int b){
	return (LL)a*b%MOD;
}
typedef long long LL;
const int N=5050;
int s[N];
int f[N],h[N];

vector<int> qaq[N];

vector<int> cows[N];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		qaq[s[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		cin>>f[i]>>h[i];
		if(h[i]<=(int)qaq[f[i]].size()){
			cows[f[i]].push_back(h[i]);
		}
	}
	for(int i=1;i<=n;i++){
		sort(cows[i].begin(),cows[i].end());
	}
	int ans=0;
	int cnt=0;
	for(int i=0;i<=n;i++){
		int tans=0;
		int c[2]={i!=0,i==0};
		for(int j=1;j<=n;j++){
			vector<int> &v=qaq[j];
			if(cows[j].empty())continue;
			int tt=0;
			int x=cows[j][0];
			// assert(x>=1&&x<=(int)qaq[j].size());
			int xl=v[x-1];
			int xr=v[v.size()-x];
			if(xl<=i||xr>i){
				tt++;
				if(cows[j].size()>=2){
					int y=cows[j][1];
					int yl=v[y-1];
					int yr=v[qaq[j].size()-y];
					if((xl<=i&&yr>i)||(yl<=i&&xr>i)){
						tt++;
					}
				}
			}
			tans+=tt;
			{
				int sl=0;
				int eq=0;
				int rle=0;
				for(int x:cows[j]){
					if(v[x-1]<=i){
						if(v[x-1]==i){
							eq++;
						}
						else{
							sl++;
						}
					}
					if(v[v.size()-x]>i){
						rle++;
					}
				}
				int d[2]={0,0};
				if(tt==1){
					int go=add(sl,rle);
					d[0]=mul(c[0],go);
					d[1]=mul(c[1],go);
					int ee=eq;
					// cerr<<"QAQ "<<j<<" "<<go<<" "<<ee<<endl;
					dadd(d[1],mul(c[0],ee));
					dadd(d[1],mul(c[1],ee));
				}
				else if(tt==2){
					int go=sub(mul(sl,rle),min(sl,rle));
					d[0]=mul(c[0],go);
					d[1]=mul(c[1],go);
					int ee=eq?rle>=sl+1?rle-1:rle:0;
					dadd(d[1],mul(c[0],ee));
					dadd(d[1],mul(c[1],ee));
				}
				else{
					d[0]=c[0];
					d[1]=c[1];
				}
				c[0]=d[0];
				c[1]=d[1];
			}
		}
		// cerr<<i<<" "<<tans<<" "<<c[1]<<endl;
		if(tans>ans){
			ans=tans;
			cnt=c[1];
		}
		else if(ans==tans){
			cnt=add(cnt,c[1]);
		}
	}
	cout<<ans<<" "<<cnt<<endl;
	return 0;
}