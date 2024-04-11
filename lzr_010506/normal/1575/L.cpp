#include <bits/stdc++.h>

const int MAX_N = 2e5 + 1 , lgN = 14 ;

struct Node {
	int num ;
	Node *ch[2] ;

	void init() {num = 0 ; ch[0] = ch[1] = NULL ;}
}tre[MAX_N * lgN * lgN] ;

Node *root[MAX_N] ;
int n , ma , tot , a[MAX_N] , f[MAX_N] ;

int lowbit(int x) {return x & (-x) ;}

int query(Node *rt , int x , int y , int fx , int fy) {
	if (!rt) return 0 ;
	if (y < fx || fy < x) return 0 ;
	if (fx <= x && y <= fy) return rt->num ;

	int mid = (x + y) >> 1 ;
	return std::max(query(rt->ch[0] , x , mid , fx , fy) , query(rt->ch[1] , mid + 1 , y , fx , fy)) ;
}

void ins(Node *&rt , int x , int y , int f , int a) {
	if (!rt) (rt = &tre[tot++])->init() ;
	rt->num = std::max(rt->num , a) ;

	if (x == y) return ;

	int mid = (x + y) >> 1 ;
	if (f <= mid) ins(rt->ch[0] , x , mid , f , a) ;
	else ins(rt->ch[1] , mid + 1 , y , f , a) ;
}

int getf(int x , int y) {
	int r = 0 ;
	for (; x ; x -= lowbit(x))
		r = std::max(r , query(root[x] , 0 , n , 0 , y)) ;

	return r ;
}

void add(int x , int y , int a) {
	for (; x <= ma ; x += lowbit(x)) ins(root[x] , 0 , n , y , a) ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d" , &a[i]) ; ma = std::max(ma , a[i]) ;
	}

	///

	int res = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (i - a[i] < 0) {f[i] = 0 ; continue ;}
		else f[i] = std::max(1 , getf(a[i] - 1 , i - a[i]) + 1) ;
		
		add(a[i] , i - a[i] , f[i]) ; res = std::max(res , f[i]) ;
	}

	printf("%d\n" , res) ;

	return 0 ;
}