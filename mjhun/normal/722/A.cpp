#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int f;
int h,m;

int main(){
	scanf("%d\n%d:%d",&f,&h,&m);
	if(m>=60)m-=60;
	if(f==12){
		if(h==0)h=1;
		else if(h>12){
			int d=h%10;
			if(d==0)h=10;
			else h=d;
		}
	}
	else {
		if(h>23){
			h=h%10;
		}
	}
	printf("%02d:%02d\n",h,m);
	return 0;
}