#include<bits/stdc++.h>
#define N 1009
using namespace std;

int tail,tp,d[N][2]; string s[N][2]; bool vis[N][2],bo[N][2];
struct node{ int x,y; }h[N],q[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool check(int x,int y,int z){
	int i;
	for (i=0; i<8; i++)
		if (((i>>y&1)==z)^(x>>i&1)) return 0;
	return 1;	
}
void opt(int x){
	for (int i=0; i<8; i++) cerr<<(x>>i&1);puts("");
}
bool cmp(node u,node v){
	return u.x<v.x||u.x==v.x&&u.y<v.y;
}
string t[3]={"z","y","x"};
int main(){
	int i,j,stp,k,p,x,y,tmp;
	for (i=0; i<3; i++)
		for (j=0; j<256; j++){
			if (check(j,i,0)){
			//	opt(j);
				h[++tail]=(node){j,1}; vis[j][1]=1;
				d[j][1]=2; s[j][1]="!"+t[i];
			//	for (int t=0; t<2;t++)putchar(s[j][1][t]);puts("");
			}
			if (check(j,i,1)){
			//	opt(j);
				h[++tail]=(node){j,1}; vis[j][1]=1;
				d[j][1]=1; s[j][1]=t[i];
			}
		}
	for (stp=3; tail<512; stp++){
	//	cerr<<stp<<' '<<tail<<endl;
		tp=0;
		memset(bo,1,sizeof(bo));
		for (i=1; i<=tail; i++){
			x=h[i].x; y=h[i].y;
		//	cerr<<stp<<' '<<x<<' '<<y<<' '<<d[x][y]+2<<endl;
			if (!vis[x][1] && d[x][y]+2==stp){
				//if (stp==5) cout<<("("+s[x][y]+")")<<endl;
				if (bo[x][1]){
					q[++tp]=(node){x,1};
					bo[x][1]=0; s[x][1]="("+s[x][y]+")";
				} else s[x][1]=min(s[x][1],"("+s[x][y]+")");
			//	if (stp==5) cout<<s[x][1]<<endl;
			}
			if (!vis[x^255][1] && d[x][y]+3==stp){
				if (bo[x^255][1]){
					q[++tp]=(node){x^255,1};
					bo[x^255][1]=0; s[x^255][1]="!("+s[x][y]+")";
				} else s[x^255][1]=min(s[x^255][1],"!("+s[x][y]+")");
			}
		}
		for (i=1; i<=tail; i++)
			for (j=1; j<=tail; j++)
				for (k=0; k<=h[i].y && k<=h[j].y; k++){
					tmp=d[h[i].x][h[i].y]+d[h[j].x][h[j].y]+1;
					p=(k==1?(h[i].x&h[j].x):(h[i].x|h[j].x));
					if (!vis[p][k] && tmp==stp){
						if (stp==7){
						//	opt(p);
						//	cout<<(s[h[i].x][h[i].y]+(k==1?"&":"|")+s[h[j].x][h[j].y])<<endl;
						}
						if (bo[p][k]){
							q[++tp]=(node){p,k}; bo[p][k]=0;
							s[p][k]=s[h[i].x][h[i].y]+(k==1?"&":"|")+s[h[j].x][h[j].y];	
						} else s[p][k]=min(s[p][k],s[h[i].x][h[i].y]+(k==1?"&":"|")+s[h[j].x][h[j].y]);
						//cout<<s[p][k]<<endl;
					}
				}
		for (; tp; tp--){
			vis[q[tp].x][q[tp].y]=1;
			d[q[tp].x][q[tp].y]=stp; h[++tail]=q[tp];
		}
	}
//	cout<<min("x","(");
	sort(h+1,h+tail+1,cmp);
//	for (i=1; i<=tail; i++) cerr<<h[i].x<<' '<<h[i].y<<endl;
	int cas; scanf("%d",&cas); char ch[10];
	while (cas--){
		scanf("%s",ch);
		tmp=0;
		for (i=0; i<8; i++) tmp|=(ch[i]-'0')<<i;
		p=(d[tmp][0]>d[tmp][1] || d[tmp][0]==d[tmp][1] && s[tmp][0]>s[tmp][1]);
		//cerr<<d[tmp][p]<<endl;
		for (i=0; i<d[tmp][p]; i++) putchar(s[tmp][p][i]); puts("");
	}
	return 0;
}