#include<bits/stdc++.h>
using namespace std;
void read(int &x) {
	int f = 1;
	x = 0;
	char op = getchar();
	while(((op-'0')|('9'-op))<0) { 
		if(op == '-') f = -1;
		op = getchar();
	}
	while(((op-'0')|('9'-op))>=0) {
		x = x * 10 + op - '0';
		op = getchar();
	}
	x *= f;
}
int T,n;
string st;
signed main()
{
	read(T);
	while (T--)
	{
		read(n);
		cin>>st;
		st=' '+st;
		for (int i=1;i<=2*n-1;i++)
		  if (i&1) cout<<st[i];
		cout<<endl;
	}
}
/*
1110000
1110 1100 1000 0000
*/