#include<bits/stdc++.h>
#define cin nmsl
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

using namespace std;
int T,n;
signed main()
{
	read(T);
	while (T--)
	{
		read(n);
		if (n%4!=0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
	}
	
}