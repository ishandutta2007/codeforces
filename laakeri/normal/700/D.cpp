#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int SQ=300;

int cnt1[101010];
int cnt2[101010];
int cnt3[101010];

int h2[101010];
int v[101010];

void rem2(int x){
	if (x==0) return;
	cnt2[x]--;
	if (cnt2[x]==0) h2[x/SQ]--;
}

void add2(int x){
	if (x==0) return;
	cnt2[x]++;
	if (cnt2[x]==1) h2[x/SQ]++;
}

void add(int x){
	rem2(cnt1[x]);
	cnt1[x]++;
	add2(cnt1[x]);
}

void rem(int x){
	rem2(cnt1[x]);
	cnt1[x]--;
	add2(cnt1[x]);
}

int n;

int getv(){
	priority_queue<int> has;
	for (int i=0;i*SQ<n;i++){
		if (h2[i]){
			for (int j=i*SQ;j<(i+1)*SQ&&j<n;j++){
				if (cnt2[j]) {
					has.push(-j);
					cnt3[j]=cnt2[j];
				}
			}
		}
	}
	int vv=0;
	int it=0;
	while (!has.empty()){
		it++;
		int t=-has.top();
		has.pop();
		if (cnt3[t]>=2){
			vv+=t*(cnt3[t]/2)*2;
			if (cnt3[t*2]==0) has.push(-t*2);
			cnt3[t*2]+=cnt3[t]/2;
			cnt3[t]-=cnt3[t]/2*2;
		}
		if (cnt3[t]==1){
			if (has.empty()) {
				cnt3[t]=0;
				continue;
			}
			int tt=-has.top();
			cnt3[t]--;
			cnt3[tt]--;
			if (cnt3[t+tt]==0) has.push(-(t+tt));
			cnt3[t+tt]++;
			vv+=t+tt;
		}
	}
	return vv;
}

int getrand(int a, int b){
	return a+rand()%(b-a+1);
}
int a[101010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int qq;
	cin>>qq;
	vector<pair<pair<int, int>, int> > qrs(qq);
	for (int i=0;i<qq;i++){
		int l,r;
		cin>>l>>r;
		qrs[i]={{l, r}, i};
	}
	auto cmp = [](pair<pair<int, int>, int> aa, pair<pair<int, int>, int> bb) {
		if (aa.F.F/SQ!=bb.F.F/SQ){
			return aa.F.F<bb.F.F;
		}
		else{
			return aa.F.S<bb.F.S;
		}
	};
	sort(qrs.begin(), qrs.end(), cmp);
	int l=1;
	int r=0;
	for (int i=0;i<qq;i++){
		auto q=qrs[i];
		while (r<q.F.S){
			r++;
			add(a[r]);
		}
		while (r>q.F.S){
			rem(a[r]);
			r--;
		}
		while (l>q.F.F){
			l--;
			add(a[l]);
		}
		while (l<q.F.F){
			rem(a[l]);
			l++;
		}
		v[q.S]=getv();
	}
	for (int i=0;i<qq;i++){
		cout<<v[i]<<"\n";
	}
}