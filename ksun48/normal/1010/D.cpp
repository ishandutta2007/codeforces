#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node {
	int realvalue;
	node *l, *r;
	string e;
	int value[2];
};
int compute(node * v){
	if(v->e == "NOT"){
		v->realvalue = 1 - compute(v->l);
	} else if(v->e == "AND"){
		v->realvalue = compute(v->l) & compute(v->r);
	} else if(v->e == "OR"){
		v->realvalue = compute(v->l) | compute(v->r);
	} else if(v->e == "XOR"){
		v->realvalue = compute(v->l) ^ compute(v->r);
	} else if(v->e == "IN"){
		// done
	}
	return v->realvalue;
}
void dfs(node * v, node * p){
	if(p == NULL){
		v->value[0] = 0;
		v->value[1] = 1;
	} else if(p->e == "NOT"){
		v->value[0] = p->value[1];
		v->value[1] = p->value[0];
	} else {
		node * other;
		if(p->l == v) other = p->r;
		if(p->r == v) other = p->l;
		if(p->e == "AND"){
			v->value[0] = p->value[other->realvalue & 0];
			v->value[1] = p->value[other->realvalue & 1];
		} else if(p->e == "OR"){
			v->value[0] = p->value[other->realvalue | 0];
			v->value[1] = p->value[other->realvalue | 1];
		} else if(p->e == "XOR"){
			v->value[0] = p->value[other->realvalue ^ 0];
			v->value[1] = p->value[other->realvalue ^ 1];
		}
	}
	if(v->e == "NOT"){
		dfs(v->l, v);
	} else if(v->e == "IN"){

	} else {
		dfs(v->l, v);
		dfs(v->r, v);
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<node*> stuff;
	for(int i = 0; i < n; i++){
		stuff.push_back(new node());
	}
	for(int i = 0; i < n; i++){
		cin >> stuff[i]->e;
		if(stuff[i]->e == "IN"){
			int a;
			cin >> a;
			stuff[i]->l = stuff[i]->r = NULL;
			stuff[i]->realvalue = a;
		} else if(stuff[i]->e == "NOT"){
			int a;
			cin >> a;
			a--;
			stuff[i]->l = stuff[a];
			stuff[i]->r = NULL;
		} else {
			int a, b;
			cin >> a >> b;
			a--; b--;
			stuff[i]->l = stuff[a];
			stuff[i]->r = stuff[b];
		}
	}
	node * root = stuff[0];
	compute(root);

	dfs(root, 0);
	for(int i = 0; i < n; i++){
		if(stuff[i]->e == "IN"){
			cout << stuff[i]->value[1-stuff[i]->realvalue];
		}
	}
	cout << '\n';
}