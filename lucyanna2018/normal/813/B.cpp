#include<iostream>
#include<algorithm>
using namespace std;
#define int64 long long int
int64 x,y,l,r;
int64 a[66],b[66],c[66*66];
int la,lb,lc;
void proc(int64 x,int64*a,int&len,int64 u){
	len = 0;
	a[len++] = 1;
	while(a[len-1] <= u/x){
		a[len] = a[len-1] * x;
		len++;
	}
}
int main(){
	cin >> x >> y >> l >> r;
	proc(x,a,la,r);
	proc(y,b,lb,r);
	for(int i=0; i<la; i++)for(int j=0; j<lb; j++){
		int64 w = a[i] + b[j];
		if(w >= l && w <= r)
			c[lc++] = w;
	}
	c[lc++] = l-1;
	c[lc++] = r+1;
	sort(c,c+lc);
	lc = unique(c,c+lc)-c;
	int64 res = 0;
	for(int i=1; i<lc; i++)
		res = max(res, c[i] - c[i-1] - 1);
	cout << res << endl;
	return 0;
}