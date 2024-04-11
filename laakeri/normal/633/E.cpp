#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int v[1010101][22];
int c[1010101][22];

int l2[1010101];

ll getmin(int a, int b){
	int l=(b-a+1);
	return min(c[a][l2[l]], c[b-(1<<l2[l])+1][l2[l]]);
}

ll getmax(int a, int b){
	int l=(b-a+1);
	return max(v[a][l2[l]], v[b-(1<<l2[l])+1][l2[l]]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>v[i][0];
		v[i][0]*=100;
	}
	for (int i=0;i<n;i++){
		cin>>c[i][0];
	}
	for (int kk=1;kk<21;kk++){
		for (int i=0;i<n;i++){
			if (i+(1<<(kk-1))<n){
				v[i][kk]=max(v[i][kk-1], v[i+(1<<(kk-1))][kk-1]);
				c[i][kk]=min(c[i][kk-1], c[i+(1<<(kk-1))][kk-1]);
			}
		}
	}
	for (int i=0;i<=n;i++){
		while ((1<<(l2[i]+1))<=i) l2[i]++;
	}
	vector<ll> lol;
	for (int i=0;i<n;i++){
		ll b=min(c[i][0], v[i][0]);
		int mi=i;
		int ma=n-1;
		while (mi<=ma){
			int mid=(mi+ma)/2;
			ll vv=getmax(i, mid);
			ll cc=getmin(i, mid);
			b=max(b, min(vv, cc));
			if (cc<=vv){
				ma=mid-1;
			}
			else{
				mi=mid+1;
			}
		}
		lol.push_back(b);
	}
	ld w=0;
	sort(lol.begin(), lol.end());
	ld tn=((ld)k/(ld)n);
	for (int i=0;i<n;i++){
		int le=n-i;
		if (le<k) continue;
		w+=tn*(ld)lol[i];
		
		tn=tn*(ld)(le-k)/(ld)(le-1);
	}
	cout<<setprecision(15)<<w<<endl;
}