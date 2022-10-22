#include<bits/stdc++.h>
#include<array>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0;i<(n);i++)

int H,W;
int G[100][100];
vector<array<int,6>> ans;

void op(array<int,6>p){
	rep(i,3) (G[p[i*2]][p[i*2+1]]*=-1)+=1;
	ans.push_back(p);
}
void op2(array<int,4>p){
  vector<int> pv;
  rep(x,2)rep(y,2) if(p[x*2+y]){ pv.push_back(x); pv.push_back(y); }
  array<int,6> pa; rep(i,6) pa[i]=pv[i];
  op(pa);
}

void loop(){
	cin>>H>>W;
	rep(y,H)rep(x,W){ char c;cin>>c; G[x][y]=c-'0'; }
	for(int y=H-1; y>=2; y--) for(int x=W-1; x>=2; x--){
		if(G[x][y]==0) continue;
		op(array<int,6>{x,y,x,y-1,x-1,y});
	}
	for(int y=H-1; y>=2; y--){
		if(G[0][y]) op(array<int,6>{0,y,0,y-1,1,y-1});
		if(G[1][y]) op(array<int,6>{1,y,0,y-1,1,y-1});
	}
	for(int x=W-1; x>=2; x--){
		if(G[x][0]) op(array<int,6>{x,0,x-1,0,x-1,1});
		if(G[x][1]) op(array<int,6>{x,1,x-1,0,x-1,1});
	}
	int c=0;
	rep(x,2)rep(y,2)c+=G[x][y];
	if(c==4){
		op({0,0,0,1,1,1});
		c=1;
	}
	if(c==1){
		array<int,4> p={1,1,1,1};
		rep(i,4) if(G[i/2][i%2]==0){ p[i]=0; break; }
		op2(p);
		c++;
	}
	if(c==2){
		array<int,4> p={1,1,1,1};
		rep(i,4) if(G[i/2][i%2]){ p[i]=0; break; }
		op2(p);
		c++;
	}
	if(c==3){
		array<int,4> p={0,0,0,0};
		rep(x,2)rep(y,2) if(G[x][y]){ p[x*2+y]=1; }
		op2(p);
	}

	cout<<ans.size()<<endl;
	for(auto& a:ans){
    swap(a[0],a[1]);
    swap(a[2],a[3]);
    swap(a[4],a[5]);
		rep(i,6){
			if(i) cout<<" ";
			cout<<(a[i]+1);
		}cout<<endl;
	}

	ans.clear();
}

int main(){
	int T; cin>>T;
	while(T--) loop();
	return 0;
}