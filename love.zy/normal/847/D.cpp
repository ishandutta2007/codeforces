#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 400003;
//
const int ratio = 2;
int cnt;
struct Tree{
	Tree *ls, *rs;
	int size, val;
}pool[MAXN], *reuse;
void update(Tree *t){
	if (t->ls){
		t->size = t->ls->size + t->rs->size;
		t->val = t->rs->val;
	}
}
inline Tree *merge(Tree *l, Tree *r){
	Tree *t = reuse ? reuse : pool + cnt++;
	t->ls = l; t->rs = r;
	update(t); return t;
}
inline void rotate(Tree *t, bool flag){
	if (flag){
		t->ls = merge(t->ls, t->rs->ls);
		reuse = t->rs;
		t->rs = t->rs->rs;
	}
	else{
		t->rs = merge(t->ls->rs, t->rs);
		reuse = t->ls;
		t->ls = t->ls->ls;
	}
}
void maintain(Tree *t){
	if (!t->ls)return;
	if (t->ls->size > t->rs->size * ratio)rotate(t, 0);
	else if (t->rs->size > t->ls->size * ratio)rotate(t, 1);
	if (t->ls->size > t->rs->size * ratio){ rotate(t->ls, 1); rotate(t, 0); }
	else if (t->rs->size > t->ls->size * ratio){ rotate(t->rs, 0); rotate(t, 1); }
}
void insert(Tree *t, int x){
	if (!t->ls){
		//if (t->val == x)return;//multiset
		pool[cnt] = { 0, 0, 1, min(x, t->val) }; t->ls = pool + cnt++;
		pool[cnt] = { 0, 0, 1, max(x, t->val) }; t->rs = pool + cnt++;
		update(t); return;
	}
	insert(t->ls->val < x ? t->rs : t->ls, x);
	maintain(t); update(t);
}
//
/*void erase(Tree *t, int x){
	Tree *ch = t->ls->val < x ? t->rs : t->ls;
	if (ch->ls)erase(ch, x);
	else *t = t->ls == ch ? *t->rs : *t->ls;
	maintain(t); update(t);
}*/
void erase(Tree *t, int x){
	if (!t->ls)return;
	Tree *ch = t->ls->val < x ? t->rs : t->ls;
	if (ch->ls)erase(ch, x);
	else if (ch->val == x)*t = t->ls == ch ? *t->rs : *t->ls;
	maintain(t); update(t);
}
//x
int rnk(Tree *t, int x){
	if (!t->ls)return 0;
	if (t->ls->val < x)return rnk(t->rs, x) + t->ls->size;
	return rnk(t->ls, x);
}
int kth(Tree *t, int x) {
	if (!t->ls)return t->val;
	if (x >= t->ls->size)return kth(t->rs, x - t->ls->size);
	return kth(t->ls, x);
}
void clear(){
	cnt = 0; reuse = 0;
}
//fingerTree multiset 
int main()
{
	int n,m,t;
	Tree *rt=&pool[cnt++];*rt={0,0,1,0x7fffffff};
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		insert(rt,max(t-i,0));
		ans=max(ans,rnk(rt,m-i));
	}
	printf("%d",ans);
}