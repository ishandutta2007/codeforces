#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 3e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN],S[MN],seg[MN<<2],ans[MN],L[MN<<2];
pii T[MN<<2];
vector<pii> qu[MN];
vector<int> V[MN];

void init(int s, int e, int i)
{
	if(s==e){
		T[i] = {0,s};
		return;
	}
	int m = (s+e)/2;
	init(s,m,i<<1);
	init(m+1,e,i<<1|1);
}

void prop(int s, int e, int i)
{
	if(s==e) return;
	L[i<<1] += L[i];
	L[i<<1|1] += L[i];
	T[i<<1].va += L[i];
	T[i<<1|1].va += L[i];
	L[i] = 0;
}

void upt(int s, int e, int x, int y, int v, int i)
{
	if(e<x||y<s) return;;
	prop(s,e,i);
	if(x<=s&&e<=y){
		T[i].va += v;
		L[i] += v;
		return;
	}
	int m = (s+e)/2;
	upt(s,m,x,y,v,i<<1);
	upt(m+1,e,x,y,v,i<<1|1);
	T[i] = min(T[i<<1],T[i<<1|1]);
}

pii fnd(int s, int e, int x, int y, int i)
{
	if(e<x||y<s) return {INF,INF};
	prop(s,e,i);
	if(x<=s&&e<=y) return T[i];
	int m = (s+e)/2;
	return min(fnd(s,m,x,y,i<<1),fnd(m+1,e,x,y,i<<1|1));
}

void upd(int s, int e, int x, int v, int i)
{
	if(s==e){
		seg[i] = v;
		return;
	}
	int m = (s+e)/2;
	if(x<=m) upd(s,m,x,v,i<<1);
	else upd(m+1,e,x,v,i<<1|1);
	seg[i] = seg[i<<1]+seg[i<<1|1];
}

int sum(int s, int e, int x, int y, int i)
{
	if(e<x||y<s) return 0;
	if(x<=s&&e<=y) return seg[i];
	int m = (s+e)/2;
	return sum(s,m,x,y,i<<1)+sum(m+1,e,x,y,i<<1|1);	
}

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    int N,Q;
    cin >> N >> Q;
    init(1,N,1);
	for(int i=1; i<=N; i++) cin >> A[i];
	for(int i=1; i<=N; i++){
		if(A[i]>i) upt(1,N,i,i,INF,1);
		else upt(1,N,i,i,i-A[i],1);
	}
	for(int i=N; i>=1; i--){
		while(1){
			pii p = fnd(1,N,i,N,1);
			if(p.va<=0){
				upt(1,N,p.vb,p.vb,INF,1);
				upt(1,N,p.vb+1,N,-1,1);
				V[i].push_back(p.vb);
				//cout << i << ' ' << p.vb << '\n';
				upd(1,N,p.vb,1,1);
			}
			else break;
		}
	}
	for(int i=1; i<=Q; i++){
		int l,r;
		cin >> l >> r;
		l = l+1;
		r = N-r;
		qu[l].emplace_back(r,i);
	}
	for(int i=1; i<=N; i++){
		for(pii q:qu[i]){
			ans[q.vb] = sum(1,N,i,q.va,1);
		}
		for(int x:V[i]){
			upd(1,N,x,0,1);
		}
	}
	for(int i=1; i<=Q; i++) cout << ans[i] << '\n';
}