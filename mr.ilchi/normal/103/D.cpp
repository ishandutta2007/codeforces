/*
 * in the name of god
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
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii; 
typedef long long ll;

const int maxN = 3*100*1000 + 5;
const int maxQ = 3*100*1000 + 5;

int n,q;
int w  [maxN];
ll  ans[maxQ];

struct node{
	
	int a,b,mod,id;

	node () {}

	node (int a , int b , int mod , int id) : a(a) , b(b) , mod(mod) , id(id) {}

	inline bool operator < (const node &sec) const{

		return (b!=sec.b) ? b<sec.b :
			 	  (mod!=sec.mod) ? mod<sec.mod :
					(a!=sec.a) ? a>sec.a : id<sec.id;
	}	
};
vector <node> Q;

int main(){
	
	scanf ("%d" , &n);
	for (int i=0; i<n; i++)
		scanf ("%d" , &w[i]);

	scanf ("%d" , &q);
	for (int i=1; i<=q; i++){
		int a,b; 
		scanf ("%d%d" , &a , &b);
		Q.push_back (node(a-1,b,(a-1)%b,i));
	}

	sort (Q.begin() , Q.end());

	for (int i=0; i<(int)Q.size(); i++){
		
		int poi =i , end=i; 
		ll  cost=0;

		while (end<(int)Q.size() && Q[end].b==Q[i].b && Q[end].mod==Q[i].mod) end++; 

		for (int j = n/Q[i].b * Q[i].b + Q[i].mod; j>=0; j-=Q[i].b){
			if (j>n) continue;		
			cost+= w[j];			
			while (poi<end && Q[poi].a==j)		
				ans[Q[poi++].id] = cost;
		}

		i = end-1;
	}

	for (int i=1; i<=q; i++)
		printf ("%I64d\n" , ans[i]);
	
	return 0;
}