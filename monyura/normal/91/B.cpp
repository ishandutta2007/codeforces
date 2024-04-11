#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct node
{
        int x;
        int y;
        int ind;
        node *left,*right;
        int lmin,rmin;
        node(int x0,int y0,int i0)
        {
                x=x0;
                y=y0;
                ind=i0;
                left=right=0;
                lmin=rmin=1e9;
        }
};

int pereshet(node *t)
{
        if (t==0) return 1e9;
        return min(min(t->lmin,t->rmin),t->ind);
}

node* merge(node *L,node *R)
{
        if (L==0) return R;
        if (R==0) return L;
        if (L->y < R->y)
        {
                R->left=merge(L,R->left);
                R->lmin=pereshet(R->left);
                return R;
        }
        L->right=merge(L->right,R);
        L->rmin=pereshet(L->right);
        return L;
}

void split(node *obj,node* &L,node* &R,int x)
{
        if (obj==0) L=R=0;
		else  if (obj->x < x)
        {
                split(obj->right,obj->right,R,x);
                obj->rmin=pereshet(obj->right);
                L=obj;
        }
		else
		{
			split(obj->left,L,obj->left,x);
			obj->lmin=pereshet(obj->left);
			R=obj;
		}
}

bool find(node *t,int x)
{
	if (!t) return false;
	if (t->x==x) return true;
	return t->x < x ?find(t->right,x) : find(t->left,x);
}

node *add(node *t,int x,int y,int ind)
{
        node *L=0,*R=0;
        split(t,L,R,x);
        //if (R!=0 && R->x==x) return merge(L,R);
        node *a=new node(x,y,ind);
        R=merge(a,R);
        return merge(L,R);
}

int ans(node *t,int x)
{
        if (t->x==x) return t->lmin;
        if (t->x < x ) return min(min(t->ind,t->lmin),ans(t->right,x));
        return ans(t->left,x);
}

int main()
{
        int n;
        cin>>n;
        int *A=new int[n];
        rep(i,0,n)
                scanf("%d",A+i);
        node *t=0;
        int pos=0;
        vector<int> res;
        res.reserve(n);
        for (int i=n-1;i>=0;i--)
        {
				if (!find(t,A[i]))
					t=add(t,A[i],rand(),pos);
                int val=ans(t,A[i]);
                if (val==1e9) res.push_back(-1);
                else res.push_back(pos-val-1);
                pos++;
        }
        for (int i=res.size()-1;i>=0;i--)
                printf("%d ",res[i]);
        return 0;      
}