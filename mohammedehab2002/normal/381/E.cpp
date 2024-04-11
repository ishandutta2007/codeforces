#include <iostream>
#include <string.h>
using namespace std;
struct Node{
	int l,o,c;
} tree[5000005];
string s;
Node make_Node(int a,int b,int c)
{
	Node ret;
	ret.l=a;
	ret.o=b;
	ret.c=c;
	return ret;
}
void build(int node,int start,int end)
{
    if (start==end)
    tree[node]=((s[start]=='(')? make_Node(0,1,0):make_Node(0,0,1));
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=make_Node(tree[2*node].l+tree[2*node+1].l+min(tree[2*node].o,tree[2*node+1].c),tree[2*node].o+tree[2*node+1].o-min(tree[2*node].o,tree[2*node+1].c),tree[2*node].c+tree[2*node+1].c-min(tree[2*node].o,tree[2*node+1].c));
    }
}
Node query(int node,int start,int end,int l,int r)
{
    if (r<start || end<l)
    return make_Node(0,0,0);
    if (l<=start && end<=r)
    return tree[node];
    int mid=(start+end)/2;
    Node p1=query(2*node,start,mid,l,r);
    Node p2=query(2*node+1,mid+1,end,l,r);
    Node ret=make_Node(p1.l+p2.l+min(p1.o,p2.c),p1.o+p2.o-min(p1.o,p2.c),p1.c+p2.c-min(p1.o,p2.c));
    return ret;
}
int main()
{
	int q;
	cin >> s;
	build(1,0,s.size()-1);
	cin >> q;
	while (q--)
	{
		int a,b;
		cin >> a >> b;
		cout << (query(1,0,s.size()-1,a-1,b-1).l)*2 << endl;
	}
}