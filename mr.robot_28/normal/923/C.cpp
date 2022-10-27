#include<bits/stdc++.h>
 
using namespace std;
struct node{
	node* left;
	node* right;
	int _sz, _sz1;
	node():
		_sz(0),
		_sz1(0),
		left(NULL),
		right(NULL){};
};
node* trie;
void go_to(node* &v, int ind, int a){
	if(!v)
	{
		v = new node();
	}
	if(ind == 0)
	{
		v -> _sz++;
		v -> _sz1++;
		return;
	}
	if((a & (1 << (ind - 1))))
	{
		go_to(v -> right, ind - 1, a);
	}
	else
	{
		go_to(v -> left, ind - 1, a);
	}
	v -> _sz = 0;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> _sz += v -> left -> _sz;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> _sz += v -> right -> _sz;
	}
}
int ans = 0;
void go_to1(node* &v, int ind, int a){
	if(ind == 0)
	{
		v -> _sz--;
		v -> _sz1--;
		if(v -> _sz == 0)
		{
			v = NULL;
		}
		return;
	}
	if((a & (1 << (ind - 1))))
	{
		if(!v -> right)
		{
			ans += (1 << (ind - 1));
			go_to1(v -> left, ind - 1, a);
		}
		else
		{
			go_to1(v -> right, ind - 1, a);
		}
	}
	else
	{
		if(!v -> left)
		{
			ans += (1 << (ind - 1));
			go_to1(v -> right, ind - 1, a);
		}
		else
		{
			go_to1(v -> left, ind - 1, a);
		}
	}
	v -> _sz = 0;
	if(!v -> left)
	{
		
	}
	else
	{
		v -> _sz += v -> left -> _sz;
	}
	if(!v -> right)
	{
		
	}
	else
	{
		v -> _sz += v -> right -> _sz;
	}
	if(v -> _sz == 0)
	{
		v = NULL;
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	trie = new node();
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		go_to(trie, 30, p);
	}
	for(int i = 0; i < n; i++)
	{
		go_to1(trie, 30, a[i]);
		cout << ans << " ";
		ans = 0;
	}
    return 0;
}