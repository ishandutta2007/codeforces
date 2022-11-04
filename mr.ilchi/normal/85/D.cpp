/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef long double ldb;
typedef long long ll;

const int maxN= 100*1000 + 5;

int Q;
map <int, int> POS;

struct range{

	int s,e;
	
	ll siz;
	ll mod[5];

	range(int s=-1, int e=-1) : s(s), e(e) {
		memset (mod,0,sizeof mod);
		siz=0;
	}

}t[1<<18];
/****************************************/
inline void build (int x){
	
	if (t[x].e<=t[x].s)
		return;

	int mid= (t[x].s + t[x].e)/2;
	int l  = (x<<1);
	int r  = l+1;

	t[l]= range(t[x].s, mid);
	t[r]= range(mid+1 , t[x].e);

	build (l); build(r);
}
/****************************************/
inline void add (int root, int pos, int val){
	
	range &now= t[root];

	now.siz++;

	if (now.s == now.e){

		now.mod[1]= val;

		return;
	}

	int l= (root<<1), r=(root<<1)+1;

	if (pos <= t[l].e)			
		add (l, pos, val);
	else
		add (r, pos, val);

	for (int i=0;i<5;i++){
		
		int tmp= (i-t[l].siz)%5; tmp= (tmp+5)%5;
		now.mod[i]= t[l].mod[i] + t[r].mod[tmp];		
	}
}
/****************************************/
inline void del (int root, int pos, int val){
	
	range &now= t[root];

	now.siz --;

	if (now.s == now.e){
		
		now.mod[1]= 0;

		return;
	}

	int l= (root<<1), r=(root<<1)+1;

	if (pos <= t[l].e)	
		del (l, pos, val);
	else
		del (r, pos, val);

	for (int i=0;i<5;i++){	
		int tmp= (i-t[l].siz)%5; tmp= (tmp+5)%5;
		now.mod[i]= t[l].mod[i] + t[r].mod[tmp];		
	}
}
/****************************************/
int main(){

	scanf ("%d", &Q);

	vector <pii> qq;
	vector <int> num;

	for (int i=1;i<=Q;i++){

		char test[5]; scanf ("%s", test);

		if (test[0]=='a'){
			int tmp; scanf ("%d", &tmp);
			qq.push_back (pii (0, tmp));
			num.push_back (tmp);
		}

		else if (test[0]=='d'){
			int tmp; scanf ("%d", &tmp);
			qq.push_back (pii (1, tmp));
		}

		else
			qq.push_back (pii (2, -1));
	}

	sort (num.begin(), num.end());

	int uni=0;

	for (int i=0;i<(int)num.size();i++){
		if (POS[num[i]]==0)
			POS[num[i]]= ++uni;
	}

	t[1]= range (1,uni);
	build (1);

	for (int i=0; i<(int)qq.size(); i++){
	
		if (qq[i].first==0)
			add (1, POS[qq[i].second], qq[i].second); 

		else if (qq[i].first==1)
			del (1, POS[qq[i].second], qq[i].second);

		else
			printf ("%I64d\n", t[1].mod[3]);
	}

	return 0;
}