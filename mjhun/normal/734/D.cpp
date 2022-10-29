#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define y0 Demetrio
using namespace std;
typedef long long ll;

int n,x0,y0;
char t[8];
int d[8];

int main(){
	scanf("%d%d%d",&n,&x0,&y0);
	memset(d,-1,sizeof(d));
	bool r=false;
	fore(i,0,n){
		char cc[4];
		int x,y;
		scanf("%s%d%d",cc,&x,&y);
		char c=cc[0];
		if(x==x0){
			if(y>y0){
				if(d[0]<0||y-y0<d[0]){
					d[0]=y-y0;
					t[0]=c;
				}
			}
			else {
				if(d[1]<0||y0-y<d[1]){
					d[1]=y0-y;
					t[1]=c;
				}
			}
		}
		if(y==y0){
			if(x>x0){
				if(d[2]<0||x-x0<d[2]){
					d[2]=x-x0;
					t[2]=c;
				}
			}
			else {
				if(d[3]<0||x0-x<d[3]){
					d[3]=x0-x;
					t[3]=c;
				}
			}
		}
		if(x+y==x0+y0){
			if(x>x0){
				if(d[4]<0||x-x0<d[4]){
					d[4]=x-x0;
					t[4]=c;
				}
			}
			else {
				if(d[5]<0||x0-x<d[5]){
					d[5]=x0-x;
					t[5]=c;
				}
			}
		}
		if(x-y==x0-y0){
			if(x>x0){
				if(d[6]<0||x-x0<d[6]){
					d[6]=x-x0;
					t[6]=c;
				}
			}
			else {
				if(d[7]<0||x0-x<d[7]){
					d[7]=x0-x;
					t[7]=c;
				}
			}
		}
		//if(t[0]=='B'||t[0]=='Q')r=r||x0+y0==x+y||x0-y0==x-y;
		//if(t[0]=='R'||t[0]=='Q')r=r||x0==x||y0==y;
	}
	t[8]=0;
	//fore(i,0,8)if(t[i])printf("demetrio %d %c\n",i,t[i]);
	//puts(t);
	r=t[0]&&t[0]!='B'||t[1]&&t[1]!='B'||t[2]&&t[2]!='B'||t[3]&&t[3]!='B';
	r=r||(t[4]&&t[4]!='R'||t[5]&&t[5]!='R'||t[6]&&t[6]!='R'||t[7]&&t[7]!='R');
	puts(r?"YES":"NO");
	return 0;
}