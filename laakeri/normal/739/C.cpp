#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<19;

int st[2*N][8];
ll v[N];
int lol[2*N];

void upd(int i, int le){
	if (i>=N){
		int t=i-N;
		if (v[t]==0){
			for (int j=0;j<8;j++) st[i][j]=0;
		}
		else if(v[t]>0){
			st[i][0]=1;
			st[i][1]=0;
			st[i][2]=1;
			st[i][3]=0;
			st[i][4]=1;
			st[i][5]=1;
			st[i][6]=1;
			st[i][7]=1;
		}
		else if(v[t]<0){
			st[i][0]=0;
			st[i][1]=1;
			st[i][2]=0;
			st[i][3]=1;
			st[i][4]=1;
			st[i][5]=1;
			st[i][6]=1;
			st[i][7]=1;
		}
	}
	else{
		if (st[i*2][0]+st[i*2+1][0]==le){
			st[i][0]=le;
		}
		else{
			st[i][0]=0;
		}
		if (st[i*2][1]+st[i*2+1][1]==le){
			st[i][1]=le;
		}
		else{
			st[i][1]=0;
		}
		st[i][2]=st[i*2+1][2];
		if (st[i*2+1][0]==le/2){
			st[i][2]=st[i*2+1][0]+st[i*2][2];
		}
		st[i][3]=st[i*2][3];
		if (st[i*2][1]==le/2){
			st[i][3]=st[i*2][1]+st[i*2+1][3];
		}
		st[i][4]=0;
		if (st[i*2][0]+st[i*2+1][1]==le){
			st[i][4]=le;
		}
		if (st[i*2][4]+st[i*2+1][1]==le){
			st[i][4]=le;
		}
		if (st[i*2][0]+st[i*2+1][4]==le){
			st[i][4]=le;
		}
		
		st[i][5]=max(st[i][0], st[i][1]);
		st[i][5]=max(st[i][5], st[i][3]);
		st[i][5]=max(st[i][5], st[i][4]);
		if (st[i*2][0]==le/2) st[i][5]=max(st[i][5], st[i*2][0]+st[i*2+1][5]);
		if (st[i*2][4]==le/2) st[i][5]=max(st[i][5], st[i*2][4]+st[i*2+1][3]);
		st[i][5]=max(st[i][5], st[i*2][5]);
		
		st[i][6]=max(st[i][0], st[i][1]);
		st[i][6]=max(st[i][6], st[i][2]);
		st[i][6]=max(st[i][6], st[i][4]);
		if (st[i*2+1][1]==le/2) st[i][6]=max(st[i][6], st[i*2][6]+st[i*2+1][1]);
		if (st[i*2+1][4]==le/2) st[i][6]=max(st[i][6], st[i*2][2]+st[i*2+1][4]);
		st[i][6]=max(st[i][6], st[i*2+1][6]);
		
		st[i][7]=max(st[i*2][7], st[i*2+1][7]);
		st[i][7]=max(st[i][7], st[i*2][6]+st[i*2+1][3]);
		st[i][7]=max(st[i][7], st[i*2][2]+st[i*2+1][5]);
		for (int j=0;j<7;j++){
			st[i][7]=max(st[i][7], st[i][j]);
		}
	}
	/*
	cout<<i<<" "<<le<<endl;
	for (int j=0;j<8;j++){
		cout<<j<<": "<<st[i][j]<<endl;
	}*/
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>v[i];
	}
	for (int i=n;i>=1;i--){
		v[i]-=v[i-1];
	}
	v[1]=0;
	for (int i=2*N-1;i>=N;i--){
		lol[i]=1;
	}
	for (int i=2*N-1;i>0;i--){
		if (i<N) lol[i]=2*lol[i*2];
		upd(i, lol[i]);
	}
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++){
		int l,r;
		ll d;
		cin>>l>>r>>d;
		v[l]+=d;
		v[1]=0;
		int le=1;
		for (l+=N;l;l/=2){
			upd(l, le);
			le*=2;
		}
		r++;
		if (r<=n){
			v[r]-=d;
			v[1]=0;
			le=1;
			for (r+=N;r;r/=2){
				upd(r, le);
				le*=2;
			}
		}
		cout<<st[1][7]+1<<'\n';
	}
}