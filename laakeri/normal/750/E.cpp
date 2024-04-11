#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

struct s{
	ll dp[5][5];
	s(){
		for (int i=0;i<5;i++)
			for (int ii=0;ii<5;ii++)
				dp[i][ii]=1e9;
	}
};

s mrg(s& a, s& b){
	s r;
	for (int i=0;i<5;i++){
		for (int ii=0;ii<5;ii++){
			for (int k=0;k<5;k++){
				r.dp[i][ii]=min(r.dp[i][ii], a.dp[i][k]+b.dp[k][ii]);
			}
		}
	}
	return r;
}

const int N=1<<18;
s st[2*N];

s qr(int i, int stl, int str, int l, int r){
	if (stl>r||str<l) {
		s re;
		for (int j=0;j<5;j++) re.dp[j][j]=0;
		return re;
	}
	if (l<=stl&&str<=r){
		return st[i];
	}
	else{
		int m=(stl+str)/2;
		s le=qr(i*2, stl, m, l, r);
		s ri=qr(i*2+1, m+1, str, l, r);
		return mrg(le, ri);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	string lol;
	cin>>lol;
	for (int i=0;i<n;i++){
		for (int j=0;j<5;j++){
			st[i+N].dp[j][j]=0;
		}
		if (lol[i]=='2'){
			st[i+N].dp[0][0]=1;
			st[i+N].dp[0][1]=0;
		}
		if (lol[i]=='0'){
			st[i+N].dp[1][1]=1;
			st[i+N].dp[1][2]=0;
		}
		if (lol[i]=='1'){
			st[i+N].dp[2][2]=1;
			st[i+N].dp[2][3]=0;
		}
		if (lol[i]=='7'){
			st[i+N].dp[3][3]=1;
			st[i+N].dp[3][4]=0;
		}
		if (lol[i]=='6'){
			st[i+N].dp[3][3]=1;
			st[i+N].dp[4][4]=1;
		}
	}
	for (int i=N-1;i>=0;i--){
		st[i]=mrg(st[i*2], st[i*2+1]);
	}
	for (int qq=0;qq<q;qq++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		s v=qr(1, 0, N-1, a, b);
		if (v.dp[0][4]>n){
			cout<<"-1\n";
		}
		else{
			cout<<v.dp[0][4]<<'\n';
		}
	}
}