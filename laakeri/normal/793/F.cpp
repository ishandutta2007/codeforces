#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int K=300;

int to[101010];
int le[101010];
int fp[1010];

void add(int l, int r){
	int b=r/K;
	int bl=b*K;
	int br=(b+1)*K-1;
	le[r]=min(le[r], le[l]);
	for (int i=max(l, bl);i<=r;i++){
		le[r]=min(le[r], le[i]);
	}
	for (int i=bl;i<=br;i++){
		le[i]=min(le[i], le[le[i]]);
		to[i]=min(to[i], le[i]);
	}
	for (int i=bl;i<=br;i++){
		to[i]=min(to[i], to[max(le[i], bl)]);
		if (to[i]<=r) to[i]=min(to[i], to[r]);
	}
	fp[b]=bl;
	for (int i=br;i>=bl;i--){
		if (i<br){
			to[i]=min(to[i], to[i+1]);
		}
		if (to[i]<bl&&fp[b]==bl){
			fp[b]=i;
		}
	}
}

int qr(int l, int r){
	int sp=r;
	int lp=r;
// 	cout<<"query "<<l<<" "<<r<<endl;
	for (int i=r;i>l;){
// 		cout<<i<<" "<<lp<<" "<<sp<<endl;
		if (lp>i){
			sp=i;
			lp=le[i];
		}
		if (i%K==K-1&&i-K>l){
// 			cout<<i-(K-1)<<" "<<lp<<endl;
			lp=min(lp, to[max(i-(K-1), lp)]);
// 			cout<<lp<<" "<<endl;
			if (lp>i-K){
// 				cout<<"taa"<<endl;
				sp=fp[i/K];
				lp=to[sp];
			}
			i-=K;
		}
		else{
			lp=min(lp, le[i]);
			i--;
		}
	}
	if (lp>l) return l;
	return sp;
}

int ans[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<pair<int, int> > rs(m);
	for (int i=0;i<m;i++){
		cin>>rs[i].F>>rs[i].S;
		rs[i].F--;
		rs[i].S--;
	}
	sort(rs.rbegin(), rs.rend());
	int q;
	cin>>q;
	vector<pair<pair<int, int>, int> > qs(q);
	for (int qq=0;qq<q;qq++){
		cin>>qs[qq].F.F>>qs[qq].F.S;
		qs[qq].S=qq;
		qs[qq].F.F--;
		qs[qq].F.S--;
	}
	sort(qs.rbegin(), qs.rend());
	for (int i=0;i<n/K;i++){
		fp[i]=i*K;
	}
	for (int i=0;i<n;i++){
		to[i]=i;
		le[i]=i;
	}
	int i2=0;
	for (int qq=0;qq<q;qq++){
		while (i2<m&&rs[i2].F>=qs[qq].F.F){
			add(rs[i2].F, rs[i2].S);
			i2++;
		}
		/*
		for (int i=0;i<n;i++){
			cout<<le[i]<<" "<<to[i]<<endl;
		}*/
		ans[qs[qq].S]=qr(qs[qq].F.F, qs[qq].F.S);
	}
	for (int i=0;i<q;i++){
		cout<<ans[i]+1<<'\n';
	}
}