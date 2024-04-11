#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<17;

int st[2*N];
int sisu[2*N];

void add(int, int, int, int, int, int);

void golazy(int i, int stl, int str){
	if (i>=N) return;
	if (sisu[i]!=0){
		int m=(stl+str)/2;
		add(i*2, stl, m, stl, m, sisu[i]);
		add(i*2+1, m+1, str, m+1, str, sisu[i]);
		sisu[i]=0;
	}
}

void add(int i, int stl, int str, int l, int r, int v){
	if (l>str||r<stl) return;
	if (l<=stl&&str<=r){
		st[i]+=v;
		sisu[i]+=v;
	}
	else{
		golazy(i, stl, str);
		int m=(stl+str)/2;
		add(i*2, stl, m, l, r, v);
		add(i*2+1, m+1, str, l, r, v);
		st[i]=max(st[i*2], st[i*2+1]);
	}
}

int get(int i, int stl, int str, int l, int r){
	if (l>str||r<stl) return -N;
	if (l<=stl&&str<=r){
		return st[i];
	}
	else{
		golazy(i, stl, str);
		int m=(stl+str)/2;
		int re=-N;
		re=max(re, get(i*2, stl, m, l, r));
		re=max(re, get(i*2+1, m+1, str, l, r));
		st[i]=max(st[i*2], st[i*2+1]);
		return re;
	}
}

int xx[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		int p,t;
		cin>>p>>t;
		if (t==0){
			add(1, 0, N-1, 1, p, -1);
		}
		else {
			add(1, 0, N-1, 1, p, 1);
			cin>>xx[p];
		}
		int mi=1;
		int ma=m;
		int f=0;
		while (mi<=ma){
			int mid=(mi+ma)/2;
			if (get(1, 0, N-1, mid, m)>=1){
				f=mid;
				mi=mid+1;
			}
			else{
				ma=mid-1;
			}
		}
		if (f==0){
			cout<<-1<<'\n';
		}
		else{
			cout<<xx[f]<<'\n';
		}
	}
}