#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n;

ll sum(ll* st, int a, int b){
	if (a==0) return st[b];
	return st[b]-st[a-1];
}

ll t1[303030];
ll s1[303030];
ll t2[303030];
ll s2[303030];
ll s3[303030];

int le1[303030];
int le2[303030];
int le3[303030];

int ri1[303030][20];
int ri2[303030][20];
int ri3[303030][20];

pair<int, int> be(pair<int, int> a, pair<int, int> b){
	if (a.F!=b.F) return max(a, b);
	else return min(a, b);
}

pair<int, int> dp[303030][2];

void smax(int i, int k, pair<int, int> v){
	dp[i][k]=be(dp[i][k], v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n+10;i++){
		le1[i]=-1;
		le2[i]=-1;
		le3[i]=-1;
		for (int j=0;j<20;j++){
			ri1[i][j]=n+2;
			ri2[i][j]=n+2;
			ri3[i][j]=n+2;
		}
	}
	for (int i=0;i<n;i++){
		cin>>t1[i];
		s1[i]=t1[i];
		if (i) s1[i]+=s1[i-1];
	}
	for (int i=0;i<n;i++){
		cin>>t2[i];
		s2[i]=t2[i];
		if (i) s2[i]+=s2[i-1];
		
		s3[i]=t1[i]+t2[i];
		if (i) s3[i]+=s3[i-1];
	}
	
	map<ll, int> su;
	su[0]=0;
	for (int i=0;i<n;i++){
		if (su.count(s1[i])){
			le1[i]=su[s1[i]];
		}
		su[s1[i]]=i+1;
	}
	su.clear();
	su[0]=0;
	for (int i=0;i<n;i++){
		if (su.count(s2[i])){
			le2[i]=su[s2[i]];
		}
		su[s2[i]]=i+1;
	}
	su.clear();
	su[0]=0;
	for (int i=0;i<n;i++){
		if (su.count(s3[i])){
			le3[i]=su[s3[i]];
		}
		su[s3[i]]=i+1;
	}
	for (int i=0;i<n;i++){
		if (le1[i]!=-1){
			ri1[le1[i]][0]=min(ri1[le1[i]][0], i+1);
		}
		if (le2[i]!=-1){
			ri2[le2[i]][0]=min(ri2[le2[i]][0], i+1);
		}
		if (le3[i]!=-1){
			ri3[le3[i]][0]=min(ri3[le3[i]][0], i+1);
		}
	}
	for (int i=n-1;i>=0;i--){
		ri1[i][0]=min(ri1[i][0], ri1[i+1][0]);
		ri2[i][0]=min(ri2[i][0], ri2[i+1][0]);
		ri3[i][0]=min(ri3[i][0], ri3[i+1][0]);
	}
	for (int j=1;j<20;j++){
		for (int i=0;i<=n;i++){
			ri1[i][j]=ri1[ri1[i][j-1]][j-1];
			ri2[i][j]=ri2[ri2[i][j-1]][j-1];
			ri3[i][j]=ri3[ri3[i][j-1]][j-1];
		}
	}
	for (int i=0;i<n;i++){
	for (int k=0;k<2;k++){
		pair<int, int> tv=dp[i][k];
// 		cout<<i<<" "<<k<<" "<<tv.F<<" "<<tv.S<<endl;
		smax(ri1[i][0], 0, {tv.F+1, ri1[i][0]});
		smax(ri1[i][0], 1, {tv.F+1, ri1[i][0]});
		
		smax(ri2[i][0], 0, {tv.F+1, ri2[i][0]});
		smax(ri2[i][0], 1, {tv.F+1, ri2[i][0]});
		
		smax(ri3[i][0], 0, {tv.F+1, ri3[i][0]});
		smax(ri3[i][0], 1, {tv.F+1, ri3[i][0]});
		if (k==0){
			int go1=i;
			int go2=ri2[tv.S][0];
			int v1=0;
			for (int j=19;j>=0;j--){
				if (ri1[go1][j]<=go2){
					v1+=(1<<j);
					go1=ri1[go1][j];
				}
			}
			smax(go2, 1, {tv.F+1+v1, go1});
		}
		else{
			int go1=ri1[tv.S][0];
			int go2=i;
			int v1=0;
			for (int j=19;j>=0;j--){
				if (ri2[go2][j]<=go1){
					v1+=(1<<j);
					go2=ri2[go2][j];
				}
			}
			smax(go1, 0, {tv.F+1+v1, go2});
		}
	}
	}
	int v=0;
	for (int i=0;i<=n;i++){
		for (int k=0;k<2;k++){
			v=max(v, dp[i][k].F);
		}
	}
	cout<<v<<endl;
}