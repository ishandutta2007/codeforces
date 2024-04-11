#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int be[101010];
int bpr[101010];

int solve(int x, vector<pair<int, int> > a){
	for (int i=0;i<=100000;i++){
		be[i]=0;
		bpr[i]=0;
	}
	int ret=0;
	for (auto t:a){
		if (t.F+t.F<=x&&be[t.F]>0) ret=max(ret, be[t.F]+t.S);
		be[t.F]=max(be[t.F], t.S);
	}
	bpr[0]=be[0];
	for (int i=1;i<=100000;i++){
		bpr[i]=max(bpr[i-1], be[i]);
	}
	for (auto t:a){
		int op=x-t.F;
		if (op>=0){
			op=min(op, t.F-1);
			if (bpr[op]>0) ret=max(ret, bpr[op]+t.S);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,c,d;
	cin>>n>>c>>d;
	int maxC=0;
	int maxD=0;
	vector<pair<int, int> > cs;
	vector<pair<int, int> > ds;
	for (int i=0;i<n;i++){
		int b,p;
		char cc;
		cin>>b>>p>>cc;
		if (cc=='C'){
			if (p<=c){
				maxC=max(maxC, b);
				cs.push_back({p, b});
			}
		}
		else{
			if (p<=d){
				maxD=max(maxD, b);
				ds.push_back({p, b});
			}
		}
	}
	int ans=0;
	if (maxC>0&&maxD>0){
		ans=maxC+maxD;
	}
	ans=max(ans, solve(c, cs));
	ans=max(ans, solve(d, ds));
	cout<<ans<<endl;
}