#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
int n;
bool a[2][N]={false};
int bans=0;
bool d[N]={false};
void s(int x){
	bool c=!((a[0][x]||a[1][x])&&(a[0][x+1]||a[1][x+1])&&((a[0][x]&&a[0][x+1])||(a[1][x]&&a[1][x+1])));
	bans-=(int)d[x];
	bans+=(int)c;
	d[x]=c;
}
int main(){
	memset(a,true,sizeof(a));
	ios::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		a[x-1][y]^=1;
		if(y>1)s(y-1);
		if(y<n)s(y);
		cout<<(bans==0?"Yes":"No")<<endl;
	}
	return 0;
}