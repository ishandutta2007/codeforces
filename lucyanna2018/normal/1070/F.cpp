#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
int n, c11, s, bes;
vector<int> c10, c01, c00;
struct Node{
	int cnt, sum;
} a[5555 * 8];
void ins(int i,int s,int e,int x,int y){
	if(s == e){
		a[i].cnt += y;
		a[i].sum += x * y;
		return;
	}
	int  m=(s+e)/2;
	if(x <= m)ins(i*2,s,m,x,y);else
		ins(i*2+1,m+1,e,x,y);
	a[i].cnt = a[i*2].cnt + a[i*2+1].cnt;
	a[i].sum = a[i*2].sum + a[i*2+1].sum;
}
int query(int i,int s,int e,int c){
	if(s == e){
		return c * s;
	}
	int m = (s + e) / 2;
	if(a[i*2+1].cnt <= c)
		return a[i*2+1].sum + query(i*2, s, m, c - a[i*2+1].cnt);
	else
		return query(i*2+1, m+1, e, c);
}
int main(){
	char c[9];int x;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s%d",c,&x);
		int w = (c[0] - '0') * 2 + (c[1] - '0');
		if(w == 3){
			c11 ++;
			s += x;
		}else{
			if(w == 2)
				c10.push_back(x);
			else
			if(w == 1)
				c01.push_back(x);
			else
				c00.push_back(x);
			ins(1,1,5000,x,1);
		}
	}
	sort(c10.begin(), c10.end());
	sort(c01.begin(), c01.end());
	sort(c00.begin(), c00.end());
	int cur10 = 0, cur01 = 0;
	bes = 0;
	for(int M = c11; M <= n; M++){
		while(2 * (c11 + cur10) < M){
			if(c10.empty())goto Finish;
			cur10 ++;
			int x = c10.back();
			c10.pop_back();
			s += x;
			ins(1,1,5000,x,-1);
		}
		while(2 * (c11 + cur01) < M){
			if(c01.empty())goto Finish;
			cur01 ++;
			int x = c01.back();
			c01.pop_back();
			s += x;
			ins(1,1,5000,x,-1);
		}
		bes = max(bes, s + query(1,1,5000,M-cur01-cur10-c11));
	}
Finish:
	printf("%d\n",bes);
	return 0;
}