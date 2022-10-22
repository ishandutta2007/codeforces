#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int h,m;

int inv(int x){
	if(x==0||x==1||x==8)return x;
	if(x==3||x==4||x==6||x==7||x==9)return -1;
	if(x==2)return 5;
	return 2;
}

bool valid(int x,int y){
	vector<int> t(4);
	t[0] = x/10;
	t[1] = x%10;
	t[2] = y/10;
	t[3] = y%10;
	reverse(t.begin(),t.end());
	rep(i,4){
		if(inv(t[i])==-1)return false;
	}
	x = inv(t[0])*10 + inv(t[1]),y = inv(t[2])*10 + inv(t[3]);
	if(x>=0&&x<h&&y>=0&&y<m)return true;
	return false;
}

int main(){
	
	int T;
	cin>>T;
	
	rep(_,T){
		scanf("%d %d",&h,&m);
		int hh = h,mm = m;
		scanf("%d:%d",&hh,&mm);
		
		
		while(true){
			if(valid(hh,mm))break;
			mm++;
			if(mm==m){
				mm = 0;
				hh++;
			}
			if(hh==h)hh = 0;
		}
		printf("%02d:%02d\n",hh,mm);
		
	}
	
    return 0;
}