// EZ problem

#include <bits/stdc++.h>

const int maxn = 1e5 + 222;
const int B = 165;

int n,q,l[maxn],r[maxn],in[maxn],f[maxn],b[maxn],rt;
std::vector<int>vec[maxn];
int ch[maxn][2],sum[maxn],tl;

int newnode() {
	sum[++tl] = 0;
	ch[tl][0] = ch[tl][1] = 0;
	return tl;
} 

void insert(int p,int l,int r,int rt) {
	while (1) {
		sum[rt] ++;
		if (l == r) return ;
		int mid = (l + r) >> 1;
		if (p <= mid) {
			if (!ch[rt][0]) ch[rt][0] = newnode();
			r = mid;
			rt = ch[rt][0];
		} else {
			if (!ch[rt][1]) ch[rt][1] = newnode();
			l = mid + 1;
			rt = ch[rt][1];
		}
	}
}

int query(int v,int l,int r,int rt) {
	while (1) {
		if (l == r) return l;
		if (!rt) return v;
		int mid = (l + r) >> 1;
		if (sum[ch[rt][0]] + mid >= v) {
			r = mid; rt = ch[rt][0];
		} else {
			v -= sum[ch[rt][0]];
			l = mid + 1;
			rt = ch[rt][1];
		}
	}
}

void rebuild(int p) {
	tl = 0;
	rt = newnode();
	vec[p].clear();
//	printf(">%d\n",r[p] - l[p]);
	for (int i = l[p]; i <= r[p]; ++ i) {
		// lim + pre >= b[p]
		f[i] = query(b[i],0,n,rt);
		insert(f[i],0,n,rt);
		vec[p].push_back(f[i]);
	} std::sort(vec[p].begin(),vec[p].end());
}

int Bquery(int p,int lim) {
	return std::upper_bound(vec[p].begin(),vec[p].end(),lim) - vec[p].begin();
} 

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x;
}

int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i)
		b[i] = read();
	for (int i = 1; i <= n; ++ i) {
		in[i] = (i - 1) / B + 1;
		if (!l[in[i]]) l[in[i]] = i;
		r[in[i]] = i;
		//printf("%d ",in[i]);
	} //puts("");
	for (int i = 1; i <= in[n]; ++ i)
		rebuild(i);
	
	scanf("%d",&q);
	while (q --) {
		int opt;
		opt = read();
		if (opt == 1) {
			int i,x;
			i = read(); x = read();
			b[i] = x;
			rebuild(in[i]);
			//for (int i = 1; i <= n; ++ i) {
			//	printf("%d ",f[i]);
		//	} puts("");
		} else {
			int p;
			p = read();
			int cnt = b[p];
			int x = cnt;
			int lim = x;
			// will be triggered if <= lim
			for (int i = p + 1; i <= r[in[p]]; ++ i) {
				if (b[i] <= lim) { 
					cnt ++;
					lim ++;
				}
			} 
			for (int i = in[p] + 1; i <= in[n]; ++ i) {
				int d = Bquery(i,lim);
				cnt += d;
				lim += d;
			} printf("%d\n",n - cnt);
		}
	} 
	return 0;
}