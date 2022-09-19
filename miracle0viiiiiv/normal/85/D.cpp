#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int RAND_VAL[1048576],CUR,ERROR;
struct node{
	int siz,prior;
	ll num,dat[5];
	node* left;
	node* right;
	node(int n=0LL){
		siz=1;
		prior=RAND_VAL[CUR++];
		dat[0]=num=n;
		dat[1]=dat[2]=dat[3]=dat[4]=0LL;
		left=NULL;
		right=NULL;
	}
	void getcur(){
		dat[0]=dat[1]=dat[2]=dat[3]=dat[4]=0LL;
		siz=1;
		int ls=0;
		if(left!=NULL){
			siz+=left->siz;
			ls=left->siz;
			rep(k,5)dat[k]=left->dat[k];
		}
		dat[(ls++)%5]+=num;
		if(right!=NULL){
			siz+=right->siz;
			rep(k,5)dat[(ls+k)%5]+=right->dat[k];
		}
	}
};
node* NERR;
int getsiz(node* v){
	return v==NULL?0:v->siz;
}
void merge(node* u,node* v,node*& ans){
	if(u==NULL)ans=v;
	else if(v==NULL)ans=u;
	else{
		if(u->prior>v->prior){
			ans=u;
			merge(u->right,v,ans->right);
		}else{
			ans=v;
			merge(u,v->left,ans->left);
		}
		ans->getcur();
	}
}
void split(node* from,node*& u,node*& v,int szu){
	if(from==NULL)u=v=NULL;
	else{
		if(getsiz(from->left)<szu){
			u=from;
			split(from->right,u->right,v,szu-getsiz(from->left)-1);
			u->getcur();
		}else{
			v=from;
			split(from->left,u,v->left,szu);
			v->getcur();
		}
	}
}
void insertV(node*& ori,int pos,int val){
	node* u;
	node* v;
	split(ori,u,v,pos);
	merge(u,new node(val),u);
	merge(u,v,ori);
}
void eraseV(node*& ori,int pos){
	node* u;
	node* v;
	split(ori,u,v,pos);
	split(v,NERR,v,1);
	NERR->num=ERROR;
	merge(u,v,ori);
}
int lesscnt(node* ori,int dat){
	if(ori==NULL)return 0;
	if(ori->num>=dat)return lesscnt(ori->left,dat);
	else return getsiz(ori->left)+1+lesscnt(ori->right,dat);
}
void init(){
	srand(time(0));
	rep(k,131072)RAND_VAL[k]=k;
	random_shuffle(RAND_VAL,RAND_VAL+131072);
	random_shuffle(RAND_VAL,RAND_VAL+131072);
	random_shuffle(RAND_VAL,RAND_VAL+131072);
	ERROR=(-1)<<31;
	NERR=new node(ERROR);
}
node* root;
int main(){
	string op;
	int q,x;
	cin>>q;
	init();
	while(q--){
		cin>>op;
		if(op=="add"){
			cin>>x;
			insertV(root,lesscnt(root,x),x);
		}else if(op=="del"){
			cin>>x;
			eraseV(root,lesscnt(root,x));
		}else printf("%I64d\n",root==NULL?0LL:root->dat[2]);
	}
	return 0;
}