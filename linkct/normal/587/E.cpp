#include <cstdio>
#include <cstring>
const int MAXN = 200005;

int n, q, seq[MAXN], res[30], tr[MAXN << 2], base[MAXN << 2][30];

//10^9: 30 bits
void insert(int b[], int v){
	for(int i = 29; i >= 0; -- i){
		if((v & (1 << i)) == 0) continue;
		if(!b[i]){
			b[i] = v;
			break;
		} v ^= b[i];
	}
}
void merge(int b[], int x[]){
	int i, j, tmp;
	for(i = 29; i >= 0; -- i){
		if(!(tmp = x[i])) continue;
		for(j = i; j >= 0; -- j){
			if((tmp & (1 << j)) == 0) continue;
			if(!b[j]){
				b[j] = tmp;
				break;
			} tmp ^= b[j];
		}
	}
}
int getSize(int b[]){
	int ret = 0, i;
	for(i = 0; i < 30; ++ i) if(b[i]) ret ++;
	return ret;
}
void sgtInit(int x, int l, int r){
	if(l == r){
		tr[x] = seq[l];
		insert(base[x], seq[l - 1] ^ seq[l]);
		return;
	}
	int mid = (l + r) >> 1;
	sgtInit(x << 1, l, mid);
	sgtInit(x << 1 | 1, mid + 1, r);
	memcpy(base[x], base[x << 1], sizeof(base[x]));
	merge(base[x], base[x << 1 | 1]);
}
void sgtUpdate1(int x, int l, int r, int ql, int qr, int qv){
	if(l >= ql && r <= qr){
		tr[x] ^= qv;
		return;
	}
	tr[x << 1] ^= tr[x], tr[x << 1 | 1] ^= tr[x];
	tr[x] = 0; int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate1(x << 1, l, mid, ql, qr, qv);
	if(qr > mid) sgtUpdate1(x << 1 | 1, mid + 1, r, ql, qr, qv);
}
void sgtUpdate2(int x, int l, int r, int p, int v){
	if(l == r){
		for(p = 0; p < 30; ++ p) if(base[x][p]) break;
		if(p != 30){l = base[x][p]; base[x][p] = 0;}
		else l = 0;
		insert(base[x], l ^ v);
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) sgtUpdate2(x << 1, l, mid, p, v);
	else sgtUpdate2(x << 1 | 1, mid + 1, r, p, v);
	memcpy(base[x], base[x << 1], sizeof(base[x]));
	merge(base[x], base[x << 1 | 1]);
}
int sgtQuery1(int x, int l, int r, int p){
	if(l == r) return tr[x];
	tr[x << 1] ^= tr[x], tr[x << 1 | 1] ^= tr[x];
	tr[x] = 0; int mid = (l + r) >> 1;
	if(p <= mid) return sgtQuery1(x << 1, l, mid, p);
	return sgtQuery1(x << 1 | 1, mid + 1, r, p);
}
void sgtQuery2(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr){
		merge(res, base[x]);
		return;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtQuery2(x << 1, l, mid, ql, qr);
	if(qr > mid) sgtQuery2(x << 1 | 1, mid + 1, r, ql, qr);
}
int main(){
	int i, t, l, r, k;
	scanf("%d%d", &n, &q);
	for(i = 1; i <= n; ++ i) scanf("%d", &seq[i]);
	sgtInit(1, 1, n);
	for(i = 1; i <= q; ++ i){
		scanf("%d%d%d", &t, &l, &r);
		if(t == 1){
			scanf("%d", &k);
			sgtUpdate1(1, 1, n, l, r, k);
			sgtUpdate2(1, 1, n, l, k);
			if(r != n) sgtUpdate2(1, 1, n, r + 1, k);
		}else{
			if(l == r){
				printf("%d\n", sgtQuery1(1, 1, n, l) ? 2 : 1);
				continue;
			}
			memset(res, 0, sizeof(res));
			sgtQuery2(1, 1, n, l + 1, r);
			insert(res, sgtQuery1(1, 1, n, l));
			printf("%d\n", 1 << getSize(res));
		}
	}
	return 0;
}