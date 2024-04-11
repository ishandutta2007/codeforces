#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld inf=1e5;
const ll mod=1e9+7;

int ma[1111][1111];
ld mm[1111][1111];

ld sth[1111][1111];
ld stv[1111][1111];

//oikea alas
ld std1[2111][2111];
//oikea ylos
ld std2[2111][2111];

int n;

ld bg=0;

ll log2mod(ld x) {
	ld l2=log(2);
	ld l3=log(3);
	ld mi=inf;
	ll ret=0;
	ll v2=1;
	ld lv2=0;
	for (ll i=0;i<=2000;i++){
		ll v3=v2;
		ld lv3=lv2;
		for (ll j=0;j<=2000;j++){
			if (abs(lv3-x)<mi){
				mi=abs(lv3-x);
				ret=v3;
			}
			
			v3*=3;
			v3%=mod;
			lv3+=l3;
			
			bg=max(bg, lv3);
		}
		
		v2*=2;
		v2%=mod;
		lv2+=l2;
	}
	return ret;
}

ld v1(int y, int x, int d) {
	if (y-d<0||y+d>=n||x-d<0||x+d>=n) return -inf;
	ld su=sth[y][x+d];
	if (x-d>0) su-=sth[y][x-d-1];
	su+=stv[y+d][x];
	if (y-d>0) su-=stv[y-d-1][x];
	su-=mm[y][x];
	return su;
}

ld v2(int y, int x, int d){
	if (y-d<0||y+d>=n||x-d<0||x+d>=n) return -inf;
	ld su=std1[y+d][x+d];
	if (y-d>0&&x-d>0) su-=std1[y-d-1][x-d-1];
	su+=std2[y-d][x+d];
	if (x-d>0) su-=std2[y+d+1][x-d-1];
	su-=mm[y][x];
	return su;
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cin>>n;
	
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		for (int j=0;j<n;j++){
			ma[i][j]=s[j]-'0';
			if (ma[i][j]==0){
				mm[i][j]=-inf;
			}
			else{
				mm[i][j]=log(ma[i][j]);
			}
		}
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (j>0) sth[i][j]+=sth[i][j-1];
			sth[i][j]+=mm[i][j];
			
			if (i>0) stv[i][j]+=stv[i-1][j];
			stv[i][j]+=mm[i][j];
			
			if (i>0&&j>0) std1[i][j]+=std1[i-1][j-1];
			std1[i][j]+=mm[i][j];
		}
	}
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<n;j++){
			if (j>0) std2[i][j]+=std2[i+1][j-1];
			std2[i][j]+=mm[i][j];
		}
	}
	
	ld bv=-inf;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			if (ma[i][ii]>0){
				
				int mii=0;
				int maa=n;
				while (mii<=maa){
					int mid=(mii+maa)/2;
					ld v=v1(i, ii, mid);
					if (v>-1){
						if (v>bv){
							bv=v;
						}
						mii=mid+1;
					}
					else{
						maa=mid-1;
					}
				}
				
				mii=0;
				maa=n;
				while (mii<=maa){
					int mid=(mii+maa)/2;
					ld v=v2(i, ii, mid);
					if (v>-1){
						if (v>bv){
							bv=v;
						}
						mii=mid+1;
					}
					else{
						maa=mid-1;
					}
				}
			}
		}
	}
	ll v=log2mod(bv);
	cout<<v<<endl;
}