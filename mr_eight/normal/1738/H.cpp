#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int ch[N][26], cov[N], f[N], len[N], p;
char s[N],temp[N];
int getfa(int x) {
	for(; p < len[x] + 1 || s[p - len[x] - 1] != s[p]; x = f[x]) ;
	return x;
}
int lst, tot = 1; 
void ins() {
	lst = getfa(lst);
	if(!ch[lst][s[p] - 'a']) 
		++tot, f[tot] = ch[getfa(f[lst])][s[p] - 'a'], ch[lst][s[p] - 'a'] = tot, len[tot] = len[lst] + 2;
	lst = ch[lst][s[p] - 'a'];
}
char qs[10];
int n, m, curm = 1, ml = 1, xns, pos[N], cnt[N];
vi vc[N]; 
void cv(int x, int w) {
	if(x <= 1) return ;
	if(!cov[x]) xns += 1, cnt[f[x]] += 1;
	if(w > cov[x]) cov[x] = w, vc[w - len[x] + 1].emplace_back(x);
}
inline bool cmp(int x,int y){
	return len[x]<len[y];
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m, f[0] = 1, len[1] = -1;
	while(m--) {
		cin >> (qs + 1);
		if(qs[2] == 'u') {
			cin >> (qs + 1);
			n += 1, s[n] = qs[1], p = n, ins();
			for(; len[lst] > n - ml + 1; lst = f[lst]) ;
			cv(lst, n);
		} else {
			
		if(vc[ml].size()){
			int u=*max_element(vc[ml].begin(),vc[ml].end(),cmp);
			if(!cnt[u] && len[u] == cov[u] - ml + 1) 
				--xns, cv(f[u], cov[u]), cov[u] = 0, cnt[f[u]] -= 1;
		} 
		++ml;}
		cout << xns << '\n';
	}
	return 0;
}
/*
3
pu a
po
pu a
*/