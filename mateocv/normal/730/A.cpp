#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

int n;
ii r[128];
vector<vector<int>>res;

void print_res(int mn) {
	cout<<mn<<"\n";
	cout<<SZ(res)<<"\n";
	for(auto it:res){for(auto i:it)cout<<i;cout<<"\n";}
	exit(0);
}
void fill_zero() {
	fore(i,0,n-1) {
		while(r[i].fst||r[i+1].fst) {
			vector<int>v(n);
			v[r[i].snd]=v[r[i+1].snd]=1;
			res.pb(v);
			r[i].fst=max(0,r[i].fst-1);
			r[i+1].fst=max(0,r[i+1].fst-1);
		}
	}
	print_res(0);
}

int main() {FIN;
	cin>>n;
	fore(i,0,n)cin>>r[i].fst,r[i].snd=i;
	if(n==2) {
		if(r[0].fst==r[1].fst) {
			cout<<r[0].fst<<"\n";
			cout<<0<<"\n";
			return 0;
		}
		fill_zero();
	}
	sort(r,r+n);
	priority_queue<ii,vector<ii>>pq;
	fore(i,0,n-2)pq.push(r[i]);
	while(r[n-1].fst!=r[n-2].fst) {
		ii t=pq.top();pq.pop();
		r[n-1].fst--; 
		t.fst--;
		vector<int>v(n);
		v[r[n-1].snd]=v[t.snd]=1;
		res.pb(v);
		if(!t.fst)fill_zero();
		pq.push(t);
	}
	int mx=r[n-1].fst;
	//cout<<"now: "<<r[n-1].fst<<" "<<r[n-2].fst<<" "<<mx<<endl;
	vector<int>maxes={r[n-1].snd,r[n-2].snd};
	while(SZ(maxes)!=n) {
		while(mx>pq.top().fst) {
			for(int i=0;i<SZ(maxes);i+=2) {
				if(i+3==SZ(maxes)) {
					vector<int>v(n);
					v[maxes[i]]=v[maxes[i+1]]=v[maxes[i+2]]=1;
					r[maxes[i]].fst--;r[maxes[i+1]].fst--;r[maxes[i+2]].fst--;
					res.pb(v);
					break;
				} else {
					vector<int>v(n);
					v[maxes[i]]=v[maxes[i+1]]=1;
					r[maxes[i]].fst--;r[maxes[i+1]].fst--;
					res.pb(v);
				}
			}
			mx--;
		}
		while(SZ(pq) && pq.top().fst==mx) {
			maxes.pb(pq.top().snd);pq.pop();
		}
	}
	print_res(mx);
}